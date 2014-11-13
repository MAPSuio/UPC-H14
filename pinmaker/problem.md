# The pinmaker
__Problem ID__: _pinmake_

![](../images/pinmaker.jpg)

As everyone else, Keanu is an enthusiastic user of BankID for mobile. It
has made his life so much easier to finally be able to throw away the annoying
_kodebrikke_.

As you probably know, BankID requires you to make up a PIN. Keanu, being
interested in security, uses of course the maximum PIN length - 8 digits.
Having an 8 digit PIN has a huge drawback; it's impossible to remember.
Therefore Keanu came up with a deceiptful scheme for his PIN; 1234567X, where
_X_ is any number _other_ than 8. To make sure he didn't forget, he also put a
note saying `1234567X` on the back of his phone, thus avoiding to write down
his actual PIN (very clever indeed).

Unfortunately Keanu seems to get his phone stolen every few weeks or so. And
the thieves seem to always find a way to crack his PIN-code scheme. Therefore
Keanu has decided to change PIN-codes every day, following a new and more
advanced scheme to make PIN-codes.

For his new scheme, Keanu has come up with a revolutionary new number
sequence, the Keanucci sequence, inspired by the famous Fibonnacci sequence.
The sequence is defined as follows:

k<sub>n</sub> = k<sub>n - 1</sub> + k<sub>n - 2</sub>

As you can see, the only difference is that instead of starting
with 1 and 1 (or 0 and 1, depending of definition), Keanu will start the
sequence with the current day and month.

For instance, on November 13, the Keanucci sequence is as follows:

k<sub>0</sub> = 13  
k<sub>1</sub> = 11  
k<sub>2</sub> = 24  
k<sub>3</sub> = 35  
k<sub>4</sub> = 59  
k<sub>5</sub> = 94  
...   
k<sub>n</sub> =  k<sub>n - 1</sub> + k<sub>n - 2</sub> 

To make his PIN-code on a given day, Keanu first finds a _properly_ random
number _n_; the number of days between his last two electrical bills from BKK.
Then he calculates the _n_-th Keanucci number for that day, and uses the last 8
digits as his PIN-code. If the _n_-th Keanucci number has less than 8 digits,
Keanu will simply add leading zeroes.

## Input
The input consists of three space separated integers _d_, _m_ and _n_, the
current day, month and the random number Keanu came up with.

## Output
Output Keanu's 8 digit PIN-code for the given day.

## Constraints
1 &le; _d_ &le; 31  
1 &le; _m_ &le; 12  
1 &le; _n_ &le; 100

## Sample input 1
```
1 1 12
```

## Sample output 1
```
00000233
```

## Sample input 2
```
30 12 8
```

## Sample output 2
```
00000642
```

## Sample input 3
```
5 2 35
```

## Sample output 3
```
46969365
```
