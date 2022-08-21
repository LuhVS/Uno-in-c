Luan Victor da Silva Rodrigues - Estrutura de Dados
The game was codded by me but the rules are mostly from the game UNO with a crucial change, now it's supposed to be a single-player game.

If you don't know how to play here's a quick guide:

Rules:
The game starts with a random card in the center
you can:
1. Place a card from your hand.
2. Draw a card from the Draw pile.
3. Skip your turn
.
1. Placing a card
	When you choose to place a card it must be a valid one, which means it has to have the same color or value as the center card, if it's a special card things can change.

1. b. Special cards
	If you place a BLOCK CARD or REVERSE CARD, the next player will lose its turn (you are the next player, I'm almost sure it's a single-player game).
	If you place a PLUS-CARD, the next player will have to draw the number after PLUS-... (probably you), you want to avoid having those.
	IF you place a CHANGE COLOR CARD, you can choose the color for the next card you'll place.

2. Drawing cards
	Every time you draw a card you lose 1 health point in this version, you die if you lost all your 13 life points. 
	Draw a card means you have to know one more card. 
	If you don't have a valid card to place, drawing is the only choice.

3. Skipping your turn
	You skip your turn to the next player (you, it is mostly a single-player game)

0. Secret Ending
	The game source has an API called secret ending, you can find out what it does by winning the game and placing the last card as a Yellow 6 (I don't know why, but this card keeps coming back so it's not that difficult). 
	