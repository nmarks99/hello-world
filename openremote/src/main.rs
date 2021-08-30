use open
fn main() {
    let path = "http://rust-lang.org";
    open::that(path).unwrap();
}
