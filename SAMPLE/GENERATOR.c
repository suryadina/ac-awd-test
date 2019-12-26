/*
Sample generator

This program will generate random samples to be used as plaintext/key
for the block cipher

-ardya suryadinata-
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
      FILE *sampel;
      char file_sampel[] = "SAMPEEEL.txt";
      int I,sum;
      unsigned Bibit;
      
      if((sampel=fopen(file_sampel,"w"))==NULL) printf("gagal membuat file");
      printf("Berapa bibit angka randomnya (0-65535)? ");
      scanf("%u",&Bibit);
      printf("Masukkan jumlah sampel yang ingin dibangkitkan = ");
      scanf("%i",&sum);
      
      srand(Bibit);
      for(I=1;I<=sum;I++) fprintf(sampel,"%04x%04x%04x%04x\n",rand(),rand(),rand(),rand());
      getch();
      fclose(sampel);
}
