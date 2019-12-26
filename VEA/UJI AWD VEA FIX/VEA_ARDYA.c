/*
Corrected version of VEA implementation in C 

Ardya Suryadinata
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
//VEA YANG INI SESUAI DENGAN GAMBAR SKEMA YANG ADA DI TA BANG KHOLIF
unsigned long VEA_encryption(unsigned long* v, unsigned long* k)
{
     unsigned long v0=v[0], v1=v[1], v2=v[2], v3=v[3], sum=0, i;
     unsigned long golden=0x9e3779b9;
     unsigned long k0=k[0], k1=k[1], k2=k[2], k3=k[3],
                   k4=k[4], k5=k[5], k6=k[6], k7=k[7];
     char nama_file[] = "tes vektor.txt";
     FILE *ftes;
     
     if((ftes=fopen(nama_file,"w"))==NULL) printf("Tidak dapat membuka file");
     
     for(i=0;i<11;i++)
     {
                      sum+=golden;
                      fprintf(ftes,"sum = %08lX\n");
                      fprintf(ftes,"Plainteks = %08lX %08lX %08lX %08lX\n",v0,v1,v2,v3);
                      fprintf(ftes,"Kunci = %08lX %08lX %08lX %08lX %08lX %08lX %08lX %08lX\n",k0,k1,k2,k3,k4,k5,k6,k7);
                      fprintf(ftes,"k4^v3 = %08lX\n", k4^v3);
                      fprintf(ftes,"(k4^v3)+k0 = %08lX\n", (k4^v3)+k0);
                      fprintf(ftes,"((k4^v3)+k0)^sum = %08lX\n", ((k4^v3)+k0)^sum);
                      fprintf(ftes,"v0^k1 = %08lX\n", v0^k1);
                      fprintf(ftes,"(v0^k1)<<5 = %08lX\n", (v0^k1)<<5);
                      fprintf(ftes,"v2 = v2+((((k4^v3)+k0)^sum)+((v0^k1)<<5)) = %08lX\n\n", v2+((((k4^v3)+k0)^sum)+((v0^k1)<<5)));
                      v2 = v2+((((k4^v3)+k0)^sum)+((v0^k1)<<5));
                      
                      fprintf(ftes,"(k5^v2) = %08lX\n", k5^v2);
                      fprintf(ftes,"(k5^v2)+k1 = %08lX\n", (k5^v2)+k1);
                      fprintf(ftes,"((k5^v2)+k1)^sum = %08lX\n", ((k5^v2)+k1)^sum);
                      fprintf(ftes,"v1^k2 = %08lX\n", v1^k2);
                      fprintf(ftes,"(v1^k2)>>5 = %08lX\n", (v1^k2)>>5);
                      fprintf(ftes,"v3 = v3+((((k5^v2)+k1)^sum)+((v1^k2)>>5)) = %08lX\n\n", v3+((((k5^v2)+k1)^sum)+((v1^k2)>>5)));
                      v3 = v3+((((k5^v2)+k1)^sum)+((v1^k2)>>5));
                      
                      fprintf(ftes,"k6+v1 = %08lX\n", k6+v1);
                      fprintf(ftes,"k2+sum = %08lX\n", k2+sum);
                      fprintf(ftes,"(k2+sum)^k3 = %08lX\n", (k2+sum)^k3);
                      fprintf(ftes,"((k2+sum)^k3)+v3 = %08lX\n", ((k2+sum)^k3)+v3);
                      fprintf(ftes,"(((k2+sum)^k3)+v3)<<4) = %08lX\n", (((k2+sum)^k3)+v3)<<4);
                      fprintf(ftes,"v0 = v0+((k6+v1)^((((k2+sum)^k3)+v3)<<4)) = %08lX\n\n", v0+((k6+v1)^((((k2+sum)^k3)+v3)<<4)));
                      v0 = v0+((k6+v1)^((((k2+sum)^k3)+v3)<<4));
                      
                      fprintf(ftes,"k7+v0 = %08lX\n", k7+v0);
                      fprintf(ftes,"k3+sum = %08lX\n", k3+sum);
                      fprintf(ftes,"(k3+sum)^k0 = %08lX\n", (k3+sum)^k0);
                      fprintf(ftes,"((k3+sum)^k0)+v2 = %08lX\n", ((k3+sum)^k0)+v2);
                      fprintf(ftes,"(((k3+sum)^k0)+v2)>>4) = %08lX\n", (((k3+sum)^k0)+v2)>>4);
                      fprintf(ftes,"v1 = v1+((k7+v0)^((((k3+sum)^k0)+v2)>>4)) = %08lX\n\n", v1+((k7+v0)^((((k3+sum)^k0)+v2)>>4)));
                      v1 = v1+((k7+v0)^((((k3+sum)^k0)+v2)>>4));  
                      
                      fprintf(ftes,"Cipherteks Cycle %i= %08lX %08lX %08lX %08lX\n\n\n",i,v0,v1,v2,v3);
                     
     }
     v[0]=v0;
     v[1]=v1;
     v[2]=v2;
     v[3]=v3;
     fclose(ftes);
}
main()
{
      unsigned long pt[4]={0,0,0,0}, kt[8]={0,0,0,0,0,0,0,0};
      printf("Plainteks = %08lx %08lx %08lx %08lx\n",pt[0],pt[1],pt[2],pt[3]);
      printf("Plainteks = %08lx %08lx %08lx %08lx %08lx %08lx %08lx %08lx\n",kt[0],kt[1],kt[2],kt[3],kt[4],kt[5],kt[6],kt[7]);
      VEA_encryption(pt, kt);
      printf("Cipherteks = %08lx %08lx %08lx %08lx\n",pt[0],pt[1],pt[2],pt[3]);
      getch();
}
