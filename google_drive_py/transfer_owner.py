#!/usr/bin/env python3
import os
import argparse

from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build
from googleapiclient.errors import HttpError

# If modifying these scopes delete the file token.json.
SCOPES = [
    "https://www.googleapis.com/auth/drive",
]

def get_credentials():
    creds = None
    if os.path.exists("token.json"):
        creds = Credentials.from_authorized_user_file("token.json", SCOPES)

    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file(
                "credentials.json", SCOPES
            )
            creds = flow.run_local_server(port=0)

    with open("token.json", "w") as token:
        token.write(creds.to_json())

    return creds


def get_my_files(service, folder_id, email, my_files=None):
    '''Recursively gets IDs of all files owned by user in requested folder'''

    if my_files is None:
        my_files = dict()

    try:
        query = f"'{folder_id}' in parents"
        results = service.files().list(
            q=query, spaces='drive',
            fields="nextPageToken, files(id, name, mimeType, owners)"
        ).execute()
        items = results.get('files', [])
        
        if not items:
            return
    
        for item in items:
            if item["mimeType"] == "application/vnd.google-apps.shortcut":
                continue # can't transfer ownership of shortcuts
            #  owner_names = [owner['displayName'] for owner in item["owners"]]
            owner_emails = [owner['emailAddress'] for owner in item["owners"]]
            if email in owner_emails:
                my_files[item["name"]] = item["id"]

            if item["mimeType"] == 'application/vnd.google-apps.folder':
                print(f"Searching in folder {item['name']}...")
                sub_folder_id = item["id"]
                get_my_files(service, sub_folder_id, email, my_files)

    except HttpError as error:
        print(f"An error occured: {error}")
    
    return my_files

def get_user_email(creds):
    '''Get currently authenticated user's email address'''
    try:
        service = build("drive", "v3", credentials=creds)
        user_info = service.about().get(fields="user(emailAddress)").execute()
        return user_info['user']['emailAddress']
    except HttpError as error:
        print(f"An error occurred: {error}")
        return None


def main():
    parser = argparse.ArgumentParser(description="Recursively transfer ownership of all files in a Google Drive folder")
    parser.add_argument("new_owner", help="The new owner of the file (email address)")
    parser.add_argument("id", help="ID of the Google Drive file or folder")
    parser.add_argument("--dry-run", action="store_true", help="Perform a dry run (no changes will be made)")
    args = parser.parse_args()
    
    creds = get_credentials()

    folder_id = args.id
    new_owner_email = args.new_owner
    email = get_user_email(creds)
    
    # Get all the file IDs from the requested folder ID
    try:
        service = build("drive", "v3", credentials=creds)
        my_files = get_my_files(service, folder_id, email)
    except HttpError as error:
        print(f"An error occurred: {error}")
    
    if not my_files:
        print(f"No files owned by {email} were found") 
    
    count = 0
    for file_name,file_id in my_files.items():
        if not args.dry_run:
            print(f"Transfering {file_name} to {new_owner_email}")
            try:
                new_permission = {
                    'type': 'user',
                    'role': 'owner',
                    'emailAddress': new_owner_email
                }
                _permission = service.permissions().create(
                    fileId=file_id,
                    body=new_permission,
                    transferOwnership=True
                ).execute()
            except:
                print(f"Caught error {error} while processing file {file_name}...skipping")
        else:
            print(f"[Dry-run] file {file_name} would be transferred to {new_owner_email}")
        count += 1
    else:
        print(f"\nSuccessfully transferred ownership of {count} files")

if __name__ == "__main__":
    main()
