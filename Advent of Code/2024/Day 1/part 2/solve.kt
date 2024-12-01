import kotlin.math.abs

fun main() {
    val lines = generateSequence { readlnOrNull()?.split("   ") }.toList()
    val listA = lines.map { it[0].toInt() }.toMutableList()
    val listB = lines.map { it[1].toInt() }.toMutableList()
    var total = 0
    for (v in listA) {
        total += v * listB.count { it == v }
    }
    println(total)
}
