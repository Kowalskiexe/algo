use regex::Regex;
use std::io::{self, BufRead};

fn get_nums(text: &str) -> Vec<i32> {
    let mut nums = Vec::<i32>::new();
    let num_re = Regex::new(r"-?\d+").expect("I f'up regex");
    for mat in num_re.find_iter(&text) {
        let num = mat.as_str().parse().expect("Couldn't parse the number");
        nums.push(num);
    }
    nums
}

fn get_diffs(v: &Vec<i32>) -> Vec<i32> {
    let mut diffs = Vec::<i32>::new();
    diffs.reserve(v.len() - 1);
    for items in v.windows(2) {
        diffs.push(items[1] - items[0]);
    }
    diffs
}

fn get_pyramid(nums: &Vec<i32>) -> Vec<Vec<i32>> {
    let mut pyramid = Vec::<Vec<i32>>::new();
    pyramid.reserve(nums.len());
    pyramid.push(nums.clone());
    let mut diffs = get_diffs(nums);
    loop {
        if diffs.len() == 0 {
            break;
        }
        pyramid.push(diffs.clone());
        diffs = get_diffs(&diffs);
    }
    pyramid
}

fn get_first_elms(pyramid: &Vec<Vec<i32>>) -> Vec<i32> {
    let mut last = Vec::<i32>::new();
    for row in pyramid {
        last.push(*row.first().unwrap());
    }
    last.reverse();
    last
}

fn get_extrapol(first_elms: &Vec<i32>) -> i32 {
    let mut ext = 0;
    for fe in first_elms {
        ext = fe - ext;
    }
    ext
}

fn main() {
    let reader = io::stdin().lock();
    let mut result = 0;
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        let nums = get_nums(&line);
        print!("nums: ");
        for n in &nums {
            print!("{n} ");
        }
        println!("");
        let pyramid = get_pyramid(&nums);
        println!("pyramid:");
        for row in &pyramid {
            for n in row {
                print!("{n} ");
            }
            println!("");
        }
        let first_elms = get_first_elms(&pyramid);
        let ext = get_extrapol(&first_elms);
        println!("{ext}");
        result += ext;
    }
    println!("{result}");
}
