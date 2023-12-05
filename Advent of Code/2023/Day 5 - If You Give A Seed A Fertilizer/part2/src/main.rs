use std::io::{self, BufRead};
use regex::Regex;
use std::cmp::Ordering;

fn extract_nums(text: &str) -> Vec<i64> {
    let num_pat = Regex::new(r"\d+").expect("I f'up regex");
    let mut nums = Vec::new();
    for mat in num_pat.find_iter(&text) {
        let mat = String::from(mat.as_str().trim());
        let mat: i64 = mat.parse().expect("It should be a number.");
        nums.push(mat);
    }
    nums
}

#[derive(Debug)]
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

#[derive(Debug)]
struct Range {
    start: i64,
    len: i64,
}

impl Range {
    fn end(&self) -> i64 {
        self.start + self.len - 1
    }
}
impl Clone for Range {
    fn clone(&self) -> Range {
        Range {
            start: self.start,
            len: self.len,
        }
    }
}

fn process_layer(old_layer: &Vec<Range>, maps: &Vec<Map>) -> Vec<Range> {
    #[derive(Debug, Eq, PartialEq, PartialOrd, Ord)]
    enum PointState {
        LayerOpening = 3,
        LayerClosing = 1,
        MapOpening = 2,
        MapClosing = 0,
    }
    #[derive(Debug)]
    struct Point<'a> {
        position: i64,
        state: PointState,
        map: Option<&'a Map>,
    }
    let mut points = Vec::<Point>::new();
    for r in old_layer {
        points.push(Point {
            position: r.start,
            state: PointState::LayerOpening,
            map: None,
        });
        points.push(Point {
            position: r.end() + 1,
            state: PointState::LayerClosing,
            map: None,
        });
    }
    for m in maps {
        points.push(Point {
            position: m.src_start,
            state:PointState::MapOpening,
            map: Some(m),
        });
        points.push(Point {
            position: m.src_start + m.len,
            state:PointState::MapClosing,
            map: Some(m),
        });
    }
    // TODO: what if they are at the same position?
    // if so then closing before opening
    points.sort_unstable_by(|a, b| {
        let f = a.position.cmp(&b.position);
        if f == Ordering::Equal {
            a.state.cmp(&b.state)
        } else {
            f
        }
    });
    println!("points:");
    for p in &points {
        println!("{:?}", p);
    }
    #[derive(Debug)]
    enum Coverage {
        Empty,
        Uncovered,
        Covered,
    }
    let mut is_layer = false;
    let mut is_map = false;
    let mut start = -1;
    let mut new_ranges = Vec::<Range>::new();
    let mut covering: Option<&Map> = None;
    for p in &points {
        let cov = if is_layer && is_map {
            Coverage::Covered
        } else if is_layer && !is_map {
            Coverage::Uncovered
        } else {
            Coverage::Empty
        };
        let end = if start == p.position {
            start
        } else {
            p.position - 1
        };
        let len = end - start + 1;
        println!("from {start} to {} is {:?} il={is_layer} im={is_map}", end, cov);
        match cov {
            Coverage::Covered => {
                let m = covering.expect("It should point to a Map");
                let start = m.trans(start).expect("Couldn't translate");
                println!("push {start} {len}");
                new_ranges.push(Range {
                    start,
                    len,
                });
            }
            Coverage::Uncovered => {
                println!("push {start} {len}");
                new_ranges.push(Range {
                    start,
                    len,
                });
            }
            Coverage::Empty => ()
        }
        start = p.position;
        match p.state {
            PointState::LayerOpening => is_layer = true,
            PointState::LayerClosing => is_layer = false,
            PointState::MapOpening => {
                is_map = true;
                covering = p.map;
            },
            PointState::MapClosing => {
                is_map = false;
                covering = None;
            },
        }
    }
    for r in &new_ranges {
        if r.len == 0 {
            println!("kurwaawwaa");
        }
    }
    new_ranges = unify_ranges(&new_ranges);
    new_ranges
}

fn unify_ranges(in_ranges: &Vec<Range>) -> Vec<Range> {
    if in_ranges.is_empty() {
        return Vec::<Range>::new();
    }
    let mut tmp: Vec<Range> = in_ranges.clone();
    tmp.sort_unstable_by(|a, b| a.start.cmp(&b.start));
    let mut start = tmp[0].start;
    let mut last_end = tmp[0].end();
    let mut out_ranges = Vec::<Range>::new();
    for r in &tmp[1..] {
        if last_end - r.start >= -1 {
            // if overlapping:
            // do nothing
        } else {
            // if not: push
            let len = last_end - start + 1;
            out_ranges.push(Range {
                start,
                len,
            });
            start = r.start;
        }
        last_end = r.end();
    }
    // push whatever's left
    let len = last_end - start + 1;
    out_ranges.push(Range {
        start,
        len,
    });
    out_ranges
}

fn main() {
    let reader = io::stdin().lock();

    let mut seeds = Vec::<Range>::new();
    let mut maps = Vec::<Vec<Map>>::new();
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        let seeds_header = Regex::new(r"seeds:").expect("I f'up regex");
        if seeds_header.is_match(&line) {
            let nums = extract_nums(&line);
            for (i, _) in nums.iter().enumerate() {
                if i % 2 == 1 {
                    continue;
                }
                seeds.push(Range {
                    start: nums[i],
                    len: nums[i + 1],
                });
            }
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
    let mut c = seeds.clone();
    for (i, layer) in maps.iter().enumerate() {
        println!("----------------");
        println!("layer: {i}");
        c = process_layer(&c, layer);
        for r in &c {
            println!("{:?}", r);
        }
    }
    for r in c {
        result = i64::min(result, r.start);
    }
    println!("{result}");
}
