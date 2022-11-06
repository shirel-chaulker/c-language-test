#include<stdio.h> // bag- fix and add libary
#pragma warning(disable : 4996) // add pragma
  

int main_1() {

   int a = 4;
   int b = 7; // bag- fix var b is not define 

   float c;

   scanf("%f", &c); // bag - syntax error, var c without &
    
   if (c==5) // var c is not define, and cannot be defined in syntax if, float is not for Integer
   {
       printf("%f", c);   // add {}, printf not write correct 
   }
   else
   {
       printf("the numbers arent equal");
   }


       
   return 0;  // add return to sign if the program is successful

}