#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/md5.h>
#include<math.h>

int main()
{
FILE *file ;
  unsigned char result[MD5_DIGEST_LENGTH];
   int i;
   double entropy;
   char c[100];

   
   file = fopen("pass.txt","r");
   
   if (file)
   {
      while((fgets(c,sizeof(c),file))!=NULL)
      {
         printf("%s\t\t",c); //printing the string from txt file
          printf("\n");
         MD5(c, strlen(c), result);
         for(i = 0; i <=MD5_DIGEST_LENGTH; i++)
         {           
           printf("%02x",result[i]); //print  the hash value
           //printf("\n");
         }      
         entropy= ( log(61) / log(2) ) * (strlen(c)-1);
         printf("\t%lf\n",entropy);     // print the entropy
         printf("\n");
      }
   }
// fprintf(EOF);
}

