// TODO: Add more command line options as I think of them
use std::env;

fn main() {

    // Define URL to NUSTARS Google Drive
    let drive_url: String = String::from("https://drive.google.com/drive/u/0/folders/0B5v80C8y8Ch1bXU3OXFVblMxbms");


    // Define string to store command line arguments
    let args: Vec<String> = env::args().collect();


    // let filename = &args[0];
    let nargs:usize = args.len();

    if nargs == 2 {

        let query = &args[1];

        // Open the NUSTARS Google Drive link in Firefox
        if query.eq("-drive") || query.eq("-Drive") {
            open::with(drive_url, "firefox").expect("Couldn't open Google Drive link");
        }
        else{
            println!("Argument {} not understood",query);
        }

    }    
    else{
        println!("Expected 1 argument but {} were given",nargs-1);
    }
    
 

}
