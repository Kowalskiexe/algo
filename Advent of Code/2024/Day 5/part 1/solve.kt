fun main() {
    val lines = generateSequence { readLine() }.toList()
    val split = lines.indexOf("")
    val rules = mutableMapOf<Int, MutableSet<Int>>()
    for (i in 0 until split) {
        val (a, b) = lines[i].split("|").map { it.toInt() }
        rules.getOrPut(a) { mutableSetOf<Int>() }.add(b)
    }
    println(rules)

    var result = 0
    for (i in split + 1 until lines.size) {
        val q = lines[i].split(",").map { it.toInt() }
        var succ = true
        val prefix = mutableSetOf<Int>()
        for (v in q) {
            if (prefix.intersect(rules.getOrDefault(v, mutableSetOf())).isNotEmpty()) {
                println("prefix $prefix, q $q v $v rules ${rules[v]}")
                succ = false
                break
            }
            prefix.add(v)
        }
        if (succ) {
            println("add $q ${q.size / 2} ${q[q.size / 2]}")
            result += q[q.size / 2]
        }

        q.forEach { print("$it ") }
        println()
        println("$succ")
    }
    println(result)
}
