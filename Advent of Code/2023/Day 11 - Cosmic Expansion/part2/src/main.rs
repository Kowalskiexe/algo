use std::io::{self, BufRead};

fn is_empty_h(line: &str) -> bool {
    for ch in line.chars() {
        if ch != '.' {
            return false;
        }
    }
    true
}

fn dist(a: (usize, usize), b: (usize, usize)) -> usize {
    let mut dist = 0;
    let (ax, ay) = a;
    let (bx, by) = b;
    if ax > bx {
        dist += ax - bx;
    } else {
        dist += bx - ax;
    }
    if ay > by {
        dist += ay - by;
    } else {
        dist += by - ay;
    }
    dist
}

fn main() {
    let reader = io::stdin().lock();
    let mut map = Vec::<Vec<char>>::new();
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        if is_empty_h(&line) {
            map.push(line.chars().clone().collect());
        }
        map.push(line.chars().collect());
    }
    let mut x = 0;
    while x < map[0].len() {
        let mut is_empty_v = true;
        for y in 0..map.len() {
            if map[y][x] != '.' {
                is_empty_v = false;
                break;
            } 
        }
        if is_empty_v {
            for y in 0..map.len() {
                map[y].splice(x..x, vec!['.']);
            }
            x += 1;
        }
        x += 1;
    }

    // TODO: don't expand, use a mask
    // fields marked a by a mask count as 1'000'000 fields

    // expanded
    for row in &map {
        for ch in row {
            print!("{ch}");
        }
        println!("");
    }

    // find galaxies
    let mut galaxies = Vec::<(usize, usize)>::new();
    for (y, row) in map.iter().enumerate() {
        for (x, ch) in row.iter().enumerate() {
            if *ch == '#' {
                galaxies.push((y, x));
            }
        }
    }

    let mut result = 0;
    for g1 in &galaxies {
        for g2 in &galaxies {
            result += dist(*g1, *g2);
        }
    }
    result /= 2;
    println!("{result}");
}
