/* Patrycja Chrzaszcz
Last modified: 28/04/2021
Connect four game in C */

#include <stdio.h>
#include<stdbool.h>  
#include <string.h>
#include <stdlib.h>

char board[6][7];

void checkHorizontal(verticalBoard, horizontalBoard, character)
{
  //FOR MIDDLE PIECES
  //vertical must stay the same
  //check that horizontal + 1 = player token
  //AND horizontal - 1 = player token
  //so long as horizontal not <= 0 or not => 6
  //then do check that horizontal + 2 = player token
  //OR horizontal - 2 = player token
  if (horizontalBoard > 0 && horizontalBoard < 6)
  {
    if(
    (board[verticalBoard][horizontalBoard + 1] == character) &&
    (board[verticalBoard][horizontalBoard - 1] == character) )
      {
      if ( 
        (board[verticalBoard][horizontalBoard + 2] == character) ||
        (board[verticalBoard][horizontalBoard - 2] == character) )
        {
      printf("Player %c has won!\n", character);
      exit(0);
        }
      }
  

  else if(
    (board[verticalBoard][horizontalBoard - 1] == character) 
    &&
    (board[verticalBoard][horizontalBoard - 2] == character) 
    &&
    (board[verticalBoard][horizontalBoard - 3] == character) )
    {
    printf("Player %c has won!\n", character);
   exit(0);
    }

    else if(
    (board[verticalBoard][horizontalBoard + 1] == character) 
    &&
    (board[verticalBoard][horizontalBoard + 2] == character) 
    &&
    (board[verticalBoard][horizontalBoard + 3] == character) )
    {
    printf("Player %c has won!\n", character);
   exit(0);
    }
  }
  else if(horizontalBoard == 0) {
    if(
    (board[verticalBoard][horizontalBoard + 1] == character) 
    &&
    (board[verticalBoard][horizontalBoard + 2] == character) 
    &&
    (board[verticalBoard][horizontalBoard + 3] == character) )
    {
    printf("Player %c has won!\n", character);
    exit(0);
    }
  }
  

  else if(horizontalBoard == 6) {
     if(
    (board[verticalBoard][horizontalBoard - 1] == character) 
    &&
    (board[verticalBoard][horizontalBoard - 2] == character) 
    &&
    (board[verticalBoard][horizontalBoard - 3] == character) )
    {
    printf("Player %c has won!\n", character);
   exit(0);
    }
  } 
}



void checkVertical(verticalBoard, horizontalBoard, character)
{
if (verticalBoard > 0 && verticalBoard < 5)
  {
    if(
    (board[verticalBoard + 1][horizontalBoard] == character) &&
    (board[verticalBoard - 1][horizontalBoard] == character) )
      {
      if ( 
        (board[verticalBoard + 2][horizontalBoard] == character) ||
        (board[verticalBoard - 2][horizontalBoard] == character) )
        {
      printf("Player %c has won!\n", character);
      exit(0);
        }
      }
  

  else if(
    (board[verticalBoard - 1][horizontalBoard] == character) 
    &&
    (board[verticalBoard - 2][horizontalBoard] == character) 
    &&
    (board[verticalBoard - 3][horizontalBoard] == character) )
    {
    printf("Player %c has won!\n", character);
   exit(0);
    }

    else if(
    (board[verticalBoard + 1][horizontalBoard] == character) 
    &&
    (board[verticalBoard + 2][horizontalBoard] == character) 
    &&
    (board[verticalBoard + 3][horizontalBoard] == character) )
    {
    printf("Player %c has won!\n", character);
   exit(0);
    }
  }
  else if(verticalBoard == 0) {
    if(
    (board[verticalBoard + 1][horizontalBoard] == character) 
    &&
    (board[verticalBoard + 2][horizontalBoard] == character) 
    &&
    (board[verticalBoard + 3][horizontalBoard] == character) )
    {
    printf("Player %c has won!\n", character);
    exit(0);
    }
  }
  

  else if(horizontalBoard == 5) {
     if(
    (board[verticalBoard - 1][horizontalBoard] == character) 
    &&
    (board[verticalBoard - 2][horizontalBoard] == character) 
    &&
    (board[verticalBoard - 3][horizontalBoard] == character) )
    {
    printf("Player %c has won!\n", character);
   exit(0);
    }
  } 
}

