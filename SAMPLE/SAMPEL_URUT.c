/*
Sample generator

This program will generate incremental samples to be used as plaintext/key
for the block cipher

-ardya suryadinata-
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main()
{
      FILE *sampel;
      char file_sampel[] = "SAMPEL URUT.txt";
      unsigned long I,sum,x,y=0;
      
      if((sampel=fopen(file_sampel,"w"))==NULL) printf("gagal membuat file");
      printf("Berapa ukuran sampel? (64-128) ");
      scanf("%u",&x);
      printf("Masukkan jumlah sampel yang ingin dibangkitkan? (<(2^32))");
      scanf("%i",&sum);
      
      if(x==64) for(I=1;I<=sum;I++) fprintf(sampel,"%08x%08x\n",y,I);
      else for(I=1;I<=sum;I++) fprintf(sampel,"%08x%08x%08x%08x\n",y,y,y,I);
      printf("selesai");
      getch();
      fclose(sampel);
}
