# UPC prize commitee
![](../images/prize.png)

The prize commitee at UPC has been hard at work getting as many prizes for the
contest as possible. If fact they even managed to get an iPhone 6 as a prize.
Wanting the phone for themselves, the commitee has decided to form a team and
participate in the contest. The problem, however, is that they aren't good
enough to win.

The prizes are ranged after value. The best team gets the most expensive prize,
the second best team get the second most expensize prize, and so on. The
iPhone has a value of `5790`.

Which position does the commitee team have to end on in order to win the
iPhone?

## Input
The first line of input contains a single integer _N_, the number of prizes.

Then follows _N - 1_ lines describing the prizes (except the iPhone), in no
particular order. Each line contains a word (atmost 50 characters long), the
name of the prize, followed by a positive number _v_, the value of the prize.
No two prizes will have the same name, and all values will have a relative
difference of at least 10<sup>-8</sup>.

## Output
Output a single integer; the position that the commitee has to end on in order
to win the phone.

If it is impossible to get the phone without winning the entire contest
(remember, the commitee aren't that good), simply output `STEAL THE PHONE`.

## Constraints
1 &le; _N_ &le; 10<sup>5</sup>  
1 &le; _v_ &le; 10<sup>7</sup>

## Sample input 1
```
4
iMac 9290
Tesla 867000
Litago 17.90
```

## Sample output 1
```
3
```

## Sample input 2
```
4
Litago 18
Lue 100
PS4 3590
```

## Sample output 2
```
STEAL THE PHONE
```
