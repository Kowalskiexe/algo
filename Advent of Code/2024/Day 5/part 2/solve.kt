fun dfs(rules: Map<Int, MutableSet<Int>>, pos: Int, ordering: MutableList<Int>, visited: MutableSet<Int>) {
    if (visited.contains(pos)) {
        return
    }
    visited.add(pos)
    for (v in rules.getOrDefault(pos, mutableSetOf())) {
        if (visited.contains(v)) {
            continue
        }
        dfs(rules, v, ordering, visited)
    }
    ordering.add(pos)
}

fun findStart(rules: Map<Int, MutableSet<Int>>): Int {
    val incoming = rules.values.asSequence().flatten()
    return rules.keys.filter { !incoming.contains(it) }.first()
}

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
        if (!succ) {
            val relevantRules = rules.filterKeys { q.contains(it) }.toMutableMap()
            for (k in relevantRules.keys) {
                relevantRules.put(k, relevantRules[k]!!.intersect(q).toMutableSet())
            }
            val ordering = mutableListOf<Int>()
            val visited = mutableSetOf<Int>()
            dfs(relevantRules, findStart(relevantRules), ordering, visited)
            println("dfs $q -> $ordering")
            result += ordering[ordering.size / 2]
        }

        q.forEach { print("$it ") }
        println()
        println("$succ")
    }
    println(result)
}
