use regex::Regex;
use std::cmp::Ordering;
use std::collections::HashMap;
use std::io::{self, BufRead};
use std::iter::zip;


#[derive(Debug, PartialEq, Eq, PartialOrd, Ord)]
enum HandRanking {
    FiveOfAKind = 6,
    FourOfAKind = 5,
    FullHouse = 4,
    ThreeOfAKind = 3,
    TwoPair = 2,
    OnePair = 1,
    HighCard = 0,
}

fn get_rank(hand: &str) -> HandRanking {
    let mut map = HashMap::<char, i64>::new();
    let mut counts = Vec::new();
    for ch in hand.chars() {
        let v: i64 = *map.get(&ch).unwrap_or(&0);
        map.insert(ch, v + 1);
    }
    for (_, v) in &map {
        counts.push(*v);
    }
    match counts.len() {
        1 => HandRanking::FiveOfAKind,
        2 => {
            if counts.contains(&1) {
                HandRanking::FourOfAKind
            } else {
                HandRanking::FullHouse
            }
        },
        3 => {
            if counts.contains(&3) {
                HandRanking::ThreeOfAKind
            } else {
                HandRanking::TwoPair
            }
        },
        4 => HandRanking::OnePair,
        _ => HandRanking::HighCard,
    } 
}

fn ch_to_val(ch: char) -> i64 {
    match ch {
        'A' => 14,
        'K' => 13,
        'Q' => 12,
        'J' => 11,
        'T' => 10,
        _ => {
            ch.to_digit(10).unwrap() as i64
        }
    }
}

fn cmp_str(a_hand: &str, b_hand: &str) -> Ordering {
    for (a, b) in zip(a_hand.chars(), b_hand.chars()) {
        if ch_to_val(a) < ch_to_val(b) {
            return Ordering::Less;
        }
        if ch_to_val(a) > ch_to_val(b) {
            return Ordering::Greater;
        }
    }
    Ordering::Equal
}

fn main() {
    let reader = io::stdin().lock();
    let mut hands = Vec::<(String, i64)>::new();
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        let re = Regex::new(r"(?<hand>.{5}) (?<bid>\d+)").expect("I f'up regex");
        let Some(caps) = re.captures(&line) else {
            eprintln!("Line didn't match the pattern");
            return;
        };
        let bid: i64 = caps["bid"]
            .parse()
            .expect("Couldn't parse the bid");
        hands.push((caps["hand"].to_string(), bid));
    }
    hands.sort_unstable_by(|a, b| {
        let rank_a = get_rank(&a.0);
        let rank_b = get_rank(&b.0);
        if rank_a == rank_b {
            cmp_str(&a.0, &b.0)
        } else {
            rank_a.cmp(&rank_b)
        }
    });
    let first = hands.iter().next().unwrap();
    let mut result: i64 = first.1;
    let mut last: &str = &first.0;
    let mut rank = 1;
    println!("{} {:?} {} {rank}", first.0, get_rank(&first.0), first.1);
    for h in &hands[1..] {
        if last != h.0 {
            rank += 1;
        }
        result += rank * h.1;
        last = &h.0;
        println!("{} {:?} {} {rank}", h.0, get_rank(&h.0), h.1);
    }
    println!("{result}");
}
