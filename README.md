# PIC10CSpring2020Assignment1
- The program is a straight forward game of "siete y medio" where the interface is in spanish in order to better cater to the target demographic where as the code is mostly in english to make it more universally readable
- The game ends once the player loses al of their money (starting at 100) or when the house/dealer loses 900 total
- game records are recorded to a gamelog.txt file
 - git finished get english rank
 - git finished get english suit
- git games are now properly recorded to gamelog file
- git player no longer allowed to play with 0 in bank
- git fixed case where player would not win when CPU busted
- git gave player busting highest priority of loss
- git added win/lose declaration to help player keep track
- git added showhand function for hand object to shorten code
- git consolidated file writing to gamelog at the end of each round to shorten code
- git added reset hand member function to clear hand
- git assigned proper 1/2 value to jack, horse and king cards
- git CPU always draws at least 1 card
- git added statements to indicate the game is over
- git added gamenumber int counter to keep track of games played
- git added lower and upper case to hit option
- git player always drawys at least 1 card per game
- git CPU draws while their total hnd value is less than 5.5
- git added case in event of a tie
