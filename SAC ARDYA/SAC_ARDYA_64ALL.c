/*
10 JANUARI 2012
Perhitungan SAC ARDYA SURYADINATA

Strict Avalanche Criterion (SAC) Test

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
  unsigned int x, xx, xxx, xxxx, jumlah_bit_satu;
  char nama_file[50],nama_file2[50], urutanfile[10], nama_file3[50];//nama_file diperoleh dari input. nama file2 itu untuk nyimpen yang udah di edit2
  FILE *fdifference, *fsac, *fpersen;
  struct Bit{
         unsigned Bit31: 1;
         unsigned Bit30: 1;
         unsigned Bit29: 1;
         unsigned Bit28: 1;
         unsigned Bit27: 1;
         unsigned Bit26: 1;
         unsigned Bit25: 1;
         unsigned Bit24: 1;
         unsigned Bit23: 1;
         unsigned Bit22: 1;
         unsigned Bit21: 1;
         unsigned Bit20: 1;
         unsigned Bit19: 1;
         unsigned Bit18: 1;
         unsigned Bit17: 1;
         unsigned Bit16: 1;
         unsigned Bit15: 1;
         unsigned Bit14: 1;
         unsigned Bit13: 1;
         unsigned Bit12: 1;
         unsigned Bit11: 1;
         unsigned Bit10: 1;
         unsigned Bit9: 1;
         unsigned Bit8: 1;
         unsigned Bit7: 1;
         unsigned Bit6: 1;
         unsigned Bit5: 1;
         unsigned Bit4: 1;
         unsigned Bit3: 1;
         unsigned Bit2: 1;
         unsigned Bit1: 1;
         unsigned Bit0: 1;
  };
  union{
        unsigned long difference;
        struct Bit biner;
  }Nilai_difference;
  int sac_64[64], jumlah_sample;
  
  //minta input file different
  printf("Masukkan nama file sample yang tadinya digunakan\n");
  scanf("%s",nama_file);
  strcat(nama_file,".txt");
  printf("Masukkan Jumlah sample\n");
  scanf("%i",&jumlah_sample);
  
  //membuka file nama_file.sac.txt sebagai file output uji AWD                        
  strcpy(nama_file2, "");
  strcpy(nama_file2, nama_file);
  strcat(nama_file2,".SAC");
  if((fsac=fopen(nama_file2,"w"))==NULL)
  {
             printf("Tidak dapat membuat file %s ",fsac);
             getch();
             exit(0);
  }
  //else {printf("sukses membuka file = %s\n",nama_file2);}
  
  //selesai membuka file output            
  for(xxx=0;xxx<64;xxx++)//diulang sebanyak 64 kali sesuai dengan jumlah posisi perubahan bit i yang mungkin
  {
                          printf("xxx = %i\n",xxx);
                          for(x=0;x<64;x++)//membuat avalanche sum array dan mengisinya dengan nilai 0
                          {sac_64[x]=0;}
                          Nilai_difference.difference = 0;
                          //selesai deklarasi
                          
                          //membuka file nama_file sebagai input difference yang akan dihitung
                          strcpy(nama_file3, "");
                          itoa(xxx+1,urutanfile,10);
                          strcpy(nama_file3, nama_file);
                          strcat(nama_file3, "_");
                          strcat(nama_file3, urutanfile);
                          strcat(nama_file3, ".Different");
                          
                          //mengecek apakah file dapat dibuka
                          if((fdifference=fopen(nama_file3,"r"))==NULL)
                          {
                              printf("Tidak dapat membuka file %s ",fdifference);
                              getch();
                              exit(0);
                          }
                          //else {printf("sukses membuka file = %s\n",nama_file3);}
                          
                          //membaca isi file difference
                          for(x=0;x<jumlah_sample;x++)//diulang sejumlah sampel yang digunakan 
                          {
                              //printf("\n%i ", x);    
                              for(xx=0;xx<2;xx++)//diulang dua kali karena ukuran block 64 bit dan sekali membaca hanya bisa 32 bit
                              {
                              //bagian ini menghitung nilai array avalanche sum
                                          if(xx==1)
                                          {
                                                      fscanf(fdifference,"%08x\n",&Nilai_difference.difference);
                                                      sac_64[32] += Nilai_difference.biner.Bit0;
                                                      sac_64[33] += Nilai_difference.biner.Bit1;
                                                      sac_64[34] += Nilai_difference.biner.Bit2;
                                                      sac_64[35] += Nilai_difference.biner.Bit3;
                                                      sac_64[36] += Nilai_difference.biner.Bit4;
                                                      sac_64[37] += Nilai_difference.biner.Bit5;
                                                      sac_64[38] += Nilai_difference.biner.Bit6;
                                                      sac_64[39] += Nilai_difference.biner.Bit7;
                                                      
                                                      sac_64[40] += Nilai_difference.biner.Bit8;
                                                      sac_64[41] += Nilai_difference.biner.Bit9;
                                                      sac_64[42] += Nilai_difference.biner.Bit10;
                                                      sac_64[43] += Nilai_difference.biner.Bit11;
                                                      sac_64[44] += Nilai_difference.biner.Bit12;
                                                      sac_64[45] += Nilai_difference.biner.Bit13;
                                                      sac_64[46] += Nilai_difference.biner.Bit14;
                                                      sac_64[47] += Nilai_difference.biner.Bit15;
                                                      
                                                      sac_64[48] += Nilai_difference.biner.Bit16;
                                                      sac_64[49] += Nilai_difference.biner.Bit17;
                                                      sac_64[50] += Nilai_difference.biner.Bit18;
                                                      sac_64[51] += Nilai_difference.biner.Bit19;
                                                      sac_64[52] += Nilai_difference.biner.Bit20;
                                                      sac_64[53] += Nilai_difference.biner.Bit21;
                                                      sac_64[54] += Nilai_difference.biner.Bit22;
                                                      sac_64[55] += Nilai_difference.biner.Bit23;
                                                      
                                                      sac_64[56] += Nilai_difference.biner.Bit24;
                                                      sac_64[57] += Nilai_difference.biner.Bit25;
                                                      sac_64[58] += Nilai_difference.biner.Bit26;
                                                      sac_64[59] += Nilai_difference.biner.Bit27;
                                                      sac_64[60] += Nilai_difference.biner.Bit28;
                                                      sac_64[61] += Nilai_difference.biner.Bit29;
                                                      sac_64[62] += Nilai_difference.biner.Bit30;
                                                      sac_64[63] += Nilai_difference.biner.Bit31;
                                          
                                          }//membaca isi file sample
                                          else
                                          {
                                              fscanf(fdifference,"%08x",&Nilai_difference.difference);//membaca isi file sample
                                          
                                              //printf("%08x",Nilai_difference.difference);
                                              sac_64[0] += Nilai_difference.biner.Bit0;
                                              sac_64[1] += Nilai_difference.biner.Bit1;
                                              sac_64[2] += Nilai_difference.biner.Bit2;
                                              sac_64[3] += Nilai_difference.biner.Bit3;
                                              sac_64[4] += Nilai_difference.biner.Bit4;
                                              sac_64[5] += Nilai_difference.biner.Bit5;
                                              sac_64[6] += Nilai_difference.biner.Bit6;
                                              sac_64[7] += Nilai_difference.biner.Bit7;
                                              
                                              sac_64[8] += Nilai_difference.biner.Bit8;
                                              sac_64[9] += Nilai_difference.biner.Bit9;
                                              sac_64[10] += Nilai_difference.biner.Bit10;
                                              sac_64[11] += Nilai_difference.biner.Bit11;
                                              sac_64[12] += Nilai_difference.biner.Bit12;
                                              sac_64[13] += Nilai_difference.biner.Bit13;
                                              sac_64[14] += Nilai_difference.biner.Bit14;
                                              sac_64[15] += Nilai_difference.biner.Bit15;
                                              
                                              sac_64[16] += Nilai_difference.biner.Bit16;
                                              sac_64[17] += Nilai_difference.biner.Bit17;
                                              sac_64[18] += Nilai_difference.biner.Bit18;
                                              sac_64[19] += Nilai_difference.biner.Bit19;
                                              sac_64[20] += Nilai_difference.biner.Bit20;
                                              sac_64[21] += Nilai_difference.biner.Bit21;
                                              sac_64[22] += Nilai_difference.biner.Bit22;
                                              sac_64[23] += Nilai_difference.biner.Bit23;
                                              
                                              sac_64[24] += Nilai_difference.biner.Bit24;
                                              sac_64[25] += Nilai_difference.biner.Bit25;
                                              sac_64[26] += Nilai_difference.biner.Bit26;
                                              sac_64[27] += Nilai_difference.biner.Bit27;
                                              sac_64[28] += Nilai_difference.biner.Bit28;
                                              sac_64[29] += Nilai_difference.biner.Bit29;
                                              sac_64[30] += Nilai_difference.biner.Bit30;
                                              sac_64[31] += Nilai_difference.biner.Bit31;
                                          }
                              }
                          }
                          for(xxxx=0;xxxx<64;xxxx++) fprintf(fsac,"%i ",sac_64[xxxx]);
                                                                              
                          fprintf(fsac,"\n");
                          fclose(fdifference);
  }
  fclose(fsac);
  printf("\nSELESAI");
  getch();
}
//SELESAI AWD
