/*Ardya Suryadinata 9 JANUARI 2012
Enkripsi dan Dekripsi TEA. sumber: TEA (Needham dan Wheeler)
*/
#include <stdio.h>
#include <conio.h>

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

void decode(long* v,long* k) 
{
     unsigned long n=32, sum, y=v[0], z=v[1],
     delta=0x9e3779b9 ;
     sum=delta<<5 ;
     /* start cycle */
     while (n-->0) 
     {
           z-= ((y<<4)+k[2]) ^ (y+sum) ^ ((y>>5)+k[3]) ;
           y-= ((z<<4)+k[0]) ^ (z+sum) ^ ((z>>5)+k[1]) ;
           sum-=delta ; }
     /* end cycle */
     v[0]=y ; v[1]=z ; 
}

main()
{
      int x;
      unsigned long Data[2], key[4] = {0,0,0,0};
      Data[0] = 0;
      Data[1] = 0;
      
      printf("Plainteks = ");
      for(x=0;x<2;x++) printf("%08lx ", Data[x]);
      printf("\nKunci = ");
      for(x=0;x<4;x++) printf("%08lx ", key[x]);
      code(Data, key);
      printf("\nCipherteks = ");
      for(x=0;x<2;x++) printf("%08lx ", Data[x]);
      getch();
}
      
