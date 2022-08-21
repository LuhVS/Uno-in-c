// Luan Rodrigues
// Atencao: as anotacoes valem para o codigo abaixo delas ou ao lado

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"
#include "iteradorLista.h"
#include "secretEnding.h"

typedef struct{
  int id;
  int specialValue;
  char color;
  int value;
} card;

void settingTable(card table[]){
  int id = 0;
  
  //red cards
  for(int i = 0; i < 10; i++){
    if (i == 0){
      table[id].specialValue = 0;
      table[id].color = 'R';
      table[id].value = i;
      table[id].id = id; id++;
    } 
    if (i > 0){
      table[id].specialValue = 0;
      table[id].color = 'R';
      table[id].value = i;
      table[id].id = id; id++;

      table[id].specialValue = 0;
      table[id].color = 'R';
      table[id].value = i;
      table[id].id = id; id++;
    }
  }
  //yellow cards
  for(int i = 0; i < 10; i++){
    if (i == 0){
      table[id].specialValue = 0;
      table[id].color = 'Y';
      table[id].value = i;
      table[id].id = id; id++;
    } 
    if (i > 0){
      table[id].specialValue = 0;
      table[id].color = 'Y';
      table[id].value = i;
      table[id].id = id; id++;

      table[id].specialValue = 0;
      table[id].color = 'Y';
      table[id].value = i;
      table[id].id = id; id++;
      }
    }
  //grean cards
  for(int i = 0; i < 10; i++){
    if (i == 0){
      table[id].specialValue = 0;
      table[id].color = 'G';
      table[id].value = i;
      table[id].id = id; id++;
    } 
    if (i > 0){
      table[id].specialValue = 0;
      table[id].color = 'G';
      table[id].value = i;
      table[id].id = id; id++;

      table[id].specialValue = 0;
      table[id].color = 'G';
      table[id].value = i;
      table[id].id = id; id++;
      }
    }
  //blue cards
  for(int i = 0; i < 10; i++){
    if (i == 0){
      table[id].specialValue = 0;
      table[id].color = 'B';
      table[id].value = i;
      table[id].id = id; id++;
    } 
    if (i > 0){
      table[id].specialValue = 0;
      table[id].color = 'B';
      table[id].value = i;
      table[id].id = id; id++;

      table[id].specialValue = 0;
      table[id].color = 'B';
      table[id].value = i;
      table[id].id = id; id++;
      }
    }

  for(int special = 1; special < 4; special++){
    /*
    special 1: block 
    special 2: plus 2 
    sepcial 3: reserse
    */
    
    //2 red
    for(int i = 0; i < 2; i++){
    table[id].specialValue = special;
    table[id].color = 'R';
    table[id].value = -1;
    table[id].id = id; id++;
    }
    
    //2 yellow
    for(int i = 0; i < 2; i++){
    table[id].specialValue = special;
    table[id].color = 'Y';
    table[id].value = -1;
    table[id].id = id; id++;
    }

    //2 green
    for(int i = 0; i < 2; i++){
      table[id].specialValue = special;
      table[id].color = 'G';
      table[id].value = -1;
      table[id].id = id; id++;
    }
    
    //2 blue
    for(int i = 0; i < 2; i++){
      table[id].specialValue = special;
      table[id].color = 'B';
      table[id].value = -1;
      table[id].id = id; id++;
    }
  }
  
  //+4 cards change color (sepcial value 4)
  for(int i = 0; i< 4; i++){
    table[id].specialValue = 4;
    table[id].color = 0;
    table[id].value = -1;
    table[id].id = id; id++;
  }

  //change color cards (special value 5)
  for(int i = 0; i< 4; i++){
    table[id].specialValue = 5;
    table[id].color = 0;
    table[id].value = -1;
    table[id].id = id; id++;
  }
}

void showTable(card table[]){
  for (int i = 0; i < 108; i++)
  printf("%c %i %i\n", 
    table[i].color, table[i].value, table[i].specialValue);
}

void showCard(card card){
  if(card.specialValue){
    switch (card.specialValue){
      case (1): printf("Reverse-card"); break;
      case (2): printf("Plus-2"); break;
      case (3): printf("Block"); break;
      case (4): printf("Plus-4"); break;
      case (5): printf("Change-color"); break;   
      }
    printf(" ");
  }
  
  
  if(card.color) {
    switch (card.color){
      case ('R'): printf("Red"); break;
      case ('Y'): printf("Yellow"); break;
      case ('G'): printf("Green"); break;
      case ('B'): printf("Blue"); break;
    }
    
    printf(" ");
  }

  if(card.value != -1)

    printf("%i", card.value);

  printf("\n");

}

