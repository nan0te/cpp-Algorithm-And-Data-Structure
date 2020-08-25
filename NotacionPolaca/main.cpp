  #include <iostream>
#include <stdlib.h>
#include "./postfix.cpp"
#include "./subfija.cpp"

char* InfijaToPostfija ( const char* infija);
char* ToPreFija ( const char* infija ) ;
int Calculate(char* postfija);
int Calculate2 (  char* prefija );

    int main()
{

 //   char* result = InfijaToPostfija("(2+4)*3") ;
 //   printf("%s \n",result);

    char* result = ToPreFija ("(2+4)*3") ;
    printf("%s\n",result);
    char result2[] = "*+242";  
    int calcular = 0 ; calcular = Calculate2(result2);
    printf("%i\n", calcular);

  //  int calcular  = 0; calcular = Calculate(result) ;
    //std::cout << "resultado operacion es :" << calcular << std::endl;
  //  printf("%i\n", calcular);


    return 0 ;
}