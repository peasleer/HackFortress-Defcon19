
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


void handler()
{
   int argc = 0;
   _asm
   {
      // Unwind the stack back to this frame
      push 0               // apparently unused value?
      push [ebp+0x08]      // pointer to this exception record
      push after_unwind    // callback addr when after RtlUnwind is done
      push [ebp+0x0C]      // pointer to this stack frame
      call dword ptr RtlUnwind

after_unwind:

      mov esi, [ebp+0x10]     // esi -> CONTEXT structure
      mov edx, [ebp+0x8]      // edx -> EXCEPTION_RECORD structure
      mov eax, [edx+0xC]      // eax -> address of exception root
      add eax, 2              // bypass exception cause
      mov [esi+0xB8], eax     // insert new eip

      mov ebx, [esi+0x94]     // get EBX from the CONTEXT structure
      mov [argc], ebx         

   }

   printf("argc: %d\n", argc);

   if( argc != 10 )
   {
      exit(2);
   }

   _asm
   {
      xor eax, eax            // reload context and continue execution
   }

   return;
}



int main( int argc, char **argv )
{

   printf("\n[ H A C K | F O R T R E S S ]\n\n");

   // Register SEH from a global class,
   // if it is called with the correct integer argument,
   // win.

   if( argc < 2 )
   {
      int i;
      for( i = 0; i < 4; i++ )
      {
         LockWorkStation();
         printf("\tDance party!\n");
         Sleep(1500);
      }
      return 1;
   }


   _asm
   {
      push [handler]       // push address of our handler
      mov eax, dword ptr fs:[0]  // save SEH
      push eax

      mov dword ptr fs:[0], esp  // install our SEH handler

      push ebx             // save ebx

      mov ebx, argc        

      xor eax, eax
      div eax              // trigger exception

      pop ebx              // restore ebx

      pop dword ptr fs:[0] // Restore SEH
      add esp, 0x4         // remove [handler]

   }
   
   char mapped[] = "foo";
   printf("You win! Submit the following string:\n\n\t%s\n", mapped);

   return 0;
}