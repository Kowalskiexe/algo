import kotlin.text.Regex


fun main() {
    val lines = generateSequence { readLine() }.toList()
    var total = 0
    for (line in lines) {
        val regex = Regex("""mul\(\d{1,3},\d{1,3}\)""")
        regex.findAll(line).forEach {
            // mul(a,b)
            val args = it.value.substring(4, it.value.length - 1)
            // a,b
            val (a, b) = args.split(",").map { it.toInt() }
            total += a * b
        }
    }
    println(total)
}
