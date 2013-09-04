
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ,'\"";

int main( int argc, char **argv )
{
    char mapped[47];
    mapped[3] = map[8];
    mapped[4] = map[13];
    mapped[5] = map[4];
    mapped[6] = map[4];
    mapped[0] = map[30];
    mapped[10] = map[18];
    mapped[11] = map[19];
    mapped[12] = map[17];
    mapped[28] = map[17];
    mapped[29] = map[3];
    mapped[30] = map[22];
    mapped[31] = map[0];
    mapped[32] = map[17];
    mapped[33] = map[4];
    mapped[34] = map[62];
    mapped[35] = map[1];
    mapped[36] = map[17];
    mapped[37] = map[4];
    mapped[38] = map[0];
    mapped[39] = map[10];
    mapped[40] = map[15];
    mapped[41] = map[14];
    mapped[42] = map[8];
    mapped[43] = map[13];
    mapped[44] = map[19];
    mapped[45] = map[18];
    mapped[46] = '\0';


   printf("[ H A C K | F O R T R E S S ]\n\n");

   // Check for debug registers, if none set,
   // lose. If DR0 set, win.

   CONTEXT cxt;
   HANDLE thread = GetCurrentThread();

    mapped[1] = map[13];
    mapped[2] = map[6];

    mapped[7] = map[17];
    mapped[8] = map[18];
    mapped[9] = map[62];

   cxt.ContextFlags = CONTEXT_DEBUG_REGISTERS;

   GetThreadContext(thread, &cxt);
    
   mapped[21] = map[4];
   mapped[22] = map[5];
   mapped[23] = map[4];
   mapped[24] = map[17];
   mapped[25] = map[62];
   mapped[26] = map[7];
   mapped[27] = map[0];
   mapped[13] = map[14];    
   mapped[14] = map[13];
   mapped[15] = map[6];
   mapped[16] = map[11];
   mapped[17] = map[24];
   mapped[18] = map[62];
   mapped[19] = map[15];
   mapped[20] = map[17];


   int i;

   for( i = 0; i < 4; i++ )
   {
      if(( cxt.Dr7 & ( 1 << ( i*2 ))) != 0 )
      {
         break;
      }
   }

   // They set a hw bp, win
   if( i < 3 )
   {
      printf("You win! Submit the following string:\n\n\t%s\n\n", mapped );
      return 0;
   }

   // No hardware breakpoint, fail
   printf("Be more leet, try again!\n");
   return 1;
}