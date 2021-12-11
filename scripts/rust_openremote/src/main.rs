// use open;
use std::process::{Command};

fn main() {

    
    // If on windows, run the command with cmd 
    let output = if cfg!(target_os = "windows") {
        Command::new("cmd")
                .args(["/C", "git config --get remote.origin.url"])
                .output()
                .expect("Command 'git config --get remote.origin.url' failed to execute")
    }

    // run throught sh if Mac or Linux
    else{
        Command::new("sh")
                .arg("-c")
                .arg("git config --get remote.origin.url")
                .output()
                .expect("Command 'git config --get remote.origin.url' failed to execute")
    };


    let github_repo_path = String::from_utf8(output.stdout).unwrap();
    open::that(github_repo_path).expect("Couldn't open the repo in browser");

}
