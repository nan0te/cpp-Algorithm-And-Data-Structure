#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>


#include "./../IStack.h"
#include "./../Stack.cpp"

using std::stringstream ;

char* Append ( char* des,  char* str);

char* DivByTwo ( int decimal ) {
    
    IStack<char>* stack = new Stack<char>;
    
    while ( decimal > 0 ) {

            int res = decimal % 2 ;
            char aux = res + '0';
            stack->push_back(aux);
            decimal = decimal / 2 ;
            
    }
        
    int N = stack->size();
    char result[N];        
        
    for ( int i = 0 ; i < N ; i++) {
            result[i] = stack->peek() ;
            stack->pop();
     }
     result[N++] = '\0';
        
    char * ret = new char[N+1];
    strcpy(ret,result); 
       // printf("%s",result);
    return ret;
}


char* ConvertBase (unsigned int num, unsigned int base) {

        IStack<int> * s = new Stack<int>;
        const char* cad = "0123456789ABCDEF";

        while ( num > 0 ) {

                int res = num % base ;
                s->push_back(res);
                num = num / base ;
        }
        
        int N = s->size();
        int index = 0 ;
        char result[N];
        char* ret = new char[N+1];

        while ( s->size() > 0 ) {

            std::cout << s->peek() << std::endl;
            result[index] = cad[s->peek()];
            s->pop();
            index++;

        }
        
        result[N++] = '\0';

        strcpy(ret,result);

    return ret;
}


 char* Append ( char* des,  char* str) {

    int len = strlen(des);
   
   strcat(des,str);

   for (int i = 0 ; i < len ; i++) {
       des[i];
   } 

    return des;

}