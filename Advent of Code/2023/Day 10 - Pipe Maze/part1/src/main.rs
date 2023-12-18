use std::collections::{HashMap, HashSet};
use std::io::{self, BufRead};

fn get_start(map: &Vec<Vec<char>>) -> Option<(usize, usize)> {
    for (y, row) in map.iter().enumerate() {
        for (x, ch) in row.iter().enumerate() {
            if *ch == 'S' {
                return Some((y, x));
            }
        }
    }
    None
}

fn is_top_side_open(ch: char) -> bool {
    let left_open: Vec<_> = "|LJS".chars().collect();
    left_open.contains(&ch)
}
fn is_bottom_side_oepn(ch: char) -> bool {
    let left_open: Vec<_> = "|F7S".chars().collect();
    left_open.contains(&ch)
}
fn is_right_side_open(ch: char) -> bool {
    let left_open: Vec<_> = "-LFS".chars().collect();
    left_open.contains(&ch)
}
fn is_left_side_open(ch: char) -> bool {
    let left_open: Vec<_> = "-J7S".chars().collect();
    left_open.contains(&ch)
}

fn get_up(map: &Vec<Vec<char>>, curr_pos: (usize, usize)) -> Option<(usize, usize)> {
    let (y, x) = curr_pos;
    if y == 0 {
        return None;
    }
    if is_bottom_side_oepn(map[y - 1][x]) {
        Some((y - 1, x))
    } else {
        None
    }
}

fn get_down(map: &Vec<Vec<char>>, curr_pos: (usize, usize)) -> Option<(usize, usize)> {
    let h = map.len();
    let (y, x) = curr_pos;
    if y >= h - 1 {
        return None;
    }
    if is_top_side_open(map[y + 1][x]) {
        Some((y + 1, x))
    } else {
        None
    }
}

fn get_left(map: &Vec<Vec<char>>, curr_pos: (usize, usize)) -> Option<(usize, usize)> {
    let (y, x) = curr_pos;
    if x == 0 {
        return None;
    }
    if is_right_side_open(map[y][x - 1]) {
        Some((y, x - 1))
    } else {
        None
    }
}

fn get_right(map: &Vec<Vec<char>>, curr_pos: (usize, usize)) -> Option<(usize, usize)> {
    let w = match map.first() {
        Some(row) => row.len(),
        None => 0,
    };
    let (y, x) = curr_pos;
    if x >= w - 1 {
        return None;
    }
    if is_left_side_open(map[y][x + 1]) {
        Some((y, x + 1))
    } else {
        None
    }
}

fn get_adj(map: &Vec<Vec<char>>) -> HashMap<(usize, usize), Vec<(usize, usize)>> {
    let mut adj = HashMap::<(usize, usize), Vec<(usize, usize)>>::new();
    for (y, row) in map.iter().enumerate() {
        for (x, ch) in row.iter().enumerate() {
            let mut neighbors = Vec::<(usize, usize)>::new();
            match ch {
                'S' => {
                    match get_up(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_down(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_left(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_right(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                }
                '|' => {
                    match get_up(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_down(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                }
                '-' => {
                    match get_left(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_right(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                }
                'L' => {
                    match get_up(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_right(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                }
                'J' => {
                    match get_up(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_left(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                }
                '7' => {
                    match get_left(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_down(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                }
                'F' => {
                    match get_right(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                    match get_down(map, (y, x)) {
                        Some(v) => neighbors.push(v),
                        None => (),
                    }
                }
                _ => (),
            }
            adj.insert((y, x), neighbors);
        }
    }
    adj
}

fn dfs(
    map: &Vec<Vec<char>>,
    adj: &HashMap<(usize, usize), Vec<(usize, usize)>>,
    start: (usize, usize),
) -> Option<usize> {
    let mut visited = HashSet::<(usize, usize)>::new();
    _dfs(map, adj, start, &mut visited, start, 0)
}

fn _dfs(
    map: &Vec<Vec<char>>,
    adj: &HashMap<(usize, usize), Vec<(usize, usize)>>,
    pos: (usize, usize),
    visited: &mut HashSet<(usize, usize)>,
    prev: (usize, usize),
    len: usize,
) -> Option<usize> {
    let (y, x) = pos;
    if visited.contains(&pos) {
        if map[y][x] == 'S' {
            return Some(len);
        } else {
            return None;
        }
    }
    visited.insert(pos);
    let mut cycle: Option<usize> = None;
    for n in &adj[&pos] {
        if *n != prev {
            match _dfs(map, adj, *n, visited, pos, len + 1) {
                Some(length) => cycle = Some(length),
                None => (),
            };
        }
    }
    cycle
}

fn main() {
    let reader = io::stdin().lock();
    let mut map = Vec::<Vec<char>>::new();
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        map.push(line.chars().collect());
    }

    let start = get_start(&map).expect("Couldn't find the starting point");
    let adj = get_adj(&map);
    for (node, neighbors) in &adj {
        print!("{:?}: ", node);
        for n in neighbors {
            print!("{:?}", n);
        }
        println!("");
    }
    let result = dfs(&map, &adj, start).expect("Didn't find a cycle") / 2;
    println!("{result}");
}
