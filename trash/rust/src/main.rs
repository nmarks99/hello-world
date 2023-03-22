use std::fs;
use filetime::FileTime;
use std::env;



fn get_file_name() -> {
    
    let args: Vec<String> = env::args().collect();





}





fn main() {
    let metadata = fs::metadata("foo.txt").unwrap();

    let mtime = FileTime::from_last_modification_time(&metadata);
    println!("{}", mtime);

    let atime = FileTime::from_last_access_time(&metadata);
    // assert!(mtime < atime);
//
    // Inspect values that can be interpreted across platforms
    println!("{}", mtime.unix_seconds());
    println!("{}", mtime.nanoseconds());

    // Print the platform-specific value of seconds
    println!("{}", mtime.seconds());

}



//
// use std::fs::File;
// use std::io::Read;
// use std::path::Path;
// use std::env;
//
//
// fn main() {
//
    // // Get path to file from user cmd line argument
    // let args: Vec<String> = env::args().collect();
    // let path = Path::new(&args[1]);
    // let display = path.display();
    //
//
    // // Open the file in read-only mode. Returns 'io::Result<File>'
    // let mut file = match File::open(&path) {
        // Err(why) => panic!("Couldnt read {}: {}", display, why),
        // Ok(file) => file,
    // };
//
    // // Read the file contents into a string, returns 'io::Result<usize>'
    // let mut s = String::new();
    // match file.read_to_string(&mut s) {
        // Err(why) => panic!("Couldn't read {}: {}", display, why),
        // Ok(_) => print!("{} contains: \n{}", display, s),
    // };
//
//
// }
