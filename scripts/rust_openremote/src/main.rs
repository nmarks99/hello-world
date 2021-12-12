use std::process::{Command};

fn main() {

    // Define a String to store cmd output 
    let cmd_output: String;

    // Check the operating system
    let windows = cfg!(target_os = "windows");


    if windows {
        cmd_output = v_windows();
    }
    else {
        cmd_output = v_unix();
    }

    let repo_link:&str = &cmd_output[0..cmd_output.len()-5]; // remove the .git at the end
    open::that(repo_link).expect("Couldn't open the repo in browser");

}

// fn isRepo(){
//     let check_if_repo_cmd = "git rev-parse --is-inside-work-tree";
//     Command::new("cmd")
// }

fn v_windows() -> String {
    let output = Command::new("cmd")
                .arg("/C") // this is important but idk why
                .arg("git config --get remote.origin.url")
                .output()
                .expect("Command 'git config --get remote.origin.url' failed to execute");

    let output = String::from_utf8(output.stdout).unwrap();
    return output;
}

fn v_unix() -> String {
    let output = Command::new("sh")
                .arg("-c") // this is important but idk why
                .arg("git config --get remote.origin.url")
                .output()
                .expect("Command 'git config --get remote.origin.url' failed to execute");

    let output = String::from_utf8(output.stdout).to_owned().unwrap();
    return output
}