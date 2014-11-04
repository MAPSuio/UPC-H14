# War
![](../images/war.jpg)

Your son Mike is a really great kid but he loves to play the classic card game war.
The problem is that he wants to play it with you.
You find the game a bit boring since there are no choices in the game, given a sequence of cards in a card deck it is always possible to calculate who the winner is going to be.
You quickly decide to code a program that given a sequence of cards, calculates the course of a game of war. The program should output the player that won.

War consists of rounds, where each round consists of the following steps:
* Each player draws a card from the top of the stack and puts it on the table.
* The player with the higher card wins and collects all cards on the table.
* If the cards are equal, the cards remain on the table, and the players draw three new cards from their stack and place them face down on the table.
* The first player to lose all of his/her cards lose the game.
* If the players lose their cards at the same round or grow tired of the game, it's a draw.

When a player wins cards, they are placed on the bottom of the stack in this order:
* The winning player places his/her own cards, the card which was placed first on the table goes first.
* The winning player then places the opponents cards back into the stack the same way.

If the game goes on for 100 000 rounds or more, they get tired and call it a draw.

You are given your and Mike's stack as input, and your program will print the name of the winner.

## Input
* n - number of cards in your stack
* m - number of cards in Mike's stack
* n cards, each with value k, k0 being the top of the stack
* m cards, each with value k, k0 being the top of the stack

## Output
* output one of you, mike or draw.

## Constraints
* 0 &le; n, m &le; 500
* multiple cards may carry the same value k
* 0 &le; k &le; 10<sup>5</sup>
* If there are 100 000 rounds or more, they call it a draw.

## Sample input
```
3
3
2 3 1
1 2 3
```

## Sample gameplay

* Your stacks at the beginning: [2 3 1] and [1 2 3]
* You draw 2, Mike draws 1, you win.
* [3 1 2 1] and [2 3]
* You draw 3, Mike draws 2, you win.
* [1 2 1 3 2] and [3]
* You draw 1, Mike draws 3, Mike wins.
* [2 1 3 2] and [3 1]
* You draw 2, Mike draws 3, Mike wins.
* [1 3 2] and [1 3 2]
* You draw 1, Mike draws 1
* You try to draw three cards but your stack runs empty
* Mike tries to draw three cards, but his stack also runs empty
* It's a draw.

## Sample output
```
draw
```

## Sample input
```
3
3
4 3 1
3 2 2
```

## Sample output
```
you
```
