use std::process::{Command};

pub fn sys_command(command:String) -> String {

    // See if on windows 
    let windows = cfg!(target_os = "windows");
    let prog:&str;
    let prog_flag:&str;

    if windows == true {
        prog = "cmd";
        prog_flag = "/C";
    }
    else{
        // Presumably the other option is a UNIX machine with "sh"
        // I think this is a reasonable assumption
        prog = "sh";
        prog_flag = "-c";
    }

    let output = Command::new(prog)
                .arg(prog_flag) // this is important but idk why
                .arg(command)
                .output()
                .expect("Command failed to execute");

    let output = String::from_utf8(output.stdout).unwrap();
    return output;
}
