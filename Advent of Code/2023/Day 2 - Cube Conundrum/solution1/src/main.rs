use std::{io::{self, BufRead}, str::FromStr};
use regex::Regex;

fn get_cubes_max(line: &str, color: &str) -> i32 {
    let re = String::from_str("(\\d+) ").unwrap() + color;
    let re = Regex::new(&re).unwrap();
    let mut out: i32 = 0;
    for cap in re.captures_iter(&line) {
        let num: i32 = cap.get(1).unwrap()
            .as_str()
            .parse()
            .unwrap();
        out = i32::max(out, num);
    }
    out
}

fn main() {
    let stdin = io::stdin();
    let reader = stdin.lock();
    
    let mut result = 0;
    for line_result in reader.lines() {
        let line = line_result.expect("Could't read line");
        let game_id_re = Regex::new(r"^Game (\d+):").expect("I f'up a regex");
        let id: i32 = game_id_re.captures(&line)
            .unwrap()
            .get(1)
            .unwrap()
            .as_str()
            .parse()
            .expect("It should be a number");

        let red_max = get_cubes_max(&line, "red");
        let blue_max = get_cubes_max(&line, "blue");
        let green_max = get_cubes_max(&line, "green");

        println!("{line}");
        println!("{id}: {red_max} red {green_max} green {blue_max} blue");
        if red_max > 12 || green_max > 13 || blue_max > 14 {
            println!("impossible");
        } else {
            result += id;
        }
    }
    println!("{result}");
}
