use std::io::{self, BufRead};

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let reader = stdin.lock();

    let mut sum: u32 = 0;
    for line_result in reader.lines() {
        let mut first: char = 'x';
        let mut last: char = 'x';
        let line = line_result?;
        for c in line.chars() {
            if c.is_digit(10) {
                if first == 'x' {
                    first = c;
                }
                last = c;
            }
        }
        println!("first {} last {}", first, last);
        let first_digit = first.to_digit(10);
        let second_digit = last.to_digit(10);
        let mut num: u32 = 0;
        match first_digit {
            Some(value) => {
                num += value * 10;
            }
            None => {
                println!("oopsie");
            }
        }
        match second_digit {
            Some(value) => {
                num += value;
            }
            None => {
                println!("oopsie");
            }
        }
        sum += num;
    }
    println!("{}", sum);

    Ok(())
}

