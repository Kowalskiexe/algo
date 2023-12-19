use num::integer::Integer;
use regex::Regex;
use std::fmt::Debug;
use std::io::{self, BufRead};
use std::str::FromStr;

fn get_nums<T>(text: &str) -> Vec<T>
where
    T: Integer + FromStr,
    <T as FromStr>::Err: Debug,
{
    let nums_re = Regex::new(r"\d+").expect("I f'up regex");
    let mut nums = Vec::<T>::new();
    for mat in nums_re.find_iter(&text) {
        let num = mat.as_str().parse().expect("Couldn't parse regex match");
        nums.push(num);
    }
    nums
}

fn get_second_format(first_format: &str) -> Vec<usize> {
    let mut strike = 0;
    let mut series = Vec::<usize>::new();
    for ch in first_format.chars() {
        if ch == '#' {
            strike += 1;
        } else {
            if strike > 0 {
                series.push(strike);
            }
            strike = 0;
        }
    }
    if strike > 0 {
        series.push(strike);
    }
    series
}

fn get_solutions(pattern: &str, second_format: Vec<usize>) -> Vec<String> {
    let mut candidates = Vec::<String>::new();
    gen_candidates(pattern, String::new(), &mut candidates);
    let mut correct = Vec::<String>::new();
    for c in &candidates {
        let c_sf = get_second_format(c);
        if c_sf == second_format {
            // println!("{c}");
            correct.push(c.clone());
        }
    }
    correct
}

fn gen_candidates(pattern: &str, curr: String, output: &mut Vec<String>) {
    if curr.len() == pattern.len() {
        output.push(curr);
        return;
    }
    let pattern_ch = pattern.chars().nth(curr.len()).unwrap();
    if pattern_ch == '?' {
        gen_candidates(pattern, curr.clone() + ".", output);
        gen_candidates(pattern, curr.clone() + "#", output)
    } else {
        gen_candidates(pattern, curr.clone() + &pattern_ch.to_string(), output);
    }
}

fn main() {
    let reader = io::stdin().lock();
    let mut result = 0;
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        let pattern_re = Regex::new(r"^(\.|#|\?)+").expect("I f'up regex");
        let pattern = pattern_re
            .find(&line)
            .expect("Didn't find the patter")
            .as_str();
        let second_format = get_nums(&line);
        println!("{pattern} {:?}", second_format);
        let solutions = get_solutions(pattern, second_format);
        println!("{}", solutions.len());
        result += solutions.len();
    }
    println!("{result}");
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_get_second_format() {
        let output = get_second_format("##..#.###");
        assert_eq!(output, vec![2, 1, 3]);
    }

    #[test]
    fn test_gen_candidates() {
        let mut candidates = Vec::<String>::new();
        gen_candidates("??.", String::new(), &mut candidates);
        assert_eq!(candidates, vec!["...", ".#.", "#..", "##."]);
    }
}