unsigned canPlace(card down, card hand, char color){
  if (color)
    down.color = color;
  
  if (!hand.color && hand.specialValue)
    return 1;

  if(hand.color && !hand.specialValue){
    if(down.color && down.specialValue)
      return hand.color == down.color;

    if(down.color && !down.specialValue)
      return hand.color == down.color ||
        hand.value == down.value;
    }

  if(hand.color && hand.specialValue){
      if(down.color && down.specialValue)
      return hand.color == down.color||
        hand.specialValue == down.specialValue||
        (hand.specialValue == 2 && down.specialValue == 4)||
        (hand.specialValue == 4 && down.specialValue == 2); 
  

    if(down.color && !down.specialValue)
      return hand.color == down.color||
        hand.specialValue == down.specialValue;
  }
    
  
} 

void swap(int vector[], int i, int j){
  int temp = vector[i];
  vector[i] = vector[j];
  vector[j] = temp;
}

void Start(lista* dPlayer, pilha* dBuy){
  int vector[108], value = 0, n = 108;
  
  for (int i = 0; i < 108; i++){
    vector[i] = value;
    value ++;
  } 

  srand (time(NULL));

  for (int i = n - 1; i > 0; i--){
    // pega um indice aleatorio de 0 a 1
    int j = rand() % (i + 1);
 
    // troca arr[i] com o elemento
    // com endereço aleatorio
    swap(vector, i, j);
  }

  int i;
  for (i = 0 ; i < 7; i++)
   inserirFinalLista(dPlayer, vector[i]); 

  for(i = 7; i < 108; i++)
  empilhar(dBuy, vector[i]);
}

void showDeck(card table[], lista* l){
  card card;
  int counter = 1;
 for(iteradorLista i = primeiro(l); !acabou(&i); proximo(&i)){
   card = table[i.posicao->valor];
   printf("%i.", counter); counter++;
   showCard(card);
 }
  printf("\n");
}

void showPile(card table[], pilha* p){
  card card;
  
  while(!pilhaVazia(p)){
    card = table[desempilhar(p)];
    showCard(card);      
  }

  printf("\n");
}

card selectCard(card table[], lista deck, unsigned p){
  iteradorLista it = procurarPosicao(&deck, p);
  card card = table[it.posicao->valor];
  return card;
}

void removeCard(card table[], lista deck, unsigned p){
  iteradorLista it = procurarPosicao(&deck, p);
  removerElemento(&it);
}


void specialEvent(card card, unsigned* jump, unsigned* buy, char* color){
  switch (card.specialValue){
    case(0): break; //normal card
    case(1): *jump = 1; break; //block card
    case(2): *buy = *buy + 2; break; //plus-2 card
    case(3): *jump = 1; break; //reverse card
    case(4): //plus-4 change color card
      *buy = *buy + 4;
      printf("next color (R, Y, G or B): ");
      scanf(" %c", color);
      break;
    case(5): //change color card
      printf("next color (R, Y, G or B): ");
      scanf(" %c", color);
      break;
    }
}

void draw(lista* deck, pilha* draw, unsigned n){
  int id;
  for (int i = 0; i < n; i++){
    id = desempilhar(draw);
    inserirFinalLista(deck, id);
  }
}

unsigned canSaveDraw(card table[], card card1, lista* centerDeck){
  iteradorLista it;
  card center;
  
  if(!card1.specialValue)
    return 0;

  if (card1.specialValue == 2 || card1.specialValue == 4)
    return 1;

  if(card1.specialValue == 1 || card1.specialValue == 3){
    it = ultimo(centerDeck);
    center = table[it.posicao->valor];

    return card1.color = center.color;
  }

  return 0;
}

