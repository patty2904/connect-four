/* Patrycja Chrzaszcz
Last modified: 22/04/2021
Connect four game in C */

#include <stdio.h>
#include<stdbool.h>  
#include <string.h>

int main(void) {

char boardd[6][7] = {
    {'-','-', '-', '-', '-', '-', '-', },
    {'-','-', '-', '-', '-', '-', '-', },
    {'-','-', '-', '-', '-', '-', '-', },
    {'-','-', '-', '-', '-', '-', '-', },
    {'-','-', '-', '-', '-', '-', '-', },
    {'-','-', '-', '-', '-', '-', '-', }
};

char board[6][7];

for (int i = 0; i < 6; i ++){
  for (int j = 0; j < 7; j++){
    board[i][j] = '-';
  }
}

int alph = 17;
printf("%s", "  1 2 3 4 5 6 7\n");
for (int i = 0; i < 6; i ++){
    printf("%c ", alph + '0'); 
    alph++;
  for (int j = 0; j < 7; j++){
    printf("%c%s", board[i][j], " ");
    if(j==6){
    printf("\n");
    }
    }
  }


  return 0;
}

/* SOURCES

*/
