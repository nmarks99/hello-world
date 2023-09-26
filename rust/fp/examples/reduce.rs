fn main() {
    // Note that sum method does the same thing as this example
    // let v: Vec<i64> = (1..5).collect();
    // println!("Summing up the elements in {:?} using the reduce method", v);
    // let sum = v.clone().into_iter().reduce(|a, b| a + b).unwrap();
    // println!("Sum = {}", sum);
    
    let v: Vec<i64> = (1..5).collect();
    // This is essentiall what reduce does under the hood:

    // This is a closure we could pass to reduce
    let inner_closure = |a:i64, b:i64| -> i64 {a + b};
    
    // reduce uses the first element of the iterator as the initial value
    let mut sum: i64  = v[0];
    
    // reduce passes the accumulator (running value which is "sum" in this example)
    // to the inner closure, along with the i'th element of the iterator, starting at index 1
    // since we use the element at index 0 as an initial value
    for i in 1..v.len() {
        sum = inner_closure(sum, v[i]);
    }

    println!("Sum = {}", sum);

}
