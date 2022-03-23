use std::fs::File;
use std::io::Read;
use std::path::Path;
use std::env;


fn main() {

    // Get path to file from user cmd line argument
    let args: Vec<String> = env::args().collect();
    let path = Path::new(&args[1]);
    let display = path.display();
    

    // Open the file in read-only mode. Returns 'io::Result<File>'
    let mut file = match File::open(&path) {
        Err(why) => panic!("Couldnt read {}: {}", display, why),
        Ok(file) => file,
    };

    // Read the file contents into a string, returns 'io::Result<usize>'
    let mut s = String::new();
    match file.read_to_string(&mut s) {
        Err(why) => panic!("Couldn't read {}: {}", display, why),
        Ok(_) => print!("{} contains: \n{}", display, s),
    };


}