int main(void) {
  card table[109]; // every card id will represent a card inside this table
  card cardHand, cardDown; // temporary cards
  iteradorLista it; 
  int choice; // to save temporary player imput
  unsigned endGame, playerTurn; // flags for turns
  unsigned jump, drawN; // flags for special events
  char color; // flag for special event
  
  //piles and dacks just hold card id:
  pilha drawPile; 
  lista playerDeck, centerDeck;

  //gonna add a player health value just for fun
  //player lost 1 health when draws a card
  int playerHealth;
  
  //setting one id for every card inside table
  settingTable(table);

  //creadting empty decks and pile
  inicializarLista(&playerDeck);
  inicializarLista(&centerDeck);
  inicializarPilha(&drawPile);
  
  //getting cards id inside decks and pile
  Start(&playerDeck, &drawPile); // 7 for each deck, rest draw

  //getting the center card on top
  cardDown = table[desempilhar(&drawPile)];        
  inserirFinalLista(&centerDeck, cardDown.id);

  //the game starts with no special event
  endGame = jump = drawN = 0;
  color = '\0';

  playerHealth = 13;
  
  //loping while player has cards or until they die
  while(!endGame){
    if(listaVazia(&playerDeck) || !playerHealth)
      break; //ends game loop;

    //1.draw-card event if needed
    if (drawN){
      while(1){ //loop while player selects invalid choices

        printf("Health: %i\n", playerHealth);
        showDeck(table, &playerDeck);
        printf("Do you have something to help you?(1-yes or 0-no)");
        scanf("%i", &choice);

        if (choice == 1){ //players says they hava a card to avoid draw
        printf("select a card:");
        scanf("%i", &choice);
          //wrong card position entered:
          if((choice > playerDeck.quantidade || choice <= 0) && choice != -1)
            printf("You cannot do this >:C!\n");
          
            //right card position entered:
          else if(choice > 0 && choice <= playerDeck.quantidade){
            cardHand = selectCard(table, playerDeck, choice-1);

            //right card position and card can save player from draw:
            if(canSaveDraw(table, cardHand, &centerDeck)){
              //moving card from playerDeck to center
              inserirFinalLista(&centerDeck, cardHand.id);
              removeCard(table, playerDeck, choice-1);
              specialEvent(cardHand, &jump, &drawN, &color);
              
              break;//exiting draw event looping
            } 
            else{  //card cannot save player
              printf("This can't help you >:)\n");
              
              printf("player draws %i cards \n", drawN);
              draw(&playerDeck, &drawPile, drawN);
             

              printf("-%i life points\n", drawN);
              playerHealth -= drawN;
              
              drawN = 0;
              
              break; //exiting draw event looping
            }
          }  
        }
 
      if (choice == 0){ //players says they dont hava a card to avoid draw
        draw(&playerDeck, &drawPile, drawN);

        printf("player draws %i cards\n", drawN);
              draw(&playerDeck, &drawPile, drawN);
        
        printf("-%i life points\n", drawN);
              playerHealth -= drawN;
        drawN = 0;
        break;
      }
    } //loop ends
    
    }//draw-card event ends

    //2.jump event if needed
    if(jump){
      printf("You don't play this time >:D\n");
      jump = 0;
    }
      
    // loop while player select invaid choices 
    else while (1){ 
      // saving center card
      it = ultimo(&centerDeck);
      cardDown = table[it.posicao->valor];

      printf("Health: %i\n", playerHealth);
      
      // showing center card and status
      printf("center card: ");
      showCard(cardDown);
      if(color)
        printf("Chosen color: %c\n", color);

      // showing player card
      printf("Your cards:\n");
      showDeck(table, &playerDeck);

      // asking and geting player's choose
      printf("Which card place (0 to jump, -1 to draw)?: ");
      scanf(" %i", &choice);
      
      // chose skip turn
      if (!choice) break; //finish player turn

      // chose draw 1 card
      if (choice == -1){
        draw(&playerDeck, &drawPile, 1);
        printf("player draws %i cards\n", 1);
              draw(&playerDeck, &drawPile, 1);
        
        printf("-%i life points\n", 1);
              playerHealth -= 1; 
        break;
        }
      // chose a invalid number
      if((choice > playerDeck.quantidade || choice <= 0) && choice != -1)
        printf("You cannot do this >:C!\n");

      // chose a card from his deck
      if(choice > 0 && choice <= playerDeck.quantidade){
        cardHand = selectCard(table, playerDeck, choice-1);

        // chosen card can't be placed
        if (!canPlace(cardDown, cardHand, color))
          printf("You cannot do this >:C!\n");

        // chosen card can be placed:
        else{
          // moving card from player deck to center
          inserirFinalLista(&centerDeck, cardHand.id);
          removeCard(table, playerDeck, choice-1);
          color = '\0';//color back to default

          // Aplying special efect from chosen card if needed
          if (cardHand.specialValue && !jump)
            specialEvent(cardHand, &jump, &drawN, &color);

          break; //finishs player turn
        }
      }
    }
    printf("\n");

    if (listaVazia(&playerDeck)){
      printf("Congradulations! You Won a uno match against yourself!\n<(>_<)>\n");
      
      //Show secret ending only if player wins with the last card placed being a yellow 6
      if(cardHand.color == 'Y' && cardHand.value == 6){
        secretEnding(choice);

      return 0;
    }
    }
      
    if (playerHealth<=0){
      printf("GAME OVER!\n");
      printf("You die :> in a card game\n(X_X)\n");
      return 0;
}
}
}


