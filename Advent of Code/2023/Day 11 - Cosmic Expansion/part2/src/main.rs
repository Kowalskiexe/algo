use std::io::{self, BufRead};

fn is_empty_h(row: &Vec<char>) -> bool {
    for ch in row {
        if *ch != '.' {
            return false;
        }
    }
    true
}

fn dist(
    mask: &Vec<Vec<usize>>,
    a: (usize, usize),
    b: (usize, usize),
) -> usize {
    let mut dist = 0;
    let (ay, ax) = a;
    let (by, bx) = b;

    let sx = usize::min(ax, bx);
    let sy = usize::min(ay, by);
    let dx = usize::max(ax, bx);
    let dy = usize::max(ay, by);

    let expansion_rate = 1_000_000;

    for x in sx+1..=dx {
        if mask[sy][x] == 1 {
            dist += expansion_rate;
        } else {
            dist += 1;
        }
    }
    for y in sy+1..=dy {
        if mask[y][dx] == 1 {
            dist += expansion_rate;
        } else {
            dist += 1;
        }
    }

    dist
}

fn main() {
    let reader = io::stdin().lock();
    let mut map = Vec::<Vec<char>>::new();
    for line_result in reader.lines() {
        let line = line_result.unwrap();
        map.push(line.chars().collect());
    }
    let mut mask: Vec<_> = map.iter().map(
        |row| vec![0; row.len()]
    ).collect();
    for (y, row) in map.iter().enumerate() {
        if is_empty_h(row) {
            for x in 0..mask[0].len() {
                mask[y][x] = 1;
            }
        }
    }

    for x in 0..map[0].len() {
        let mut is_empty_v = true;
        for y in 0..map.len() {
            if map[y][x] != '.' {
                is_empty_v = false;
                break;
            } 
        }
        if is_empty_v {
            for y in 0..mask.len() {
                mask[y][x] = 1;
            }
        }
    }

    for (y, row) in map.iter().enumerate() {
        for (x, ch) in row.iter().enumerate() {
            if mask[y][x] == 0 {
                print!("{ch}");
            } else {
                print!("o");
            }
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
            let d = dist(&mask, *g1, *g2);
            result += d;
        }
    }
    result /= 2;
    println!("{result}");
}
