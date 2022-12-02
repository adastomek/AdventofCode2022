#include <stdio.h>
#include <stdlib.h>

#define A_ROCK 'A'
#define A_PAPER 'B'
#define A_SCISSORS 'C'
#define B_ROCK 'X'
#define B_PAPER 'Y'
#define B_SCISSORS 'Z'

#define DRW 'A' - 'X'

#define WIN 6
#define DRAW 3
#define LOSS 0

struct round{
   char a;
   char b;
};
typedef struct round round;

void* file2round(FILE* stratguide, round* rnd);
int round2score(round* curr_round);

int main(void)
{
   FILE* f = fopen("input.txt", "r");
   if (f == NULL){
      fprintf(stderr, "Cannot open file\n"); exit(EXIT_FAILURE);
   }
   
   round rnd; int score = 0; int scoreadd = 0;
   while (file2round(f, &rnd) != NULL){
      scoreadd = round2score(&rnd);
      printf("%d\n", scoreadd);
      score += scoreadd;
   }
   printf("%d\n", score);
}

void* file2round(FILE* stratguide, round* rnd)
{
   if(fscanf(stratguide,"%c %c ", &rnd->a, &rnd->b) == EOF){
      rnd = NULL;
      return NULL;
   }
   return rnd;
}

int round2score(round* curr_round)
{
   int score;
   char oponent = curr_round->a; char played = curr_round->b;
   switch (played){
      case B_ROCK:
         score = 1; break;
      case B_PAPER:
         score = 2; break;
      case B_SCISSORS:
         score = 3; break;
      default:
         fprintf(stderr, "Error with default cases"); exit(EXIT_FAILURE);
   }
   if ((played - oponent) == (B_ROCK - A_ROCK)){
      return score += DRAW;
   }
   if (oponent == A_ROCK && played == B_PAPER){
      return score += WIN;
   }
   if (oponent == A_ROCK && played == B_SCISSORS){
      return score += LOSS;
   }
   if (oponent == A_PAPER && played == B_ROCK){
      return score += LOSS;
   }
   if (oponent == A_PAPER && played == B_SCISSORS){
      return score += WIN;
   }
   if (oponent == A_SCISSORS && played == B_ROCK){
      return score += WIN;
   }
   if (oponent == A_SCISSORS && played == B_PAPER){
      return score += LOSS;
   }

   return 0;
}  
