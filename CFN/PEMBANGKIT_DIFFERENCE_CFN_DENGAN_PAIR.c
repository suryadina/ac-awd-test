/*
18 desember 2011
Pembangkit difference Algoritma CFN:
SELURUH POSISI PERUBAHAN SECARA OTOMATIS

Difference calculator with pair for CFN algorithm

Ardya Suryadinata

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>

//ALGORITMA CFN
unsigned long CFN(unsigned long* v, unsigned long* K)
{
      unsigned long sum=0,delta=0x9e3779b9;
      int i, j, indexK, maxK=8, jumlahCycle=1;
      for(i=1;i<=jumlahCycle;i++)
      {
                                sum+=delta;

                                K[0]^=(((K[1]<<4)^(K[2]>>5))^(sum+K[3]));
                                K[1]^=(((K[2]<<4)^(K[3]>>5))^(sum+K[4]));
                                K[2]^=(((K[3]<<4)^(K[4]>>5))^(sum+K[5]));
                                K[3]^=(((K[4]<<4)^(K[5]>>5))^(sum+K[6]));
                                K[4]^=(((K[5]<<4)^(K[6]>>5))^(sum+K[7]));
                                K[5]^=(((K[6]<<4)^(K[7]>>5))^(sum+K[0]));
                                K[6]^=(((K[7]<<4)^(K[0]>>5))^(sum+K[1]));
                                K[7]^=(((K[0]<<4)^(K[1]>>5))^(sum+K[2]));

                                v[0]+=(((((v[1]<<4)+K[0])^K[5])+(sum^(v[3]>>5)))^sum);
                                v[2]+=(((((v[3]<<4)+K[2])^K[7])+(sum^(v[1]>>5)))^sum);
                                v[1]+=(((((v[2]<<4)+K[1])^K[4])+(sum^(v[0]>>5)))^sum);
                                v[3]+=(((((v[0]<<4)+K[3])^K[6])+(sum^(v[2]>>5)))^sum);
      }
}
//SELESAI ALGORITMA CFN

//MAIN UNTUK PEMBUATAN PASANGAN
main()
{ 
  //mulai deklarasi seed=seed random, x=counter
  unsigned int seed, jumlah_sample, x, xx,xxx;
  unsigned long cipherteks[4], cipherteks1[4], plainteks[4], plainteks1[4], e=0x1,difference[4], v[4], v_ASLI[4];
  char nama_file[50],nama_file2[50],nama_file3[50], urutanfile[5];//nama_file diperoleh dari input. nama file2 itu untuk nyimpen yang udah di edit2
  FILE *fsample, *fdifference, *fpair;
  //selesai deklarasi
  
  //DEKLARASI KUNCI TEA
  unsigned long kunci[8]={0x0000000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000}, k[8];
  //SELESAI DEKLARASI KUNCI TEA  
  //minta input file sample dan kunci untuk mini aes
  printf("Masukkan nama file sample\n");
  scanf("%s",nama_file);
  strcat(nama_file,".txt");
  printf("Masukkan jumlah sample yang digunakan\n");
  scanf("%i", &jumlah_sample);
  
  for(xxx=0;xxx<128;xxx++)
  {
                        
              //membuka file nama_file sebagai sample
              if((fsample=fopen(nama_file,"r"))==NULL)
              {
                  printf("Tidak dapat membuka file %s ",fsample);
                  exit(0);
              }
              
              //membuka file nama_file.difference.txt sebagai file output difference
              itoa(xxx+1,urutanfile,10);
              strcpy(nama_file2, nama_file);
              strcat(nama_file2, "_");
              strcat(nama_file2, urutanfile);
              strcat(nama_file2, ".Different");
              if((fdifference=fopen(nama_file2,"w"))==NULL)
              {
                  printf("Tidak dapat membuat file %s ",fdifference);
                  exit(0);
              }
              //membuka file nama_file.pair.txt sebagai file output pasangan2 ptx dan ctx
              strcpy(nama_file3, nama_file);
              strcat(nama_file3, "_");
              strcat(nama_file3, urutanfile);
              strcat(nama_file3, ".Pair");
              if((fpair=fopen(nama_file3,"w"))==NULL)
              {
                  printf("Tidak dapat membuat file %s ",fpair);
                  exit(0);
              }
              
              //selesai membuka file output
              //membaca isi file sample dan membuat difference
              for(x=0;x<jumlah_sample;x++)
              {
                  for(xx=0;xx<4;xx++)
                  {
                                     fscanf(fsample,"%08x",&plainteks[xx]);
                                     v_ASLI[xx] = plainteks[xx];
                                     plainteks1[xx] = plainteks[xx];
                  }//membaca isi file sample
                  
                  //ENKRIPSI SEBELUM PLAINTEKS DIUBAH
                  k[0] = kunci[0];
                  k[1] = kunci[1];
                  k[2] = kunci[2];
                  k[3] = kunci[3];
                  k[4] = kunci[4];
                  k[5] = kunci[5];
                  k[6] = kunci[6];
                  k[7] = kunci[7];
                  
                  v[0] = v_ASLI[0];//mengubah posisi plainteks
                  v[1] = v_ASLI[1];//mengubah posisi plainteks
                  v[2] = v_ASLI[2];//mengubah posisi plainteks
                  v[3] = v_ASLI[3];//mengubah posisi plainteks
                  
                  CFN(v,k);
              
                  for(xx=0;xx<4;xx++)
                  {cipherteks[xx] = v[xx];}
                  //SELESAI ENKRIPSI
                  
                  //ENKRIPSI SETELAH PLAINTEKS DIUBAH
                  if(xxx<32) 
                  {
                             v_ASLI[3] = v_ASLI[3] ^ (e << xxx);
                             plainteks1[3] = v_ASLI[3];
                             v[3]= plainteks1[3];//membuat plainteks'
                  }
                  else  
                  {
                             if(xxx<64)
                             {
                                       v_ASLI[2] = v_ASLI[2] ^ (e << xxx);
                                       plainteks1[2] = v_ASLI[2];
                                       v[2]= plainteks1[2];//membuat plainteks'
                             }
                             else
                             {
                                 if(xxx<96)
                                 {
                                           v_ASLI[1] = v_ASLI[1] ^ (e << xxx);
                                           plainteks1[1] = v_ASLI[1];
                                           v[1]= plainteks1[1];//membuat plainteks'
                                 }
                                 else
                                 {
                                     v_ASLI[0] = v_ASLI[0] ^ (e << xxx);
                                     plainteks1[0] = v_ASLI[0];
                                     v[0]= plainteks1[0];//membuat plainteks'
                                 }
                             }
                  }
                  
                  k[0] = kunci[0];
                  k[1] = kunci[1];
                  k[2] = kunci[2];
                  k[3] = kunci[3];
                  k[4] = kunci[4];
                  k[5] = kunci[5];
                  k[6] = kunci[6];
                  k[7] = kunci[7];
                  
                  v[0] = v_ASLI[0];//mengubah posisi plainteks
                  v[1] = v_ASLI[1];//mengubah posisi plainteks
                  v[2] = v_ASLI[2];//mengubah posisi plainteks
                  v[3] = v_ASLI[3];//mengubah posisi plainteks
                  CFN(v,k);
              
                  for(xx=0;xx<4;xx++)
                  {cipherteks1[xx] = v[xx];}
                  //SELESAI ENKRIPSI
                  
                  for(xx=0;xx<4;xx++)
                  {
                                     difference[xx] = cipherteks[xx]^cipherteks1[xx];//membuat difference
                                     fprintf(fdifference,"%08x", difference[xx]);//menulis difference dan pasangan ke file
                  }
                  fprintf(fdifference,"\n");
                  fprintf(fpair,"%08x%08x%08x%08x %08x%08x%08x%08x %08x%08x%08x%08x %08x%08x%08x%08x %08x%08x%08x%08x\n",
                  plainteks[0], plainteks[1], plainteks[2], plainteks[3],
                  plainteks1[0], plainteks1[1], plainteks1[2], plainteks1[3],
                  cipherteks[0], cipherteks[1], cipherteks[2], cipherteks[3],
                  cipherteks1[0], cipherteks1[1], cipherteks1[2], cipherteks1[3],
                  difference[0], difference[1], difference[2], difference[3]);
              }
              //menutup file output
              fclose(fsample);
              fclose(fpair);
              fclose(fdifference);
  }
  printf("PROSES PEMBANGKITAN DIFFERENCE SUDAH SELESAI");
  getch();
}
//SELESAI BAGIAN PEMBANGKIT PASANGAN
