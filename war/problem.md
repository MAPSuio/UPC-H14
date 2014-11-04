# War
![](<path to image here>)

<needs more story>

War is a card game where the outcome is completely dependent on the state at the start at the game, so instead of actually playing it, PLAYER1 and PLAYER2 wanted you to make a program that played it for them automatically.

PLAYER1 and PLAYER2 have divided their cards, and the stacks of cards are described to you in the input. PLAYER1 has n cards and PLAYER2 has m cards. The cards are in the order from top to bottom of the stack, so the first card PLAYER1 will draw is card _n0_ and the first card PLAYER2 will draw is card _m0_.

The game starts by PLAYER1 and PLAYER2 each drawing a card from their stacks and comparing them. The player with the highest number takes both cards. If the cards are equal, PLAYER1 and PLAYER2 take three cards each from their stack and place them face down. Then they draw two new cards and compare them. The player with the highest card wins all 10 cards. If they are still equal, another 6 cards are placed face down and another 2 cards are drawn to compare. The winner takes all 18 cards. If they are equal, this process continues.

When a player wins a card, it is placed at the bottom of the winning players stack.

<create scheme for deciding the order when cards are put together like that>
Temporarily
* the winning player's cards are placed into his/her stack, with the first card that entered the board as the first card into the stack
* The losing player's cards are then inserted the same way.

The first player to lose all his/her cards lose the game. Find out if the game will end with PLAYER1 winning, PLAYER2 winning or a draw, or (maybe) if the game is infinite (hopefully not)

It is a draw when both players "lose" in the same round.

## Input
* n - number of cards for PLAYER1
* m - number of cards for PLAYER2
* n cards, each with value k
* m cards, each with value k

## Output
* output one of PLAYER1, PLAYER2 or draw.

## Constraints
* 0 &le; n, m &le; 500
* multiple cards may carry the same k
* k is positive: 0 &le; k &le; 10<sup>5</sup>
* If no winner is decided within 100 000 iterations, they call it a draw.

## Sample input
```
3
3
2 3 1
1 2 3
```

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
PLAYER1
```
