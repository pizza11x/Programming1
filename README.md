# Programming1 University Project (ITA)
 
LABORATORY EXAM PROJECT
 
1. Game of pairs of cards
To develop an algorithm for simulating the game of pairs of cards between two players identified by their names. Initially "shuffling" a deck of Neapolitan cards.
The algorithm for shuffling the cards is based on the idea of actually swapping the cards in the deck in pairs; an input variable allows you to indicate how many times you have to
make exchanges.
It is randomly chosen which of the two players is to start the game. Two cards are "revealed" whose position is indicated by the first player. If the two cards have the same value, the player scores a point and the two cards are revealed.
The player continues until he makes a mistake (he does not find two identical cards) and the turn passes to the other player. At each turn, the player has the list of face down and face up cards available. The game ends when all the cards are revealed. The player with the most points wins the game.
Implement the program and perform at least 3 tests.
Use the function rand (), whose prototype is in <stdlib.h>, to generate the indices of the two cards to be exchanged at each step. In tests, always starting with the deck
"Sorted" and then view the "shuffled" deck.
Remember that, if random_number is declared of type int, then the call random_number = rand ()% (n + 1); generates a random integer (uniform distribution) in the set (0,1,2, .. n).


2. Current account
Suppose you want to manage the current accounts of n users. Each user is identified by the Surname, Name, account number, movement list.
 Manage current accounts and manage the following operations
• Enter a new account holder who is assigned a unique code.
• View the movement list of a given account holder (given the account number or Surname / Name) on a set date.
Implement the algorithm for simulating current accounts. Carry out and
display at least one test for each of the required options

 
