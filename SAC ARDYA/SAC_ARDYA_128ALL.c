/*
10 JANUARI 2012
Perhitungan SAC ARDYA SURYADINATA

128-bit block algorithm Strict Avalanche Criterion (SAC) Test
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
  unsigned int x, xx, xxx, xxxx, jumlah_sample, jumlah_bit_satu;
  char nama_file[50],nama_file2[50], urutanfile[10], nama_file3[50];//nama_file diperoleh dari input. nama file2 itu untuk nyimpen yang udah di edit2
  FILE *fdifference, *fsac;
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
  unsigned int sac_128[128];
  
  //minta input file different
  printf("Masukkan nama file sample yang tadinya digunakan\n");
  scanf("%s",nama_file);
  strcat(nama_file,".txt");
  printf("Masukkan Jumlah sample\n");
  scanf("%i",&jumlah_sample);
  
  //membuka file nama_file.awd.txt sebagai file output uji AWD                        
  strcpy(nama_file2, "");
  strcpy(nama_file2, nama_file);
  strcat(nama_file2,".SAC");
  if((fsac=fopen(nama_file2,"w"))==NULL)
  {
             printf("Tidak dapat membuat file %s ",fsac);
             getch();
             exit(0);
  }
  else {printf("sukses membuka file = %s\n",nama_file2);}
  
  //selesai membuka file output
              
  for(xxx=0;xxx<128;xxx++)//diulang sejumlah posisi perubahan bit i yang memungkinkan
  {
                          printf("xxx = %i\n",xxx);
                          for(x=0;x<128;x++)//menginisiasi avalanche sum array dengan nilai 0
                          {sac_128[x]=0;}
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
                          else {printf("sukses membuka file = %s\n",nama_file3);}
                          
                          //membaca isi file difference
                          for(x=0;x<jumlah_sample;x++)//diulang sejumlah sampel yang digunakan 
                          {
                              //mulai menghitung avalanche sum array
                              for(xx=0;xx<4;xx++)//diulang sebanyak empat kali karena ukuran blok adalah 128 dan kemampuan sekali menyimpan hanya 32 bit
                              {
                                                 
                                          if(xx==3)
                                          {
                                                      fscanf(fdifference,"%08x\n",&Nilai_difference.difference);
                                                      sac_128[96] += Nilai_difference.biner.Bit0;
                                                      sac_128[97] += Nilai_difference.biner.Bit1;
                                                      sac_128[98] += Nilai_difference.biner.Bit2;
                                                      sac_128[99] += Nilai_difference.biner.Bit3;
                                                      sac_128[100] += Nilai_difference.biner.Bit4;
                                                      sac_128[101] += Nilai_difference.biner.Bit5;
                                                      sac_128[102] += Nilai_difference.biner.Bit6;
                                                      sac_128[103] += Nilai_difference.biner.Bit7;
                                                      
                                                      sac_128[104] += Nilai_difference.biner.Bit8;
                                                      sac_128[105] += Nilai_difference.biner.Bit9;
                                                      sac_128[106] += Nilai_difference.biner.Bit10;
                                                      sac_128[107] += Nilai_difference.biner.Bit11;
                                                      sac_128[108] += Nilai_difference.biner.Bit12;
                                                      sac_128[109] += Nilai_difference.biner.Bit13;
                                                      sac_128[110] += Nilai_difference.biner.Bit14;
                                                      sac_128[111] += Nilai_difference.biner.Bit15;
                                                      
                                                      sac_128[112] += Nilai_difference.biner.Bit16;
                                                      sac_128[113] += Nilai_difference.biner.Bit17;
                                                      sac_128[114] += Nilai_difference.biner.Bit18;
                                                      sac_128[115] += Nilai_difference.biner.Bit19;
                                                      sac_128[116] += Nilai_difference.biner.Bit20;
                                                      sac_128[117] += Nilai_difference.biner.Bit21;
                                                      sac_128[118] += Nilai_difference.biner.Bit22;
                                                      sac_128[119] += Nilai_difference.biner.Bit23;
                                                      
                                                      sac_128[120] += Nilai_difference.biner.Bit24;
                                                      sac_128[121] += Nilai_difference.biner.Bit25;
                                                      sac_128[122] += Nilai_difference.biner.Bit26;
                                                      sac_128[123] += Nilai_difference.biner.Bit27;
                                                      sac_128[124] += Nilai_difference.biner.Bit28;
                                                      sac_128[125] += Nilai_difference.biner.Bit29;
                                                      sac_128[126] += Nilai_difference.biner.Bit30;
                                                      sac_128[127] += Nilai_difference.biner.Bit31;
                                          }//membaca isi file sample
                                          else
                                          {
                                              if(xx==2)
                                              {
                                                      fscanf(fdifference,"%08x",&Nilai_difference.difference);//membaca isi file sample
                                                      sac_128[64] += Nilai_difference.biner.Bit0;
                                                      sac_128[65] += Nilai_difference.biner.Bit1;
                                                      sac_128[66] += Nilai_difference.biner.Bit2;
                                                      sac_128[67] += Nilai_difference.biner.Bit3;
                                                      sac_128[68] += Nilai_difference.biner.Bit4;
                                                      sac_128[69] += Nilai_difference.biner.Bit5;
                                                      sac_128[70] += Nilai_difference.biner.Bit6;
                                                      sac_128[71] += Nilai_difference.biner.Bit7;
                                                      
                                                      sac_128[72] += Nilai_difference.biner.Bit8;
                                                      sac_128[73] += Nilai_difference.biner.Bit9;
                                                      sac_128[74] += Nilai_difference.biner.Bit10;
                                                      sac_128[75] += Nilai_difference.biner.Bit11;
                                                      sac_128[76] += Nilai_difference.biner.Bit12;
                                                      sac_128[77] += Nilai_difference.biner.Bit13;
                                                      sac_128[78] += Nilai_difference.biner.Bit14;
                                                      sac_128[79] += Nilai_difference.biner.Bit15;
                                                      
                                                      sac_128[80] += Nilai_difference.biner.Bit16;
                                                      sac_128[81] += Nilai_difference.biner.Bit17;
                                                      sac_128[82] += Nilai_difference.biner.Bit18;
                                                      sac_128[83] += Nilai_difference.biner.Bit19;
                                                      sac_128[84] += Nilai_difference.biner.Bit20;
                                                      sac_128[85] += Nilai_difference.biner.Bit21;
                                                      sac_128[86] += Nilai_difference.biner.Bit22;
                                                      sac_128[87] += Nilai_difference.biner.Bit23;
                                                      
                                                      sac_128[88] += Nilai_difference.biner.Bit24;
                                                      sac_128[89] += Nilai_difference.biner.Bit25;
                                                      sac_128[90] += Nilai_difference.biner.Bit26;
                                                      sac_128[91] += Nilai_difference.biner.Bit27;
                                                      sac_128[92] += Nilai_difference.biner.Bit28;
                                                      sac_128[93] += Nilai_difference.biner.Bit29;
                                                      sac_128[94] += Nilai_difference.biner.Bit30;
                                                      sac_128[95] += Nilai_difference.biner.Bit31;
                                              }
                                              else
                                              {
                                                  if(xx==1)
                                                  {
                                                          fscanf(fdifference,"%08x",&Nilai_difference.difference);//membaca isi file sample
                                                          sac_128[32] += Nilai_difference.biner.Bit0;
                                                          sac_128[33] += Nilai_difference.biner.Bit1;
                                                          sac_128[34] += Nilai_difference.biner.Bit2;
                                                          sac_128[35] += Nilai_difference.biner.Bit3;
                                                          sac_128[36] += Nilai_difference.biner.Bit4;
                                                          sac_128[37] += Nilai_difference.biner.Bit5;
                                                          sac_128[38] += Nilai_difference.biner.Bit6;
                                                          sac_128[39] += Nilai_difference.biner.Bit7;
                                                          
                                                          sac_128[40] += Nilai_difference.biner.Bit8;
                                                          sac_128[41] += Nilai_difference.biner.Bit9;
                                                          sac_128[42] += Nilai_difference.biner.Bit10;
                                                          sac_128[43] += Nilai_difference.biner.Bit11;
                                                          sac_128[44] += Nilai_difference.biner.Bit12;
                                                          sac_128[45] += Nilai_difference.biner.Bit13;
                                                          sac_128[46] += Nilai_difference.biner.Bit14;
                                                          sac_128[47] += Nilai_difference.biner.Bit15;
                                                          
                                                          sac_128[48] += Nilai_difference.biner.Bit16;
                                                          sac_128[49] += Nilai_difference.biner.Bit17;
                                                          sac_128[50] += Nilai_difference.biner.Bit18;
                                                          sac_128[51] += Nilai_difference.biner.Bit19;
                                                          sac_128[52] += Nilai_difference.biner.Bit20;
                                                          sac_128[53] += Nilai_difference.biner.Bit21;
                                                          sac_128[54] += Nilai_difference.biner.Bit22;
                                                          sac_128[55] += Nilai_difference.biner.Bit23;
                                                          
                                                          sac_128[56] += Nilai_difference.biner.Bit24;
                                                          sac_128[57] += Nilai_difference.biner.Bit25;
                                                          sac_128[58] += Nilai_difference.biner.Bit26;
                                                          sac_128[59] += Nilai_difference.biner.Bit27;
                                                          sac_128[60] += Nilai_difference.biner.Bit28;
                                                          sac_128[61] += Nilai_difference.biner.Bit29;
                                                          sac_128[62] += Nilai_difference.biner.Bit30;
                                                          sac_128[63] += Nilai_difference.biner.Bit31;
                                                  }
                                                  else
                                                  {
                                                          fscanf(fdifference,"%08x",&Nilai_difference.difference);//membaca isi file sample
                                                          sac_128[0] += Nilai_difference.biner.Bit0;
                                                          sac_128[1] += Nilai_difference.biner.Bit1;
                                                          sac_128[2] += Nilai_difference.biner.Bit2;
                                                          sac_128[3] += Nilai_difference.biner.Bit3;
                                                          sac_128[4] += Nilai_difference.biner.Bit4;
                                                          sac_128[5] += Nilai_difference.biner.Bit5;
                                                          sac_128[6] += Nilai_difference.biner.Bit6;
                                                          sac_128[7] += Nilai_difference.biner.Bit7;
                                                          
                                                          sac_128[8] += Nilai_difference.biner.Bit8;
                                                          sac_128[9] += Nilai_difference.biner.Bit9;
                                                          sac_128[10] += Nilai_difference.biner.Bit10;
                                                          sac_128[11] += Nilai_difference.biner.Bit11;
                                                          sac_128[12] += Nilai_difference.biner.Bit12;
                                                          sac_128[13] += Nilai_difference.biner.Bit13;
                                                          sac_128[14] += Nilai_difference.biner.Bit14;
                                                          sac_128[15] += Nilai_difference.biner.Bit15;
                                                          
                                                          sac_128[16] += Nilai_difference.biner.Bit16;
                                                          sac_128[17] += Nilai_difference.biner.Bit17;
                                                          sac_128[18] += Nilai_difference.biner.Bit18;
                                                          sac_128[19] += Nilai_difference.biner.Bit19;
                                                          sac_128[20] += Nilai_difference.biner.Bit20;
                                                          sac_128[21] += Nilai_difference.biner.Bit21;
                                                          sac_128[22] += Nilai_difference.biner.Bit22;
                                                          sac_128[23] += Nilai_difference.biner.Bit23;
                                                          
                                                          sac_128[24] += Nilai_difference.biner.Bit24;
                                                          sac_128[25] += Nilai_difference.biner.Bit25;
                                                          sac_128[26] += Nilai_difference.biner.Bit26;
                                                          sac_128[27] += Nilai_difference.biner.Bit27;
                                                          sac_128[28] += Nilai_difference.biner.Bit28;
                                                          sac_128[29] += Nilai_difference.biner.Bit29;
                                                          sac_128[30] += Nilai_difference.biner.Bit30;
                                                          sac_128[31] += Nilai_difference.biner.Bit31;
                                                  }
                                              }
                                          }
                              }
                          }
                          for(xxxx=0;xxxx<128;xxxx++) fprintf(fsac,"%i ",sac_128[xxxx]);
                          fprintf(fsac,"\n");
                          fclose(fdifference);
  }
  fclose(fsac);
  printf("\nSELESAI");
  getch();
}
//SELESAI AWD
