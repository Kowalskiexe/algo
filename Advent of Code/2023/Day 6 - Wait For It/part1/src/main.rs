use std::io;
use regex::Regex;
use std::iter::zip;

fn get_nums(text: &str) -> Vec<i32> {
    let num_re = Regex::new(r"\d+").expect("I f'up regex");
    let mut nums = Vec::<i32>::new();
    for mat in num_re.find_iter(text) {
        let num = mat.as_str()
            .parse()
            .expect("It should be a number.");
        nums.push(num);
    }
    nums
}

fn down(a: f32) -> f32 {
    if a == a as i32 as f32 {
        a - 1.
    } else {
        f32::floor(a)
    }
}

fn up(a: f32) -> f32 {
    if a == a as i32 as f32 {
        a + 1.
    } else {
        f32::ceil(a)
    }
}

fn main() {
    let mut times_line = String::new();
    let mut dist_line = String::new();
    io::stdin().read_line(&mut times_line).expect("couldn't read the first line");
    io::stdin().read_line(&mut dist_line).expect("couldn't read the second line");
    let times = get_nums(&times_line);
    let dists = get_nums(&dist_line);
    let mut result = 1;
    for (t, d) in zip(times, dists) {
        let t = t as f32;
        let d = d as f32;
        let delta_root = f32::sqrt(t*t - 4.*d);
        let a = up((t - delta_root) / 2.);
        let b = down((t + delta_root) / 2.);
        let k = (b - a + 1.) as i32;
        println!("{a} {b} {k}");
        result *= k;
    }
    println!("{result}");
}
