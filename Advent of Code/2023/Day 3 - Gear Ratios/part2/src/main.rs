use std::io::{self, BufRead};
use std::collections::{HashSet, HashMap};

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

    let mut y = 0;
    let mut mask = Vec::<Vec<i32>>::new();
    let mut mask_values = HashMap::<i32, i32>::new();
    let mut reading_num = false;
    let mut num_count = 0;
    let mut curr_num = String::new();
    for line in &engine {
        mask.push(Vec::new());
        let mut x = 0;
        let mut first_x = -1;
        let mut last_x;
        for ch in line.chars() {
            if ch.is_ascii_digit() {
                if !reading_num {
                    num_count += 1;
                    first_x = x;
                }
                reading_num = true;
                curr_num.push(ch);
                mask[y].push(num_count);
            } else {
                if reading_num {
                    last_x = x - 1;
                    println!("found: {curr_num}, its id={num_count} ({y}, ({first_x}, {last_x}))");
                    mask_values.insert(num_count, curr_num.parse().expect("It should be number"));
                    curr_num.clear();
                }
                reading_num = false;
                mask[y].push(0);
            }
            x += 1;
        }
        y += 1;
    }

    for row in &mask {
        for num in row {
            print!("{num} ");
        }
        println!("");
    }

    let mut result = 0;
    y = 0;
    for line in &engine {
        let mut x = 0;
        for ch in line.chars() {
            if ch == '*' {
                let mut neighbors = HashSet::new();
                // upper row
                for i in (x-1)..=(x+1) {
                    if mask[y - 1][i] > 0 {
                        neighbors.insert(mask[y - 1][i]);
                    }
                }
                // left
                if mask[y][x - 1] > 0 {
                    neighbors.insert(mask[y][x - 1]);
                }
                // right
                if mask[y][x + 1] > 0 {
                    neighbors.insert(mask[y][x + 1]);
                }
                // lower row
                for i in (x-1)..=(x+1) {
                    if mask[y + 1][i] > 0 {
                        neighbors.insert(mask[y + 1][i]);
                    }
                }
                println!("* at {y} {x} neighbors with: ");
                for n in &neighbors {
                    println!("{n}: {}", mask_values.get(n).unwrap());
                }
                if neighbors.len() == 2 {
                    let mut gear_ratio = 1;
                    for n in &neighbors {
                        gear_ratio *= mask_values.get(n).unwrap();
                    }
                    println!("It's a gear! {gear_ratio}");
                    result += gear_ratio;

                }
            }
            x += 1;
        }
        y += 1;
    }
    println!("{result}");
}
