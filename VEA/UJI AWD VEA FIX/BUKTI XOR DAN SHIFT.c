#include<stdio.h>
#include<conio.h>
//PROGRAM UNTUK MEMBUKTIKAN BAHWA A^B<<5 DAN (A^B)<<5
main()
{
      unsigned int A = 7,B = 5;
      printf("A = %04X\n", A);
      printf("B = %04X\n", B);
      printf("B<<5 = %04X\n", B<<5);
      printf("A^B<<5 = %04X\n", A^B<<5);
      printf("(A^B)<<5 = %04X\n", (A^B)<<5);
      printf("A+B<<5 = %04X\n", A+B<<5);
      printf("A+(B<<5) = %04X\n", A+(B<<5));
      
      getch();
}
