/*
Avalanche Weight Distribution (AWD) Test for 128-bit block cipher

created by ardya suryadinata
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>

//MAIN UNTUK AWD
main()
{ 
  //mulai deklarasi 
  unsigned int x, xx, xxx, jumlah_sample, jumlah_bit_satu;
  char nama_file[50],nama_file2[50], urutanfile[10], nama_file3[50];//nama_file diperoleh dari input. nama file2 itu untuk nyimpen yang udah di edit2
  FILE *fdifference, *fawd;
  struct Bit{
         unsigned Bit0: 1;
         unsigned Bit1: 1;
         unsigned Bit2: 1;
         unsigned Bit3: 1;
         unsigned Bit4: 1;
         unsigned Bit5: 1;
         unsigned Bit6: 1;
         unsigned Bit7: 1;
         unsigned Bit8: 1;
         unsigned Bit9: 1;
         unsigned Bit10: 1;
         unsigned Bit11: 1;
         unsigned Bit12: 1;
         unsigned Bit13: 1;
         unsigned Bit14: 1;
         unsigned Bit15: 1;
         unsigned Bit16: 1;
         unsigned Bit17: 1;
         unsigned Bit18: 1;
         unsigned Bit19: 1;
         unsigned Bit20: 1;
         unsigned Bit21: 1;
         unsigned Bit22: 1;
         unsigned Bit23: 1;
         unsigned Bit24: 1;
         unsigned Bit25: 1;
         unsigned Bit26: 1;
         unsigned Bit27: 1;
         unsigned Bit28: 1;
         unsigned Bit29: 1;
         unsigned Bit30: 1;
         unsigned Bit31: 1;
  };
  union{
        unsigned long difference;
        struct Bit biner;
  }Nilai_difference;
  unsigned int kurva_awd[129];
  
  //minta input file different
  printf("Masukkan nama file sample yang tadinya digunakan\n");
  scanf("%s",nama_file);
  strcat(nama_file,".txt");
  printf("Masukkan Jumlah sample\n");
  scanf("%i",&jumlah_sample);
                          
  //membuka file nama_file.awd.txt sebagai file output uji AWD
  strcpy(nama_file2, "");
  strcpy(nama_file2, nama_file);
  strcat(nama_file2,".AWD");
  if((fawd=fopen(nama_file2,"w"))==NULL)
  {
                                        printf("Tidak dapat membuat file %s ",fawd);
                                        getch();
                                        exit(0);
  }
  else {printf("sukses membuka file = %s\n",nama_file2);}
  //selesai membuka file output
              
  for(xxx=0;xxx<128;xxx++)//perulangan ini untuk membuka file secara berurutan 
  {
                          printf("xxx = %i\n",xxx);//mencetak counter file yang dibuka
                          for(x=0;x<129;x++)
                          {kurva_awd[x]=0;}
                          Nilai_difference.difference = 0;
                          //selesai inisiasi nilai difference dan array AWD
                          
                          //membuka file nama_file sebagai input difference yang akan dihitung
                          strcpy(nama_file3, "");
                          itoa(xxx+1,urutanfile,10);
                          strcpy(nama_file3, nama_file);
                          strcat(nama_file3, "_");
                          strcat(nama_file3, urutanfile);
                          strcat(nama_file3, ".Different");
              
                          //mengecek apakah file different dapat dibuka
                          if((fdifference=fopen(nama_file3,"r"))==NULL)
                          {
                              printf("Tidak dapat membuka file %s ",fdifference);
                              getch();
                              exit(0);
                          }
                          else {printf("sukses membuka file = %s\n",nama_file3);}
                          
                          //membaca isi file difference
                          for(x=0;x<jumlah_sample;x++)//diulang sampai sejumlah sampel yang digunakan
                          {
                              //printf("\n%i ", x);
                              jumlah_bit_satu = 0;//variabel ini isinya bersifat sementara dan digunakan untuk menghitung hamming weight dari vektor avalanche
                              
                              for(xx=0;xx<4;xx++)//diulang sebanyak empat kali karena ukuran blok algoritma adalah 128. sedangkan sekali membaca hanya 32 bit
                              {
                                                 
                                          if(xx==3)
                                          fscanf(fdifference,"%08x\n",&Nilai_difference.difference);//membaca isi file sample
                                          else
                                          fscanf(fdifference,"%08x",&Nilai_difference.difference);//membaca isi file sample
                                          
                                          //printf("%08x",Nilai_difference.difference);
                                          jumlah_bit_satu += Nilai_difference.biner.Bit0 + Nilai_difference.biner.Bit1 + Nilai_difference.biner.Bit2 + Nilai_difference.biner.Bit3 +
                                                            Nilai_difference.biner.Bit4 + Nilai_difference.biner.Bit5 + Nilai_difference.biner.Bit6 + Nilai_difference.biner.Bit7 +
                                                            Nilai_difference.biner.Bit8 + Nilai_difference.biner.Bit9 + Nilai_difference.biner.Bit10 + Nilai_difference.biner.Bit11 +
                                                            Nilai_difference.biner.Bit12 + Nilai_difference.biner.Bit13 + Nilai_difference.biner.Bit14 + Nilai_difference.biner.Bit15+
                                                            Nilai_difference.biner.Bit16 + Nilai_difference.biner.Bit17 + Nilai_difference.biner.Bit18 + Nilai_difference.biner.Bit19 +
                                                            Nilai_difference.biner.Bit20 + Nilai_difference.biner.Bit21 + Nilai_difference.biner.Bit22 + Nilai_difference.biner.Bit23 +
                                                            Nilai_difference.biner.Bit24 + Nilai_difference.biner.Bit25 + Nilai_difference.biner.Bit26 + Nilai_difference.biner.Bit27 +
                                                            Nilai_difference.biner.Bit28 + Nilai_difference.biner.Bit29 + Nilai_difference.biner.Bit30 + Nilai_difference.biner.Bit31;
                              }
                              kurva_awd[jumlah_bit_satu]++;//menambahkan nilai elemen array AWD berdasarkan hamming weight vektor avalanche yang sudah dihitung
                          }
                          //menulis perhitungan awd ke file
                          for (x=0;x<129;x++)
                          {
                              fprintf(fawd,"%i ",kurva_awd[x]);
                          }
                          fprintf(fawd,"\n");
                          //menutup file output
                          fclose(fdifference);
  }
  printf("\nSELESAI");
  fclose(fawd);
  getch();
}
//SELESAI AWD
