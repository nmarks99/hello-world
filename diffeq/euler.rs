
fn euler_integrate(xspan:&[f32], step_size: f32) {
    let mut x: Vec<f32> = (xspan[0]..xspan[1]).step_by(step_size).collect();
    for i in x.iter() {
        println!("{:?}",i);
    }
}

fn main() {
    let mut c = euler_integrate([0,10],0.1);
}

// def eval_integral(func, xspan, step_size):
//     '''
//     Numerical integration with Euler’s method
//     Parameters:
//     ====================
//     func: Python function
//     func is the function you want to integrate for
//     xspan: list
//     xspan is a list of two elements, representing
//     the start and end of integration
//     step_size:
//     a smaller step_size will give a more accurate result
//     Returns:
//     ====================
//     int_val:
//     result of the integration
//     '''

//     x = np.arange(xspan[0], xspan[1], step_size)
//     int_val = 0
//     for xi in x:
//         int_val += func(xi) * step_size
//     return int_val

// def half_cos_sqr(x):
//     return 0.5*(math.cos(x))**2

// result = eval_integral(func=half_cos_sqr, xspan=[0, pi/2], step_size=0.0001)
// eqn = r'J(cos(x)) = {:.3f}'.format(result)
// display(Math(eqn))