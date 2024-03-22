# engg1340comp2113
# Team member
Chen Bozhou (3035820760), Li Jiagen (3035770848)
# FIVE-IN-A-ROW GAME Stage 1 (Part done by Li Jiagen and Chen Bozhou)
## Features
#### Sign in and log in
Users have to create accounts to play this game at the beginning with usernames and passwords entered. 
After users set up their accounts, they can log in to play games whenever they want. Identification is needed in this process.
#### Starting a game
Two players play this game. Only after they both logged into their accounts, they are able to start a game.
Players can choose either to start a new game or to continue with their old game.
If the two players decide to continue with an old game, they need to enter its ending time.
#### Playing methods
They move chess pieces alternately by entering coordinates on the chessboard shown on the screen.
If a coordinate entered is illegal, the player will be asked to re-enter it.
#### Condition of winning a game
The person who first gets five chess pieces in a row, a column or a diagonal wins this game.
If there is not any space left on the chessboard and nobody wins, it is a tie.
Players can choose to take a dive when it comes to their turn.
#### Setting records
After a game comes to a close, its basic information including date and time, players and final result will be recorded automatically.
Players can access their own records later on.
#### Saving unfinished games
If both of players reach an agreement on stopping playing temporarily, the data of this game including the two players' username, time and the person who is going to play the next step will be saved.
## How we implement these features
#### Sign in and log in
We can create a folder named as the username entered by users when users sign in.
The first .txt file in the folder should be password.
When user log in, data in folder cannot be visited before password was qualified.
#### Setting records
There is a .txt file in the account folder that record combat gains.
Each records are just like a line of text combined by elements like "date of game, play with whom, result of game".



# Stage 2 update
## Team member
Chen Bozhou (3035820760), Li Jiagen (3035770848)

## Part done by Chen Bozhou (3035830760)
This is the centre part of five-in-a-row game, which is a C++ program that can play game.
### Improved description & game rule
##### Chessboard and chess
The chessboard is 15×15 size, with coordinate axis at the top and left of the board. The empty grid point on the chessboard shows as '-', and the symbol of chesses are '0' and '1', when player enters a coordinate, the '+' at that point will be replaced by the chess symbol.
##### Illegal coordinate
If player enters a coordinate which not in the chessboard or has already has a chess on it, then a hint "Illegal coordinate or there is already a piece" will print and let the player enters coordinate again.
##### Screen shown
After each player finishs their hand, unless the game end, the screen will be clean and print a new current chessboard with notice that ask another player to enter coordinate.
##### Game end
If one of the player win the game, the program will print "Player x Win!" and end the game.
### List of features
Proper indentation and naming styles
In-code documentation
### Non-standard C++ libraries
##### <conio.h>
Prepare to connect with peripheral functions and keep console panel.
