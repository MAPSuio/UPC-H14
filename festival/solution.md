# Festival area

Implement http://en.wikipedia.org/wiki/Shoelace_formula.

Shoelace formula pseudocode:
* Points: [a, b, c, d]
* Pairs: \[a, b\] \[b, c\] \[c, d\] \[d,a\]
* for all pairs as a, b
 * sum += a.x*b.y - b.x*a.y
* sum = abs(sum)/2
