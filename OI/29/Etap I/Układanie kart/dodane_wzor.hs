f n = if n == 3
		then 1
		else f(n - 1) * (n - 1) + 1