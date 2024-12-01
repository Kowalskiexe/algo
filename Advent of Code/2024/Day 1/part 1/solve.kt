import kotlin.math.abs

fun main() {
    val lines = generateSequence { readlnOrNull()?.split("   ") }.toList()
    val listA = lines.map { it[0].toInt() }.toMutableList()
    val listB = lines.map { it[1].toInt() }.toMutableList()
    listA.sort()
    listB.sort()
    var total = 0
    for (i in listA.indices) {
        total += abs(listB[i] - listA[i])
    }
    println(total)
}
