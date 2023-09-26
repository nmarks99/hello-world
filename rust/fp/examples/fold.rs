fn main() {
    let v: Vec<i64> =  (1..5).collect();
    println!("Sum the elements in {:?} using the fold method", v);
    let sum: i64 = v.clone().into_iter().fold(0, |a, b| a+b);
    println!("Result = {}", sum);

    // implenting fold 'manually'
    // let v: Vec<i64> = (1..5).collect();
    //
    // // This is a closure we could pass to reduce
    // let inner_closure = |a:i64, b:i64| -> i64 {a + b};
    // 
    // // fold takes an initial value, unlike reduce
    // let initial_value: i64 = 0;
    //
    // // reduce uses the first element of the iterator as the initial value
    // let mut sum: i64  = initial_value;
    // 
    // // reduce passes the accumulator (running value which is "sum" in this example)
    // // to the inner closure, along with the i'th element of the iterator
    // // unlike reduce, the initial value is used, so we iterate from index 0 to the end
    // for i in 0..v.len() {
    //     sum = inner_closure(sum, v[i]);
    // }
    //
    // println!("Sum = {}", sum);

}
