#include <iostream>
#include <stdlib.h>

#include "IStack.h"
#include "Stack.cpp"

#include "ParentesisProblem.hpp"

bool ParentesisPoblem ( const char* cadena );
bool ArrayCharCompare ( const char* str1,  const char* str2 ) ;
bool CharCompare(const char *str1, const char *str2);
bool AperturasYCierres(const char *cad);

    int main()
{

    const char *cad = "(((())))";
    //ParentesisPoblem(cad) ? printf("True\n") : printf("false\n") ;
    bool result;
    result = ParentesisProblem(cad);

    if (result == true)
        printf("True \n\n");
    else
        printf("False\n\n");

    ////////////////////////////////

    char cad2[] = ")]}"; // const char* cad 2 = ")]}"
    bool compare;
    compare = ArrayCharCompare("2", cad2);

    if (compare)
        printf("el caracter esta dentro de la palabra\n\n");
    else
        printf("el char no se encuentra en la palabra\n\n");

    ///////////////////////////////////

    const char* cad3 = "[[((()))]]}";
    bool result2;
    result2 = AperturasYCierres(cad3);

    if (result2 == true ) printf("Balanceado\n\n");
    else printf("No estan balanceados\n\n");



 
    return 0 ;

}