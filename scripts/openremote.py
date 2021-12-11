#!/usr/bin/env python
import os
import subprocess


def isRepo():
    '''
    Check if the current directory is a git repo. If it is return true, otherwise false
    '''

    c = 'git rev-parse --is-inside-work-tree'
    try:
        subprocess.check_output(c, shell=True).decode("utf8")
        return True
    except:
        return False

def isGitHubDir():
    '''
    Check if the current directory is called GitHub. Assume that 
    this is the directory where all your repos are stored. Return 
    true or false accordingly. 
    '''

    cwd_name = os.path.basename(os.getcwd())
    if cwd_name == "GitHub":
       return True
    else:
        return False

# -------------------------------------

if isGitHubDir() is True:
    '''
    If the current directory is called GitHub, just open github.com
    '''
    url = "https://github.com/"
    cmd = "explorer " + url
    os.system(cmd)
    exit()
     

elif isRepo() is True:
    '''
    Open the repository's page. Get the url with the git config command below.
    '''
    cmd1 = "git config --get remote.origin.url"
    result = subprocess.check_output(cmd1, shell=True)
    result = result.decode('utf8').replace(".git","")

    cmd2 = "explorer " + result
    os.system(cmd2)

