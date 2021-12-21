use std::process::{Command};

pub fn sys_cmd_output(command:String) -> std::string::String {

    let prog:&str;
    let prog_flag:&str;
    
    if cfg!(target_os = "windows"){
        prog = "cmd";
        prog_flag = "/C";
    } else {
        prog = "sh";
        prog_flag = "-c";
    }

    let output = Command::new(prog)
                .arg(prog_flag)
                .arg(command)
                .output()
                .expect("Shell command failed to execute");

    let output = String::from_utf8(output.stdout).unwrap();
    return output;
}

pub fn sys_cmd(command:&str) {

    let prog:&str;
    let prog_flag:&str;
    
    if cfg!(target_os = "windows"){
        prog = "cmd";
        prog_flag = "/C";
    } else {
        prog = "sh";
        prog_flag = "-c";
    }

    Command::new(prog)
                .arg(prog_flag)
                .arg(&command)
                .output()
                .expect("Shell command failed to execute");

}


