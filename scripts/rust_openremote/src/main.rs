mod helpers;

fn main() {

    let cmd_output:String;
    let get_repo_url_cmd = "git config --get remote.origin.url".to_string();

    // Run the command
    cmd_output = helpers::sys_command(get_repo_url_cmd);
    let repo_link:&str = &cmd_output[0..cmd_output.len()-5]; // remove the .git at the end
    
    // Open url in browser
    open::that(repo_link).expect("Couldn't open the repo in browser"); 

}

// fn isRepo(){
//     let check_if_repo_cmd = "git rev-parse --is-inside-work-tree";
//     Command::new("cmd")
// }
