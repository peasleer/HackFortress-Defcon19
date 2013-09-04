
#include <stdio.h>
#include <string.h>

/* Solvable with the 'strings' utility or equivalent. */

int main(int argc, char** argv)
{
   printf("[ H A C K | F O R T R E S S ]\n\n");

   printf("Please enter the password: ");

   char buf[32];
   fgets( buf, 32, stdin );

   if( strcmp( buf, "it gets harder\n") == 0)
   {
      printf("\n\nYou got it! Submit the password you entered to the scoreboard!\n");
      return 0;
   }
   else
   {
      printf("\n\nTry again...\n");
      return 1;
   }

}
