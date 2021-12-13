mod helpers;

fn main() {


    if helpers::is_repo() { // check that cwd is a repo
        
        // cmd output is a std::process::Output struct
        let cmd_output: std::process::Output;
        let get_repo_url_cmd = String::from("git config --get remote.origin.url");
        
        // Run the command
        cmd_output = helpers::sys_command(get_repo_url_cmd);

        // Make a string from the output and remove the .git at the end
        let cmd_output = String::from_utf8(cmd_output.stdout).unwrap();
        let repo_link:&str = &cmd_output[0..cmd_output.len()-5];
        
        // Open url in browser
        open::that(repo_link).expect("Couldn't open the repo in browser"); 
    
    }

    else{ // otherwise tell user they aren't in a repo
        println!("Current directory is not a git repository");
    }

    
}

