# openremote
Opens the GitHub repository page for the repository corresponding to the directory you run the program in. If the directory is called GitHub, it opens GitHub.com


## Installation
First you must install rust from from [https://www.rust-lang.org/tools/install](https://www.rust-lang.org/tools/install). Then in a terminal navigate to the root directory of the project and run the following:
```
cargo build --release
```
Then find the built executable in target/release and move it to somewhere that is on your system path. In Linux I put it in ~/bin. On windows you also could put it there but maybe need to at that directory to your path.


## Useage Example
Assume you have already clone a GitHub repository on your computer called *hello-world*
```
cd ~/Documents/GitHub/hello-world # Navigate to the repo in your local file system
 

openremote # run the program

```
In the above example, the program will open the *hello-world* repository page in on GitHub.com in your default web browser. 
