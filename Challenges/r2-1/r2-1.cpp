
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char **argv )
{
   printf("[ H A C K | F O R T R E S S ]\n\n");

   if( argc < 4 )
   {
      printf("Usage: %s arg1 arg2 arg3\n", argv[0]);
      printf("\tGet all arguments correct to win.\n");
      return 1;
   }

   if( strcmp( "learn", argv[1] ) == 0 )
      if( atoi( argv[2] ) == 2 )
         if( strcmp( "burn", argv[3] ) == 0 )
         {
            printf(
               "You win! Submit this string to the scorboard: %s %s %s\n", 
               argv[1], argv[2], argv[3] );
            return 0;
         }
        
      
   

   printf("Try again...");

   return 0;

}