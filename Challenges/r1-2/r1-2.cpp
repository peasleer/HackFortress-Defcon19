
#include <stdio.h>
#include <string.h>

/* Solvable with the 'strings' utility and some guessing,
   or with a disassembler in less than a minute. */

/* Random passwords taken from '500 worst passwords of all time' and the
   movie "Hackers." */

char a[16] = "god";
char b[16] = "sex";
char c[16] = "love";
char d[16] = "secret";
char e[16] = "password";
char f[16] = "123456";
char g[16] = "pussy";
char h[16] = "12345";
char i[16] = "qwerty";
char j[16] = "dragon";
char k[16] = "696969";
char l[16] = "letmein";
char m[16] = "shadow";
char n[16] = "abc123";
char o[16] = "monkey";
char p[16] = "constant";
char q[16] = "injected";
char r[16] = "pass";
char s[16] = "fuckme";
char t[16] = "knight";
char u[16] = "iceman";
char v[16] = "maverick";
char w[16] = "voyager";
char x[16] = "diablo";
char y[16] = "panther";
char z[16] = "yamaha";


int main(int argc, char** argv)
{
   printf("[ H A C K | F O R T R E S S ]\n\n");

   printf("Please enter the password: ");

   char buf[32];
   fgets( buf, 32, stdin );

   if( strcmp( buf, strcat(o, "\n")) == 0)
   {
      printf("You got it! Submit the password you entered to the scoreboard!\n");
      return 0;
   }
   else
   {
      printf("Try again...\n");
      return 1;
   }

}
