# I'd rather walk alone
 ![](../images/walkalone.jpg)

One evening you're visiting your uncle, you find yourself exploring his dark
basement. In a hidden drawer along some football cards you discover some old
and almost unreadable hand written notes. The title says `season 1989/1990`.
You examine the papers closely and discover numerous messages. `Liverpool
before Manchester United` one message says.

You are stunned. You can't believe what you're reading. What could this mean?
Could it really be that Liverpool placed before Manchester United in the top
division some time in the past? You quickly decide to investigate by making a
program to decipher these messages into a sorted table.

## Input
Input is a list of league placement constraints between teams in the English top
football division.

Each line in the input represents such a constraint, and indicates that one
team places either somewhere before or somewhere after another team in the
league.

All team names are given as single words, (team names with spaces are
concatenated with camelCase). You can assume that the constraints are
consistent; i.e. that that a team can't be placed both before and after another
team. You can also assume that for a set of constraints, there only exist one
possible solution.

## Output
Output a sorted list of the teams in ascending order with regards to how they
placed in the league.

## Constraints
Number of teams in a league is always greater than 1 and less or equal to 20.

## Sample input
```
Liverpool BEFORE ManchesterUnited
Chelsea AFTER ManchesterUnited
Chelsea AFTER Liverpool
```

## Sample output
```
Liverpool
ManchesterUnited
Chelsea
```
