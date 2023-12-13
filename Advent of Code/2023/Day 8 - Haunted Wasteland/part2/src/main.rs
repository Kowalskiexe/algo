use num::integer::Integer;
use regex::Regex;
use std::collections::HashMap;
use std::io::{self, BufRead};

fn get_map(portals: &HashMap<String, (String, String)>, path: &str) -> HashMap<String, String> {
    let nodes = portals.clone().into_keys();
    let mut map = HashMap::<String, String>::new();
    for mut curr in nodes {
        let start = curr.clone();
        for ch in path.chars() {
            if ch == 'L' {
                curr = portals[&curr].0.clone();
            }
            if ch == 'R' {
                curr = portals[&curr].1.clone();
            }
        }
        map.insert(start, curr.clone());
    }
    map
}

fn vlcm<T>(nums: Vec::<T>) -> T where T: Integer + Clone {
    if nums.len() == 0 {
        return T::zero();
    }
    if nums.len() == 1 {
        return nums[0].clone();
    }
    T::lcm(&nums[0], &vlcm(nums[1..].to_vec()))
}

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
            r"^(?<start>[0-9A-Z]{3}) = \((?<left>[0-9A-Z]{3}), (?<right>[0-9A-Z]{3})\)$")
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

    let map = get_map(&portals, &directions);
    
    let mut start_nodes: Vec<String> = portals.clone().into_keys().collect();
    start_nodes.retain(
        |v| {
            v.chars().nth(2).unwrap() == 'A'
        }
    );

    let mut dists = Vec::new();
    for n in &start_nodes {
        let mut curr_node = n.clone();
        let mut steps = 0;
        while curr_node.chars().nth(2).unwrap() != 'Z' {
            curr_node = map[&curr_node].clone();
            steps += directions.len();
        }
        dists.push(steps);
    } 
    let result = vlcm(dists);
    println!("{result}");
}
