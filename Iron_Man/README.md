# Character Randomizer

# Idea
In games (especially fighting games) there is usually a number of different characters to choose from. Players have come up with the term "Iron Man", when two players
play against each other using every character in the game once.<br />
In order to make this more interesting, this Character Randomizer is designed in a way, that it shuffles the sequence of characters for both players individually,
allowing for interesting match ups to take place. In addition, a random stage is picked for every new round and the player who won more matches is crowned as the winner. <br />
This algorithm in specifically designed for the Fighting Game Super Smash Bros Ultimate.

# How does it work?
- characters and Stage for the current round is determined
- after the round has taken place, the winner of this round is declared by either pressing 1 or 2
- the process is repeated until every character has been played once by both players

# Notes
Similarly to the Ranking System, I would have approached this project differently nowadays, but the main focus back then were early problem-solving approaches and
handling randomness in C. I've listed some ideas in Fix.

# To Fix
- non-optimal shuffle -> perhaps Fisher-Yates Shuffle
- less magic numbers -> more dynamic variables
- structuring the code in reusable functions and no copy and paste -> especially since player 1 and player 2 prectically do the same
