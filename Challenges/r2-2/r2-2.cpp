
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "shared.h"

char map[] = "abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ,'\"";
char mapped[36];



int main( int argc, char **argv )
{
   mapped[0] = map[18];
   mapped[1] = map[7];
   mapped[2] = map[8];
   mapped[3] = map[17];
   mapped[4] = map[61];
   mapped[5] = map[8];
   mapped[6] = map[17];
   mapped[7] = map[4];
   mapped[8] = map[63];
   mapped[9] = map[18];
   mapped[10] = map[61];
   mapped[11] = map[8];
   mapped[12] = map[18];
   mapped[13] = map[61];
   mapped[14] = map[18];
   mapped[15] = map[7];
   mapped[16] = map[8];
   mapped[17] = map[17];
   mapped[18] = map[61];
   mapped[19] = map[8];
   mapped[20] = map[17];
   mapped[21] = map[4];
   mapped[22] = map[63];
   mapped[23] = map[18];
   mapped[24] = map[61];
   mapped[25] = map[8];
   mapped[26] = map[18];
   mapped[27] = map[61];
   mapped[28] = map[18];
   mapped[29] = map[7];
   mapped[30] = map[8];
   mapped[31] = map[17];
   mapped[32] = map[61];
   mapped[33] = map[8];
   mapped[34] = map[17];

   printf("[ H A C K | F O R T R E S S ]\n\n");

   HKEY out;
   int result;

   result = RegOpenKeyEx( HKEY_LOCAL_MACHINE, "SOFTWARE\\HackFortress", NULL, KEY_QUERY_VALUE, &out );

   if( result != ERROR_SUCCESS )
   {  
      mapped[33] = map[5];
      mapped[34] = map[4];
      mapped[35] = map[4];
      printf("I guess you just don't have what I'm looking for.\n");
      return 1;


   }

   mapped[0] = map[49];
   mapped[1] = map[13];
   mapped[2] = map[19];
   mapped[3] = map[61];
   mapped[4] = map[7];
   mapped[5] = map[0];
   mapped[6] = map[3];
   mapped[7] = map[61];
   mapped[8] = map[18];
   mapped[9] = map[13];
   mapped[10] = map[61];
   mapped[11] = map[2];
   mapped[12] = map[16];
   mapped[13] = map[4];
   mapped[14] = map[0];
   mapped[15] = map[18];
   mapped[16] = map[4];
   mapped[17] = map[61];
   mapped[18] = map[0];
   mapped[19] = map[61];
   mapped[20] = map[10];
   mapped[21] = map[4];
   mapped[22] = map[23];
   mapped[23] = map[61];
   mapped[24] = map[18];
   mapped[25] = map[13];
   mapped[26] = map[61];
   mapped[27] = map[6];
   mapped[28] = map[4];
   mapped[29] = map[18];
   mapped[30] = map[61];
   mapped[31] = map[0];
   mapped[32] = map[61];
   mapped[33] = map[10];
   mapped[34] = map[4];
   mapped[35] = map[23];

   printf("You win! Sumbit the following string:\n\t%s\n", mapped);

   RegCloseKey( out );
   
   return 0;

}