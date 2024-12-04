fun solve(lines: List<String>): Int {
    val w = lines.size
    val h = lines[0].length
    var total = 0
    for (y in 1 until h - 1) {
        for (x in 1 until w - 1) {
            val c = lines[y][x]
            val SE = lines[y + 1][x + 1]
            val SW = lines[y + 1][x - 1]
            val NE = lines[y - 1][x + 1]
            val NW = lines[y - 1][x - 1]
            if (c == 'A'
                && ((NW == 'M' && SE == 'S') || (NW == 'S' && SE == 'M'))
                && ((NE == 'M' && SW == 'S') || (NE == 'S' && SW == 'M'))
            )
                total++
        }
    }
    return total
}

fun main() {
    assert(solve(listOf(
        "M.S",
        ".A.",
        "M.S",
    )) == 1)
    assert(solve(listOf(
        ".M.S......",
        "..A..MSMS.",
        ".M.S.MAA..",
        "..A.ASMSM.",
        ".M.S.M....",
        "..........",
        "S.S.S.S.S.",
        ".A.A.A.A..",
        "M.M.M.M.M.",
        "..........",
    )) == 9)

    val lines = generateSequence { readLine() }.toList()
    solve(lines).also { println(it) }
}
