
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>


class Secret
{
public:
   Secret()
   {
      LPCSTR name = "HackFortress";
      LPSTR buf[1024];
      int ret = GetEnvironmentVariableA(name, *buf, 1024);

      if( GetLastError() == ERROR_ENVVAR_NOT_FOUND )
      {
         exit( 0 );
      }

      return;
   }
};


Secret secret;

char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ,'";   


int main(int argc, char **argv)
{

   printf("\n[ H A C K | F O R T R E S S ]\n\n");

   char mapped[36];
   bool win = false;

   int argc2 = argc + 5;

   _asm {
            push eax
            push ebx

            xor eax, eax
            xor ebx, ebx
            
            mov ebx, 8009
            mov eax, 5
      start:
            cmp eax, 6
            jnz first
            pop ebp
            ret
      first:
            cmp ebx, 8011
            push second
            ret
            inc ebx
            push start
            ret
            pop ebp
            ret

      second:
            push ss           // Ollydbg 1.x debugger detection. v2 is smart
            pop ss            // enough to not respect push ss/pop ss stuff >:(
            pushf
            pop ax
            and ax, 0x100
            jz notdebugged
            push ss           // Infinite loop of lulz :)
            pop ss            // Again, only effective on Ollydbg 1.x :(
            jmp $-2           
            
      notdebugged:
            cmp argc2, 13
            jnz end
   }
   
   argc2 = atoi(argv[5]); 
   if( argc2 != 11 )
   {
      _asm
      {
         jmp end
      }
   }
         
   mapped[0] = map[19];
   mapped[1] = map[14];
   mapped[2] = map[3];
   mapped[3] = map[0];
   mapped[4] = map[24];
   mapped[5] = map[62];
   mapped[6] = map[24];
   mapped[7] = map[14];
   mapped[8] = map[20];
   mapped[9] = map[62];
   mapped[10] = map[11];
   mapped[11] = map[4];
   mapped[12] = map[0];
   mapped[13] = map[17];
   mapped[14] = map[13];
   mapped[15] = map[4];
   mapped[16] = map[3];
   mapped[17] = map[62];
   mapped[18] = map[14];
   mapped[19] = map[15];
   mapped[20] = map[0];
   mapped[21] = map[16];
   mapped[22] = map[20];
   mapped[23] = map[4];
   mapped[24] = map[62];
   mapped[25] = map[15];
   mapped[26] = map[17];
   mapped[27] = map[4];
   mapped[28] = map[3];
   mapped[29] = map[8];
   mapped[30] = map[2];
   mapped[31] = map[0];
   mapped[32] = map[19];
   mapped[33] = map[4];
   mapped[34] = map[18];
   mapped[35] = '\0';

   _asm
   {
            mov win, 1

      end:
            pop ebx
            pop eax
   }

   if( !win )
   {
      printf("Try again! And be quick, your TF2 team is getting creamed ;)\n");
      return 1;
   }
   


   printf("You win! Submit the following line for the win:\n\t%s\n", mapped);

   return 0;
}