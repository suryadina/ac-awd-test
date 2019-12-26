#include<stdio.h>
#include<conio.h>

//program pembuktian bahwa (A XOR B)+C != A XOR B + C != A XOR (B+C)

main()
{
      unsigned long A,B,C;
      A = 0X12345678;
      B = 0X87654321;
      C = 0X11223344;
      
      printf("A = %08lX\n",A);
      printf("B = %08lX\n",B);
      printf("C = %08lX\n",C);
      printf("A XOR B = %08lX\n", A^B);
      printf("B + C = %08lX\n", B+C);
      printf("(A XOR B)+C = %08lX\n", (A^B)+C);
      printf("A XOR B + C = %08lX\n", A^B+C);
      printf("A XOR (B+C) = %08lX\n", A^(B+C));
      
      getch();
}
