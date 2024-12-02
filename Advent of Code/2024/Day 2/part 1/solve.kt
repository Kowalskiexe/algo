import kotlin.math.abs


fun safe(report: List<Int>): Boolean {
    if (report.size <= 1)
        return true

    val d = if (report[1] - report[0] > 0) 1 else -1
    // 1 - increases
    // -1 - decreases

    for (i in 1 until report.size) {
        val diff = report[i] - report[i - 1]
        if (diff * d < 0) // sign mismatch
            return false
        if (abs(diff) < 1 || abs(diff) > 3)
            return false
    }
    return true
}

fun main() {
    val lines = generateSequence { readlnOrNull()?.split(" ") }.toList()
    val reports = lines.map { it.map { it.toInt() }.toList() }
    var result = 0
    for (report in reports) {
        if (safe(report)) {
            result++
        }
    }
    println(result)
}
