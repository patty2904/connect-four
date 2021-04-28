/* Patrycja Chrzaszcz
Last modified: 28/04/2021
Connect four game in C */

#include <stdio.h>
#include<stdbool.h>  
#include <string.h>
#include <stdlib.h>

char board[6][7];

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
      printf("You cannot place your token here.\n");
      exit(0);
    } else {
    board[verticalBoard][horizontalBoard] = character;
    break;
    }
}
while (!((verticalBoard + 1) > 5));

  }
  else {
    printf("You cannot place your token here.\n");
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
    printf("You cannot place your token here.\n");
    break; 
  }
  printf("Horizontal position: ");
  scanf("%d", &horizontalPosition);
  if (horizontalPosition > 6 || horizontalPosition < 0){
    printf("You cannot place your token here.\n");
    break; 
  }
  populateBoard(verticalPosition, horizontalPosition, firstPlayer);
  }
  else if (i % 2 == 0)
  {
  printf("%c, What move do you want to make?  \n", secondPlayer);
  printf("Vertical position: ");
  scanf("%d", &verticalPosition);
  if (verticalPosition > 5 || verticalPosition < 0){
    printf("You cannot place your token here.\n");
    break; 
  }
  printf("Horizontal position: ");
  scanf("%d", &horizontalPosition);
   if (horizontalPosition > 6 || horizontalPosition < 0){
    printf("You cannot place your token here.\n");
    break; 
  }
  populateBoard(verticalPosition, horizontalPosition, secondPlayer);
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
