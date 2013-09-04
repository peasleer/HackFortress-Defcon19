
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

char map[] = "abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ,'";

int main(int argc, char **argv)
{
   printf("\n[ H A C K | F O R T R E S S ]\n\n");

   char mapped[28];

   mapped[8] = map[23];
   mapped[9] = map[61];
   mapped[10] = map[20];

   mapped[16] = map[0];
   mapped[17] = map[20];
   mapped[18] = map[13];

   mapped[24] = map[6];
   mapped[25] = map[19];
   mapped[26] = 'n';
   mapped[27] = '\0';

   unsigned char _debug = false;

   _asm
   {
      push eax
      push edx

      xor eax, eax
      xor edx, edx

      // Get linear address of PEB
      mov eax, fs:[30h]

      // PEB + 2 -> BeingDebugged
      mov dl, [eax+2]
      mov _debug, dl

      pop edx
      pop eax
      
   }

   mapped[19] = map[16];
   mapped[20] = map[8];
   mapped[21] = map[18];
   mapped[22] = map[4];
   mapped[23] = map[61];

   if(_debug)
   {
      printf("Don't debug me, bro! (Try harder)\n");

      mapped[7] = map[16];
      mapped[5] = map[23];
      mapped[9] = map[61];

      return 1;
   }

   FILE* f = fopen( "C:\\HackFortress", "r" );

   mapped[11] = map[4];
   mapped[12] = map[16];
   mapped[13] = map[23];
   mapped[14] = map[61];
   mapped[15] = map[5];

   if( f == 0 )
   {
      mapped[13] = map[17];
      mapped[11] = map[61];
      mapped[19] = map[12];

      printf("I guess you just don't have what I'm looking for\n");
      return 2;
   }

   char buf[21];
   buf[20] = '\0';
   unsigned int read = fread(buf, sizeof(char), 20, f);

   mapped[3] = map[61];
   mapped[4] = map[8];
   mapped[5] = map[17];
   mapped[6] = map[61];
   mapped[7] = map[12];

   if( read <= 0 )
   {
      
      mapped[9] = map[17];
      mapped[3] = map[7];
      mapped[15] = map[4];

      printf("You are kind of half-assing it -_-\n");
      return 3;
   }

   fclose(f);

   mapped[0] = map[17];
   mapped[1] = map[7];
   mapped[2] = map[4];

   if( strcmp( buf, "pwned the challenge!" ) == 0 )
   {
      printf("You win! Submit the following string for the win:\n\n\t%s\n", mapped);

      mapped[0] = map[12];
      mapped[1] = map[9];
      mapped[2] = map[26];

      return 0;
   }
   else
   {
      printf("A kitten dies every time you get this wrong\n");
      return 4;
   }

}
