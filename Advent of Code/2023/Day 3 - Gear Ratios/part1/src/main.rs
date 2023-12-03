use std::io::{self, BufRead};
use regex::Regex;

fn is_part(ch: char) -> bool {
    !ch.is_ascii_digit() && (ch != '.')
}

fn main() {
    let stdin = io::stdin();
    let reader = stdin.lock();

    let mut engine = Vec::<String>::new();
    for line in reader.lines() {
        let line = String::from(".") + &(line.unwrap()) + ".";
        engine.push(line);
    }
    let x = engine[0].len();
    let mut bot_guard = String::new();
    let mut top_guard = String::new();
    for _ in 0..x {
        bot_guard += ".";
        top_guard += ".";
    }
    engine.splice(0..0, vec!(bot_guard).iter().cloned());
    engine.push(top_guard);

    for line in &engine {
        println!("{}", &line);
    }

    let mut result = 0;
    let mut y = 0;
    for line in &engine {
        let num_re = Regex::new(r"\d+").expect("I f'd up a regex");
        for mat in num_re.find_iter(&line) {
            let start = mat.start() - 1;
            let end = mat.end();
            let mut succ = false;
            for ch in engine[y - 1][start..=end].chars() {
                if is_part(ch) {
                    succ = true;
                    break;
                }
            }
            if is_part(engine[y].chars().nth(start).unwrap()) {
                succ = true;
            }
            if is_part(engine[y].chars().nth(end).unwrap()) {
                succ = true;
            }
            if !succ {
                for ch in engine[y + 1][start..=end].chars() {
                    if is_part(ch) {
                        succ = true;
                        break;
                    }
                }
            }
            let mat = mat.as_str()
                .parse::<i32>()
                .expect("It should be a number");
            println!("{mat} is {succ}"); 
            if succ {
                result += mat;
            }
        }
        y += 1;
    }
    println!("{result}");
}
