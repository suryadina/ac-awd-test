/*
18 december 2011

Pembangkit difference Algoritma TEA:
SELURUH POSISI PERUBAHAN SECARA OTOMATIS

Difference calculator for TEA algorithm

Ardya Suryadinata
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>


//ALGORITMA TEA
void code(long* v, long* k)
{
     unsigned long y=v[0], z=v[1], sum=0, //set up
     delta=0x9e3779b9, /* a key schedule constant */
     n=32 ;
     while (n-->0) 
     { /* basic cycle start */
          sum += delta ;
          y += ((z<<4)+k[0]) ^ (z+sum) ^ ((z>>5)+k[1]) ;
          z += ((y<<4)+k[2]) ^ (y+sum) ^ ((y>>5)+k[3]) ;
     } /* end cycle */
     v[0]=y ; v[1]=z ; 
}
//SELESAI ALGORITMA TEA

//MAIN UNTUK PEMBUATAN PASANGAN
main()
{ 
  //mulai deklarasi seed=seed random, x=counter
  unsigned int seed, jumlah_sample, x, xx,xxx;
  unsigned long cipherteks[2], cipherteks1[2], plainteks[2], plainteks1[2], e=0x1,difference[2], v[2], v_ASLI[2];
  char nama_file[50],nama_file2[50], urutanfile[5];//nama_file diperoleh dari input. nama file2 itu untuk nyimpen yang udah di edit2
  FILE *fsample, *fdifference;
  //selesai deklarasi
  
  //DEKLARASI KUNCI TEA
  unsigned long kunci[4] = {0,0,0,0}, k[4];
  //SELESAI DEKLARASI KUNCI TEA  
  //minta input file sample dan kunci untuk mini aes
  printf("Masukkan nama file sample\n");
  scanf("%s",nama_file);
  strcat(nama_file,".txt");
  printf("Masukkan jumlah sample yang digunakan\n");
  scanf("%i", &jumlah_sample);
  
  for(xxx=0;xxx<64;xxx++)
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
              
              //selesai membuka file output
              //membaca isi file sample dan membuat difference
              for(x=0;x<jumlah_sample;x++)
              {
                  for(xx=0;xx<2;xx++)
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
                  
                  v[0] = v_ASLI[0];//mengubah posisi plainteks
                  v[1] = v_ASLI[1];//mengubah posisi plainteks
                  code(v,k);
              
                  for(xx=0;xx<2;xx++)
                  {cipherteks[xx] = v[xx];}
                  //SELESAI ENKRIPSI
                  
                  //ENKRIPSI SETELAH PLAINTEKS DIUBAH
                  if(xxx<32) 
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
                  
                  k[0] = kunci[0];
                  k[1] = kunci[1];
                  k[2] = kunci[2];
                  k[3] = kunci[3];
                  
                  v[0] = v_ASLI[0];//mengubah posisi plainteks
                  v[1] = v_ASLI[1];//mengubah posisi plainteks
                  code(v,k);
              
                  
                  for(xx=0;xx<2;xx++)
                  {cipherteks1[xx] = v[xx];}
                  //SELESAI ENKRIPSI
                  
                  for(xx=0;xx<2;xx++)
                  {
                                     difference[xx] = cipherteks[xx]^cipherteks1[xx];//membuat difference
                                     fprintf(fdifference,"%08x", difference[xx]);//menulis difference dan pasangan ke file
                  }
                  fprintf(fdifference,"\n");
              }
              //menutup file output
              fclose(fsample);
              fclose(fdifference);
  }
  printf("PROSES PEMBANGKITAN DIFFERENCE SUDAH SELESAI");
  getch();
}
//SELESAI BAGIAN PEMBANGKIT PASANGAN
