use std::io::{self, BufRead};
use std::collections::HashSet;

fn main() {
    let reader = io::stdin().lock();

    let mut result = 0;
    for line_result in reader.lines() {
        let line = line_result.unwrap();

        let mut winning_nums = HashSet::<i32>::new();
        let mut chosen_nums = HashSet::<i32>::new();
        let mut curr_num = String::new();
        #[derive(PartialEq)]
        enum Reading {
            Id,
            Winning,
            Chosen,
        }
        let mut reading = Reading::Id;
        for ch in line.chars() {
            match ch {
                ':' => reading = Reading::Winning,
                '|' => reading = Reading::Chosen,
                '0'..='9' => {
                    if reading != Reading::Id {
                        curr_num.push(ch)
                    }
                },
                _ => {
                    if reading == Reading::Id {
                        continue;
                    }
                    // flush currently read number on whitespace
                    if curr_num.len() == 0 {
                        continue;
                    }
                    let num = curr_num.parse().expect("It should be a number");
                    if reading == Reading::Winning {
                        winning_nums.insert(num);
                    }
                    if reading == Reading::Chosen {
                        chosen_nums.insert(num);
                    }
                    curr_num.clear();
                },
            };
        }
        // one last flush
        let num = curr_num.parse().expect("It should be a number");
        chosen_nums.insert(num);

        print!("Winning numbers: ");
        for w in &winning_nums {
            print!("{w} ");
        }
        println!("");
        print!("Chosen numbers: ");
        for c in &chosen_nums {
            print!("{c} ");
        }
        println!("");
        let mut guessed = 0;
        for c in &chosen_nums {
            if winning_nums.contains(c) {
                guessed += 1;
            }
        }
        println!("guessed {guessed}");
        if guessed > 0 {
            let value = i32::pow(2, guessed - 1);
            println!("{value}");
            result += value;
        }
    }
    println!("{result}");
}
