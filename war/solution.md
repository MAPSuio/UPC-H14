# War
The naive way:
* You need one queue for each player "stack"
* You need a "bet" queue for each player, these are the extra cards during a war
* You need a container for one card for each player "card"

While there are cards in both queues:
* draw a card from each "stack" into "card"
* compare the cards
* if one card is higher than the other
  * winners bet queue is emptied into winners stack
  * winners card is emptied into winners stack
  * losers bet queue is emptied into winners stack
  * losers card is emptied into winners stack
* else push the current cards into the bet queue, draw three new and put each into the bet queue
  * it should be safe to ignore it if you cannot draw enough cards

Afterwards, check which queues are empty. If both are empty it is a draw, if one is empty and not the other, there is a winner.
