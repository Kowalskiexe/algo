use regex::Regex;
use std::collections::HashMap;
use std::io::{self, BufRead};

fn main() {
    let reader = io::stdin().lock();
    let mut directions = String::new();
    let mut portals = HashMap::<String, (String, String)>::new();
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        
        let directions_re = Regex::new(r"^(L|R)+$").expect("I f'up regex");
        match directions_re.find(&line) {
            Some(mat) => {
                directions = mat.as_str().to_string();
            },
            None => (),
        }

        let portal_re = Regex::new(
            r"^(?<start>[A-Z]{3}) = \((?<left>[A-Z]{3}), (?<right>[A-Z]{3})\)$")
            .expect("I f'up regex");
        match portal_re.captures(&line) {
            Some(caps) => {
                let start = caps["start"].to_string();
                let left = caps["left"].to_string();
                let right = caps["right"].to_string();
                portals.insert(start, (left, right));
            },
            None => (),
        }
    }

    let mut curr = "AAA".to_string();
    println!("{curr}");
    let mut steps = 0;
    while curr != "ZZZ" {
        for ch in directions.chars() {
            if ch == 'L' {
                curr = portals[&curr].0.clone();
            }
            if ch == 'R' {
                curr = portals[&curr].1.clone();
            }
            println!("{curr}");
            steps += 1;
        }
    }
    println!("{steps}");
}
