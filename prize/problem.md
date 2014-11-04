# UPC prize commitee
![](../images/prize.png)

The prize commitee at UPC has been hard at work getting as many prizes for the
contest as possible. If fact they even managed to get an iPhone 6 as a prize.
Wanting the phone for themselves, the commitee has decided to form a team and
participate in the contest. The problem, however, is that they aren't good
enough to win.

The prizes are ranged after value. The best team gets the most expensive prize,
the second best team get the second most expensize prize, and so on.

Which position does the commitee team have to end on in order to win the
iPhone?

## Input
The first line of input contains a single integer _N_, the number of prizes.

Then follows _N_ lines describing the prizes, in no particular order. Each line
contains a word (atmost 50 characters long), the name of the prize, followed
by an positive number _v_, the value of the prize. No two prizes will have the
same name, and there will always be a prize named `iPhone`.

## Output
Output a single integer; the position that the commitee has to end on in order
to win the phone.

If it is impossible to get the phone without winning the entire contest
(remember, the commitee aren't that good), simply output `STEAL THE PHONE`.

## Constraints
1 &le; _N_ &le; 10000  
1 &le; _v_ &le; 10000000

## Sample input 1
```
4
iMac 9290
Tesla 867000
Litago 17.90
iPhone 5790
```

## Sample output 1
```
3
```

## Sample input 2
```
4 6
Litago 18
iPhone 5790
Galaxy_S4 100
PS4 3590
```

## Sample output 2
```
STEAL THE PHONE
```
