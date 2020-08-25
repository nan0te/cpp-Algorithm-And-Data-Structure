#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "ConverADecimal.cpp"

 
 char* Append( char* des,  char* str);
 char* DivByTwo ( int decimal );
 char* ConvertBase (unsigned int num, unsigned int base);

int main (){


   //  const char* result = DivideByTwo(121);
    // printf("%s",result);

     char* r =  DivByTwo(65) ;
  //   printf("%s",r);

     char* resu =  ConvertBase(41855,16);
     printf("%s",resu);
    //std::cout << result  << std::endl;

// char des[] = "asd";
//char str[] = "dasd";
  //   char* append = Append( des , str);
    
   // int len = strlen(append);
/*     for ( int i = 0 ; i < len ; i++ ){
         append[i];
     }
   */ //std::cout << append << std::endl ;

    return 0;
}