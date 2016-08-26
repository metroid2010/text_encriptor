#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
   FILE* fpin;
   FILE* fpout;
   int i = 0, d, count, j;
   char name_file[100];
   char c, a;
   char str[1000], temp[6];
   int sz, s;

   do{
      printf("Name of file? ");
      scanf(" %[^\n]", name_file);
      fpin = fopen(name_file, "r");
      if(!fpin)
         printf("Sorry, file not found\n");
   }while(!fpin);

   printf("File found. Desencrypting\n");

   fpout = fopen("desen.txt", "w");

   a = fscanf(fpin, "%c", &c);
   fseek(fpin, 0, SEEK_SET);
   while(a != EOF)
   {
      count = 0;
      do
      {
         a = fscanf(fpin, "%c", &c);
         if(c==' ')
         {
            count += 1;
         }
      }while(c != '\n');
     // printf("check");
      if(count!=0)
      {
         fprintf(fpout, "%c", count);
      }
   }

   printf("File output: enc.txt ");
   fclose(fpin);
   fclose(fpout);
   printf("\n\n");
   system("PAUSE");
   return 0;

}
