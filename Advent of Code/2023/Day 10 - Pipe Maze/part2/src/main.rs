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

fn get_h<T>(map: &Vec<Vec<T>>) -> usize {
    map.len()
}

fn get_w<T>(map: &Vec<Vec<T>>) -> usize {
    match map.first() {
        Some(row) => row.len(),
        None => 0,
    }
}

fn is_top_side_open(ch: char) -> bool {
    let left_open: Vec<_> = "|LJS".chars().collect();
    left_open.contains(&ch)
}
fn is_bottom_side_open(ch: char) -> bool {
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
    if is_bottom_side_open(map[y - 1][x]) {
        Some((y - 1, x))
    } else {
        None
    }
}

fn get_down(map: &Vec<Vec<char>>, curr_pos: (usize, usize)) -> Option<(usize, usize)> {
    let h = get_h(map);
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
    let w = get_w(map);
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
) -> Option<Vec<(usize, usize)>> {
    let mut visited = HashSet::<(usize, usize)>::new();
    _dfs(map, adj, start, &mut visited, start)
}

fn _dfs(
    map: &Vec<Vec<char>>,
    adj: &HashMap<(usize, usize), Vec<(usize, usize)>>,
    pos: (usize, usize),
    visited: &mut HashSet<(usize, usize)>,
    prev: (usize, usize),
) -> Option<Vec<(usize, usize)>> {
    let (y, x) = pos;
    if visited.contains(&pos) {
        if map[y][x] == 'S' {
            return Some(Vec::new());
        } else {
            return None;
        }
    }
    visited.insert(pos);
    let mut cycle: Option<Vec<(usize, usize)>> = None;
    for n in &adj[&pos] {
        if *n != prev {
            match _dfs(map, adj, *n, visited, pos) {
                Some(mut cyc) => {
                    cyc.push((y, x));
                    cycle = Some(cyc);
                }
                None => (),
            };
        }
    }
    cycle
}

fn get_shape(
    point: (usize, usize),
    neighbors: &[(usize, usize)],
) -> Option<char> {
    let mut is_top_open = false;
    let mut is_bottom_open = false;
    let mut is_left_open = false;
    let mut is_right_open = false;
    let (y, x) = point;
    for (ny, nx) in neighbors {
        if y > 0 && *ny == y - 1 && *nx == x {
            is_top_open = true;
        }
    }
    for (ny, nx) in neighbors {
        if *ny == y + 1 && *nx == x {
            is_bottom_open = true;
        }
    }
    for (ny, nx) in neighbors {
        if *ny == y && x > 0 && *nx == x - 1 {
            is_left_open = true;
        }
    }
    for (ny, nx) in neighbors {
        if *ny == y && *nx == x + 1 {
            is_right_open = true;
        }
    }
    if is_top_open && is_bottom_open {
        return Some('|');
    }
    if is_left_open && is_right_open {
        return Some('-');
    }
    if is_top_open && is_right_open {
        return Some('L');
    }
    if is_top_open && is_left_open {
        return Some('J');
    }
    if is_left_open && is_bottom_open {
        return Some('7');
    }
    if is_right_open && is_bottom_open {
        return Some('F');
    }
    None
}

// shoot a ray in NW direction
// return number of collisions with the border
fn ray(map: &Vec<Vec<char>>, mask: &Vec<Vec<usize>>, src: (usize, usize)) -> usize {
    let (mut y, mut x) = src;
    let mut col = 0;
    while y > 0 && x > 0 {
        y -= 1;
        x -= 1;
        // ignore 7 and L
        if mask[y][x] == 1 && map[y][x] != 'L' &&  map[y][x] != '7' {
            col += 1;
        }
    }
    col
}

fn is_inside(map: &Vec<Vec<char>>, mask: &Vec<Vec<usize>>, point: (usize, usize)) -> bool {
    let col = ray(map, mask, point);
    col % 2 == 1
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
    let cycle = dfs(&map, &adj, start).expect("Didn't find a cycle");
    println!("{:?}", cycle);

    let (sy, sx) = start;
    let neighbors = vec![
        cycle[0].clone(),
        cycle[cycle.len() - 2].clone(),
    ];
    map[sy][sx] = get_shape(start, &neighbors[..]).expect("Couldn't determine shape for S");

    // 0 - ground
    // 1 - border
    // 2 - filled
    let mut mask: Vec<Vec<usize>> = map.iter().map(|row| vec![0; row.len()]).collect();
    for node in &cycle {
        let (y, x) = *node;
        mask[y][x] = 1;
    }

    let w = get_w(&map);
    let h = get_h(&map);

    for y in 0..h {
        for x in 0..w {
            if mask[y][x] == 1 {
                continue;
            }
            if is_inside(&map, &mut mask, (y, x)) {
                mask[y][x] = 2;
            }
        }
    }
    let mut result = 0;
    for (y, row) in mask.iter().enumerate() {
        for (x, n) in row.iter().enumerate() {
            match n {
                0 => print!("."),
                1 => print!("{}", map[y][x]),
                2 => {
                    print!("o");
                    result += 1;
                },
                _ => (),
            };
        }
        println!("");
    }
    println!("{result}");
}
