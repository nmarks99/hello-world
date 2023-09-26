fn main() {
    // let v: Vec<i64> = (1..10).collect();
    // println!("Get only the even numbers in {:?} using filter method", v);
    // let evens: Vec<i64> = v.clone().into_iter().filter(|x| x % 2 == 0).collect();
    // println!("Result = {:?}", evens);

    // implenting fold 'manually'
    let v: Vec<i64> = (1..10).collect();
    
    let mut new_vec: Vec<i64> = vec![];
    
    // closure that can be passed to the filter function
    let inner_closure = |x: i64| -> bool { 
        x % 2 == 0
    };
    
    for i in v.iter() {
        if inner_closure(*i) {
            new_vec.push(*i);
        }
    }
    println!("Result = {:?}", new_vec);

}
