#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "IStack.h"
#include "Stack.cpp"


// cadena ((((()))))

/* 
    si es un ) y si esta vacia return false. Sino esta vacia pop
    si balance es true y esta vacia return true : false 
*/
bool ParentesisProblem( const char* cadena ) {

    IStack<const char*>* stack = new Stack<const char*>;

    int i = 0 ;
    int len = strlen(cadena) ;

    bool balance = true ;    

        while ( i < len && ( cadena[i] == '(' || cadena[i] == ')' ) ) {

                if ( cadena[i] == '(' ) 
                  {
                      stack->push_back(&cadena[i]);
                  }
                else  {
                       //bool vacia = false ;
                      // ( vacia == stack->isEmpty() ) ? std::cout << "vacia" <<std::endl : std::cout << "no"<<std::endl;  
                      if ( stack->size() == 0 )  {     
                            balance = false ;
                      }
                     else  {
                          
                            stack->pop();
                          
                        }
                 }
           i++; 

        }
        std::cout << stack->size();
        

        bool result = false;
        if ( balance == true && ( stack->size() == 0 ) )  result = true; 
        
        //result == true ? std::cout<< "true" << std::endl : std::cout << " false \n" ;
        
        return result;
        //return ( balance == true && stack->isEmpty() ) ? true : false ;                    

        }
//    ((((((( )))))))


bool match(char str1,  const char* str2);
bool ArrayCharCompare(const char *str1,  const char* str2);
// {[[(())]]}
bool AperturasYCierres ( const char* cad ) {

    IStack<const char *>* aperturas = new Stack<const char *>;
    
    int index = 0 ;
    int len = strlen(cad);
    bool balance = true ;
    
    char aperts[] = "([{";
    char cierres[] = ")]}";

    while (index < len && (ArrayCharCompare(&cad[index], aperts) || ArrayCharCompare(&cad[index], cierres) )) {

            if ( ArrayCharCompare(&cad[index],aperts) )
            {
                 aperturas->push_back(&cad[index]);
                    
            }

            else 
            {

                    if( aperturas->size() == 0 ) balance = false ;

                    else {  // char top = *aperturas->peek() ;
                            // buscar pareja si cad[index] es la pareja de aperturas->peek()
                            if (match(*aperturas->peek(), &cad[index]))  aperturas->pop();
                        
                    }
            }
        index++;
    }
        
    bool result = false ;
    if ( balance && (aperturas->size() == 0) ) result = true ;

        return result;
}


bool CharCompare ( const char* str1, const char* str2) {

    return (strcmp(str1,str2) == 0 ) ? true  : false ;

}

bool ArrayCharCompare(const char *str1,  const char* str2)
{
      bool result = false ;   
    
      if      (str1[0] == str2[0])  result = true ;
      else if (str1[0] == str2[1])  result = true;
      else if (str1[0] == str2[2])  result = true;

      return result;
}

bool match ( char str1,  const char*  str2 ) {

        bool match = false ;
        if ( ( str1 == '(' ) && (  str2[0] == ')' ) ) match = true ;
        else if ((str1 == '[') && (str2[0] == ']'))  match = true;
        else if ((str1 == '{') && (str2[0] == '}'))  match = true;

        return match;
}