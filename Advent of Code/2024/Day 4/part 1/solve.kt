fun solve(lines: List<String>): Int {
    val w = lines.size
    val h = lines[0].length
    // letters '.' are sentinels
    val grid = Array(h + 6) { CharArray(w + 6) { '.' } }
    lines.forEachIndexed { y, line ->
        line.forEachIndexed { x, c ->
            grid[y + 3][x + 3] = c
        }
    }
    var total = 0
    for (y in 0 until h) {
        for (x in 0 until w) {
            // E, W, S, N, SE, SW, NE, NW
            val dy = arrayOf(
                arrayOf(0, 0, 0, 0), // E
                arrayOf(0, 0, 0, 0), // W
                arrayOf(0, 1, 2, 3), // S
                arrayOf(0, -1, -2, -3), // N
                arrayOf(0, 1, 2, 3), // SE
                arrayOf(0, 1, 2, 3), // SW
                arrayOf(0, -1, -2, -3), // NE
                arrayOf(0, -1, -2, -3), // NW
            )
            val dx = arrayOf(
                arrayOf(0, 1, 2, 3), // E
                arrayOf(0, -1, -2, -3), // W
                arrayOf(0, 0, 0, 0), // S
                arrayOf(0, 0, 0, 0), // N
                arrayOf(0, 1, 2, 3), // SE
                arrayOf(0, -1, -2, -3), // SW
                arrayOf(0, 1, 2, 3), // NE
                arrayOf(0, -1, -2, -3), // NW
            )
            for (i in 0 until 8) {
                var mismatch = false
                for (j in 0 until "XMAS".length) {
                    val c = grid[y + dy[i][j] + 3][x + dx[i][j] + 3]
                    if (c != "XMAS"[j]) {
                        mismatch = true
                        break
                    }
                }
                if (!mismatch) {
                    total++
                }
            }
        }
    }
    return total
}

fun main() {
    assert(solve(listOf(
        "XMAS",
        "....",
        "SAMX",
        "....",
    )) == 2)
    assert(solve(listOf(
        "X..S",
        "M..A",
        "A..M",
        "S..X",
    )) == 2)
    assert(solve(listOf(
        "X...",
        ".M..",
        "..A.",
        "...S",
    )) == 1)
    assert(solve(listOf(
        "S...",
        ".A..",
        "..M.",
        "...X",
    )) == 1)
    assert(solve(listOf(
        "...X",
        "..M.",
        ".A..",
        "S...",
    )) == 1)
    assert(solve(listOf(
        "...S",
        "..A.",
        ".M..",
        "X...",
    )) == 1)
    assert(solve(listOf(
        "..X...",
        ".SAMX.",
        ".A..A.",
        "XMAS.S",
        ".X....",
    )) == 4)
    assert(solve(listOf(
        "MMMSXXMASM",
        "MSAMXMSMSA",
        "AMXSXMAAMM",
        "MSAMASMSMX",
        "XMASAMXAMM",
        "XXAMMXXAMA",
        "SMSMSASXSS",
        "SAXAMASAAA",
        "MAMMMXMMMM",
        "MXMXAXMASX",
    )) == 18)

    val lines = generateSequence { readLine() }.toList()
    solve(lines).also { println(it) }
}
