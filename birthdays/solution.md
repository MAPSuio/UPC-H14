# Happy birthday to you
The easiest solution is to use a language with an good date library. 
Iterating by one year from the start to the end year and checking if the year is a leap year and if the leap day was on 
a friday or saturday.
The corner case here is to not include the start year if the birthday was after february. The same applies to the end year, 
if the birthday is before february.