void checkDiagonal (verticalBoard, horizontalBoard, player){
  
}


void populateBoard(verticalBoard, horizontalBoard, player)
{
  char character = ' ';
  if (player == 'Y'){
    character = 'Y';
  } else {
    character = 'R';
  }

  if (board[verticalBoard][horizontalBoard] == '-') {
do{
if(board[verticalBoard + 1][horizontalBoard] == '-'){
      printf("You cannot place a token if there is space below.\n");
      exit(0);
    } else {
    board[verticalBoard][horizontalBoard] = character;
    break;
    }
}
while (!((verticalBoard + 1) > 5));

  }
  else {
    printf("Something is already in this position.\n");
  }
  
  int vertNum = 0;
  printf("%s", "  0 1 2 3 4 5 6\n");
    for (int i = 0; i < 6; i ++){
      printf("%d ", vertNum); 
      vertNum++;
    for (int j = 0; j < 7; j++){
      printf("%c%s", board[i][j], " ");
      if(j==6){
      printf("\n");
      }
      }
      }
}


int main(void) {

int temp = 1;

if (temp == 1){
  for (int i = 0; i < 6; i ++){
  for (int j = 0; j < 7; j++){
    board[i][j] = '-';
  }
}

int vertNum = 0;
  printf("%s", "  0 1 2 3 4 5 6\n");
    for (int i = 0; i < 6; i ++){
      printf("%d ", vertNum); 
      vertNum++;
    for (int j = 0; j < 7; j++){
      printf("%c%s", board[i][j], " ");
      if(j==6){
      printf("\n");
      }
      }
      }     
}

printf("Vertical position is first, horizontal position is second.");
char firstPlayer;
char secondPlayer;
printf("Who goes first? (Y for Yellow or R for Red).");
scanf("%c", &firstPlayer);

if (firstPlayer == 'Y')
  secondPlayer = 'R';
else 
secondPlayer = 'Y';

int i = 1;
while (i < 43)
{ 
  int verticalPosition = 0;
  int horizontalPosition= 0;
  if (i % 2 != 0){
  printf("%c, What move do you want to make?  \n", firstPlayer);
  printf("Vertical position: ");
  scanf("%d", &verticalPosition);
  if (verticalPosition > 5 || verticalPosition < 0){
    printf("This position does not exist.\n");
    break; 
  }
  printf("Horizontal position: ");
  scanf("%d", &horizontalPosition);
  if (horizontalPosition > 6 || horizontalPosition < 0){
    printf("This position does not exist.\n");
    break; 
  }
  populateBoard(verticalPosition, horizontalPosition, firstPlayer);
  checkHorizontal(verticalPosition, horizontalPosition, firstPlayer);
  checkVertical(verticalPosition, horizontalPosition, firstPlayer);
  }

  else if (i % 2 == 0)
  {
  printf("%c, What move do you want to make?  \n", secondPlayer);
  printf("Vertical position: ");
  scanf("%d", &verticalPosition);
  if (verticalPosition > 5 || verticalPosition < 0){
    printf("This position does not exist.\n");
    break; 
  }
  printf("Horizontal position: ");
  scanf("%d", &horizontalPosition);
   if (horizontalPosition > 6 || horizontalPosition < 0){
    printf("This position does not exist.\n");
    break; 
  }
  populateBoard(verticalPosition, horizontalPosition, secondPlayer);
  checkHorizontal(verticalPosition, horizontalPosition, secondPlayer);
  checkVertical(verticalPosition, horizontalPosition, secondPlayer);

  }
  else {
    printf("Something went wrong...");
  }
  i++;
}
  temp = 0;
  return 0;
}

// char boardd[6][7] = {
//   // 0,0  0,1  0,2
//     {'-','-', '-', '-', '-', '-', '-', },
//     {'-','-', '-', '-', '-', '-', '-', },
//     {'-','-', '-', '-', '-', '-', '-', },
//     {'-','-', '-', '-', '-', '-', '-', },
//     {'-','-', '-', '-', '-', '-', '-', },
//     {'-','-', '-', '-', '-', '-', '-', }
// };

/* SOURCES

*/
