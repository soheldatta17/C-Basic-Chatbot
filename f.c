#include<stdio.h>
//#include<conio.h>
 
int main() {
   char password[128], c;
   int index = 0;
  
   printf("Enter Password : ");
   while((c = getch()) != 13)
   {
       if(index < 0)
           index = 0;
       if(c == 8){
           printf("\b");
           
          // putch('\b');
           index--;
       continue;
       }
       password[index++] = c;
       printf("*");
   }
   password[index] = '\0';
 
   printf("\nPassword String = %s", password);
  
   return 0;
}