use std::io::{self, BufRead};
use regex::Regex;

fn extract_nums(text: &str) -> Vec<i64> {
    let num_pat = Regex::new(r"\d+").expect("I f'up regex");
    let mut nums = Vec::new();
    for mat in num_pat.find_iter(&text) {
        let mat = String::from(mat.as_str().trim());
        println!("{}", mat);
        let mat: i64 = mat.parse().expect("It should be a number.");
        nums.push(mat);
    }
    nums
}

struct Map {
    dst_start: i64,
    src_start: i64,
    len: i64,
}

impl Map {
    fn is_in(&self, num: i64) -> bool {
        self.src_start <= num && num < self.src_start + self.len
    }
    fn trans(&self, num: i64) -> Option<i64> {
        if self.is_in(num) {
            let dist_to_src = num - self.src_start;
            Some(self.dst_start + dist_to_src)
        } else {
            None
        }
    }
}

fn main() {
    let reader = io::stdin().lock();

    let mut seeds = Vec::<i64>::new();
    let mut maps = Vec::<Vec<Map>>::new();
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        let seeds_header = Regex::new(r"seeds:").expect("I f'up regex");
        if seeds_header.is_match(&line) {
            seeds = extract_nums(&line);
        }

        let map_header = Regex::new(r".* map:").expect("I f'up regex");
        if map_header.is_match(&line) {
            // add new layer
            maps.push(Vec::<Map>::new());
        }

        let map_line = Regex::new(r"^\d+ \d+ \d+").unwrap();
        if map_line.is_match(&line) {
            let nums = extract_nums(&line);
            let m = Map {
                dst_start: nums[0],
                src_start: nums[1],
                len: nums[2],
            };
            maps.last_mut().unwrap().push(m);
        }
    }

    let mut result = i64::MAX;
    for seed in &seeds {
        let mut c = *seed;
        println!("from {c} ");
        for (i, layer) in maps.iter().enumerate() {
            for map in layer {
                match map.trans(c) {
                    Some(val) => {
                        println!("{c} -> {val}, {}", i + 1);
                        c = val;
                        break;
                    },
                    None => (),
                }
            }
        }
        println!("to {c}");
        result = i64::min(result, c);
    }
    println!("{result}");
}
