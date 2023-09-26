fn main() {
    let v_str = vec!["1.57", "hi", "2.37", "bye", "3.14", "1"];
    let v_int: Vec<f64>  = v_str.iter().filter_map(|s| s.parse().ok()).collect();
    println!("{:?}", v_int);
}
