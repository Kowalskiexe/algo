use std::io::{self, BufRead};
use regex::Regex;

fn to_digit(s: &str) -> u32 {
    match s {
        "one" => 1,
        "two" => 2,
        "three" => 3,
        "four" => 4,
        "five" => 5,
        "six" => 6,
        "seven" => 7,
        "eight" => 8,
        "nine" => 9,
        _ => {
            let ch = s.chars().next().unwrap(); 
            ch.to_digit(10).unwrap()
        }
    }
}

fn main() {
    let stdin = io::stdin();
    let reader = stdin.lock();

    let mut sum: u32 = 0;
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        let re = Regex::new(r"(\d|one|two|three|four|five|six|seven|eight|nine)").unwrap();
        let digits: Vec<&str> = re.find_iter(&line).map(|m| m.as_str()).collect();
        let f: &str = digits[0];
        let l: &str = digits[digits.len() - 1];
        let fv: u32 = to_digit(f);
        let lv: u32 = to_digit(l);
        sum += fv * 10 + lv;
    }
    println!("{}", sum);
}

