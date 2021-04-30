/* Patrycja Chrzaszcz
Last modified: 28/04/2021
Connect four game in C */

#include <stdio.h>
#include<stdbool.h>  
#include <string.h>
#include <stdlib.h>

char board[6][7];
char stack1[];
char stack2[];
int count = 0;
int count2 = 0;

void pushStack1(board)
{
  int rest = stack1[count];
  rest = board;
  count++;
}

char popStack1()
{
char rest = stack1[count - 1];
count--;
return rest;
}

void pushStack2()
{
  char rest = stack2[count];
  rest = stack1[count - 1];
  count2++;
}

char popStack2()
{
  char rest = stack2[count2 - 1];
  rest = stack1[count + 1];
  count2--;
  return rest;

}


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

int checkDiagonalQ1 (vertical, horizontal, character){
  if ((vertical >= 0 && vertical <= 5) && (horizontal >= 0 && horizontal <= 6) && (board[vertical][horizontal] == character))
  {
    return checkDiagonalQ1(vertical + 1, horizontal + 1, character);
  }
}

int checkDiagonalQ2 (vertical, horizontal, character){
  if ((vertical >= 0 && vertical <= 5) && (horizontal >= 0 && horizontal <= 6) && (board[vertical][horizontal] == character))
  {
    return checkDiagonalQ2(vertical + 1, horizontal - 1, character);
  }
}

int checkDiagonalQ3 (vertical, horizontal, character){
  if ((vertical >= 0 && vertical <= 5) && (horizontal >= 0 && horizontal <= 6) && (board[vertical][horizontal] == character))
  {
    return checkDiagonalQ3(vertical - 1, horizontal + 1, character);
  }
}

int checkDiagonalQ4 (vertical, horizontal, character){
  if ((vertical >= 0 && vertical <= 5) && (horizontal >= 0 && horizontal <= 6) && (board[vertical][horizontal] == character))
  {
    return checkDiagonalQ4(vertical - 1, horizontal - 1, character);
  }
}

void checkDiagonals(character)
{
  for (int i = 0; i < 6; i ++){
    for (int j = 0; j < 7; j++){
      int count = checkDiagonalQ1(i, j, character);
      count+= checkDiagonalQ4(i, j, character);

      int count2 = checkDiagonalQ2(i, j, character); 
      count2+= checkDiagonalQ3(i, j, character);

      if(count>=5 || count2>=5)
				{
          printf("Player %c has won!\n", character);
          exit(0);
        }
    }
  }
}


void populateBoard(verticalBoard, horizontalBoard, player)
{
  int flag = 1;
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
else if (firstPlayer == 'R')
secondPlayer = 'Y';
else{
printf("This character is not valid.");
  exit(0);
}

int i = 1;
while (i < 43)
{ 
  int verticalPosition = 0;
  int horizontalPosition= 0;
  int flag = 1;
  char redo = 'N';

  if (i % 2 != 0){
  do{
  printf("%c, What move do you want to make?  \n", firstPlayer);
  printf("Vertical position: ");
  scanf("%d", &verticalPosition);
  printf("Horizontal position: ");
  scanf("%d", &horizontalPosition);
  if ((horizontalPosition <= 6 && horizontalPosition >= 0) || (verticalPosition <= 5 && verticalPosition >= 0)){
    flag = 2;
  }
  printf("This position does not exist.\n");
  }
  while (flag == 1);
  populateBoard(verticalPosition, horizontalPosition, firstPlayer);
  pushStack1(board);
  checkHorizontal(verticalPosition, horizontalPosition, firstPlayer);
  checkVertical(verticalPosition, horizontalPosition, firstPlayer);
  checkDiagonals(firstPlayer);

  printf("Do you wish to undo this move? (Y or N)");
  scanf("%c", &redo);
  if (redo == 'Y'){
    pushStack2();
    popStack1();
  }
  }



  else if (i % 2 == 0)
  {
    do{
  printf("%c, What move do you want to make?  \n", secondPlayer);
  printf("Vertical position: ");
  scanf("%d", &verticalPosition);
  printf("Horizontal position: ");
  scanf("%d", &horizontalPosition);
  if ((horizontalPosition <= 6 && horizontalPosition >= 0) || (verticalPosition <= 5 && verticalPosition >= 0)){
    flag = 2;
  }
   printf("This position does not exist.\n");
  }
  while (flag == 1);
  populateBoard(verticalPosition, horizontalPosition, secondPlayer);
  pushStack1(board);
  checkHorizontal(verticalPosition, horizontalPosition, secondPlayer);
  checkVertical(verticalPosition, horizontalPosition, secondPlayer);
  checkDiagonals(secondPlayer);

  printf("Do you wish to undo this move? (Y or N)");
  scanf("%c", &redo);
  if (redo == 'Y'){
    pushStack2();
    popStack1();
  }
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
