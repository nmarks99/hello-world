fn main() {

    // demonstrating map
    let v: Vec<i64> = (1..10).collect();
    println!("Square each number in {:?} using map method", v);
    let squared: Vec<i64> = v.into_iter().map(|x| x * x).collect();
    println!("Result = {:?}", squared);

    // Implementing map 'manually':
    // let v: Vec<i64> = (1..10).collect();
    //
    // // closure that can be passed to the map function
    // let inner_closure = |x: i64| -> i64 {
    //     x * x
    // };
    // 
    // let mut new_vec: Vec<i64> = vec![];
    // for elem in v.clone() {
    //     new_vec.push(inner_closure(elem));
    // }
    // println!("Result = {:?}", new_vec);

}
