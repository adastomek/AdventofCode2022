/*going through file, adding each calorie until a blank line is reached. comparing it with the previous calorie total*/

#include <stdio.h>
#include <stdlib.h>

#define STRLEN 10

void fopenchk(FILE* file);
long tolong(FILE* file);
long elvecals(FILE* file);
long mostcals(FILE* file);

int main()
{
   /* maybe make this an argv instead for input file */

   FILE* calfile = fopen("input.txt", "r");
   fopenchk(calfile);
   printf("%ld\n", mostcals(calfile));
   fclose(calfile); 
}

/* better with a test function */

void fopenchk(FILE* file)
{
   if (file == NULL){
      fprintf(stderr, "Error reading file");
      exit(EXIT_FAILURE);
   }
}
long tolong(FILE* file)
{
   char s[STRLEN];
   if (fgets(s, STRLEN, file) == NULL){
      return -1;
   }
   return strtol(s, NULL, 10);
}

long elvecals(FILE* file)
{
   long calories = tolong(file);
   long toadd = tolong(file);
   
   if (toadd == -1){
      return 0;
   }

   while (toadd != 0){
      calories += toadd;
      toadd = tolong(file);      
   }
   return calories;
}

long mostcals(FILE* file)
{
   long curr_elve;
   long most = 0;
   while ((curr_elve = elvecals(file)) != 0){
      if (curr_elve > most){
         most = curr_elve;
      }
   }
   return most;
}
