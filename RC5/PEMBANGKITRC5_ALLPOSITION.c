/*
18 desember 2011
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

//DEKLARASI RC5 32/16/12
typedef unsigned long int WORD; //SHOULD BE 32 BIT=4 BYTE
#define w 32 //word size in bits
#define r 7 //number of round
#define b 16 //number of bytes in key
#define c 4 //number if word in key
//c=max(1, ceil(8*b/w)
#define t   26 //size of table s=2*(r+t) words
WORD S[t]; //expanded key table
WORD P = 0xb7e15163, Q = 0x9e3779b9; //magic constant
//rotation operation begin
#define ROTL(x,y) (((x)<<(y&(w-1))) | ((x)>>(w-(y&(w-1)))))
#define ROTR(x,y) (((x)>>(y&(w-1))) | ((x)<<(w-(y&(w-1)))))
//rotation end

void RC5_ENCRYPT(WORD *pt, WORD *ct); //2 word input pt dan output ct
void RC5_SETUP(unsigned char *K);//secret input key K[0...b-1]
unsigned char key[b] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned long printword(WORD A); //fungsi print
unsigned long printword_reverse(WORD A);//fungsi print
//SELESAI DEKLARASI RC5

//MAIN UNTUK PEMBUATAN PASANGAN
main()
{ 
  //mulai deklarasi seed=seed random, x=counter
  unsigned int seed, jumlah_sample, x, xx,xxx;
  unsigned long cipherteks[2], cipherteks1[2], plainteks[2], plainteks1[2], e=0x1,difference[2], v[2], v_ASLI[2], ct[2];
  char nama_file[50],nama_file2[50], urutanfile[5];//nama_file diperoleh dari input. nama file2 itu untuk nyimpen yang udah di edit2
  FILE *fsample, *fdifference;
  //selesai deklarasi
  
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
                  RC5_SETUP(key);
                  v[0] = printword_reverse(v_ASLI[0]);//mengubah posisi plainteks
                  v[1] = printword_reverse(v_ASLI[1]);//mengubah posisi plainteks
                  RC5_ENCRYPT(v,ct);
              
                  for(xx=0;xx<2;xx++)
                  {cipherteks[xx] = printword(ct[xx]);}
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
                  RC5_SETUP(key);
                  v[0] = printword_reverse(v_ASLI[0]);//mengubah posisi plainteks
                  v[1] = printword_reverse(v_ASLI[1]);//mengubah posisi plainteks
                  RC5_ENCRYPT(v,ct);
                  
                  for(xx=0;xx<2;xx++)
                  {cipherteks1[xx] = printword(ct[xx]);}
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

//ALGORITMA RC5
void RC5_ENCRYPT(WORD *pt, WORD *ct) //2 word input pt dan output ct
{
     WORD i, A=pt[0]+S[0], B=pt[1]+S[1];
     for(i=1;i<=r;i++)
     {
                      A = ROTL(A^B,B)+S[2*i];
                      B = ROTL(B^A,A)+S[2*i+1];
     }
     ct[0] = A; ct[1] = B;
}
//encryption end

//key setup
void RC5_SETUP(unsigned char *K)//secret input key K[0...b-1]
{
     WORD i, j, k, u=w/8, A, B, L[c];
     for (i=b-1, L[c-1]=0;i!=-1;i--) L[i/u]=(L[i/u]<<8)+K[i];
     for (S[0]=P,i=1;i<t;i++) S[i] = S[i-1]+Q;
     for (A=B=i=j=k=0;k<3*t;k++,i=(i+1)%t,j=(j+1)%c)
     {
         A = S[i] = ROTL(S[i]+(A+B),3);
         B = L[j] = ROTL(L[j]+(A+B),(A+B));
     }
}
//SELESAI ALGORITMA RC5
//fungsi print
unsigned long printword(WORD A)
{
         WORD k,kk = 0;
         for(k=0;k<w;k+=8) kk ^= ((A>>k)&0xFF)<<(24-k);
         return kk;
}

unsigned long printword_reverse(WORD A)
{
         WORD k,kk = 0;
         for(k=0;k<w;k+=8) kk = ((A>>k)&0xFF) ^ (kk<<8);
         return kk;
}
