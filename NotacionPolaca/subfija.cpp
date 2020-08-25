#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
#include <stack>
#include "./../IStack.h"
#include "./../Stack.cpp"

bool Containn ( char token, const char* cad ) {

    bool contain = false ;
        for ( int index = 0 ; index < (int)strlen(cad) ; index++ ) {
                
                if ( token == cad[index] ) {
                        contain = true ;
                        break;
                }
        }
    return contain ;
}

char* ToPreFija ( const char* infija ) {

       IStack<char>* stack = new Stack<char> ;
       IStack<char> * prefija = new Stack<char> ;
       const char* digits = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" ;

       std::unordered_map<char,int> precedencia ;
       precedencia['*'] = 3 ;
       precedencia['/'] = 3 ;
       precedencia['+'] = 2 ;
       precedencia['-'] = 2 ;
       precedencia[')'] = 1 ;
       
       int len =  strlen(infija) ;

       for (int i = len ; i >= 0 ; i-- ) {
            
            char token = infija[i] ;
        
            if ( token == 32 ) continue ;
            else if ( Containn(token,digits) )   prefija->push_back(token) ;     
            else if ( token == ')' )  stack->push_back(token) ;

            else if ( token == '(' ) {
                char top = stack->peek() ;
                stack->pop() ;

                while ( top != ')' ) {
                    prefija->push_back(top) ;
                    top = stack->peek();
                    stack->pop() ;
                }
            }
            else {
                    while ( !stack->isEmpty() && ( precedencia[stack->peek()] >= precedencia[token]) ) {
                        prefija->push_back(stack->peek()) ;
                        stack->pop() ;
                    }
                 stack->push_back(token) ;                    
            }
       } 

       while ( !stack->isEmpty() ) {
           prefija->push_back(stack->peek()); 
           stack->pop();
       }    
    
    int size = prefija->size() ;
    int N = 0 ;
    char result[N];
    
    for ( int i = 0 ; i < size ; i++ )
    {
      result[i] = prefija->peek() ; std::cout<<result[i];
      prefija->pop();
      N++;
    }
    result[N] = '\0' ;
     
     char* result2 = new char[N] ; 
     strcpy(result2,result) ;
     

       
    return result2 ;

}

int Aritmetica2 ( char _operator, char operando1, char operando2) {

    int result = 0 ;
    if ( _operator == '*' )     result = operando1 * operando2 ;
    else if ( _operator == '/') result = operando1 / operando2 ;
    else if ( _operator == '+') result = operando1 + operando2 ;
    else if ( _operator == '-') result = operando1 - operando2 ;
    
    return result ;
}


int Calculate2 (  char* prefija ) {

    IStack<int>*  s = new Stack<int> ;
    const char* nums = "0123456789";
    const char* operators = "*/+-";
    int len = strlen(prefija);

    for ( int i = len-1 ; i >= 0 ; i-- ) {

            char token = prefija[i];
            std::cout << token << " . " << std::endl;
            
            if ( Contain(token,nums)) {
                s->push_back(int(prefija[i])-48);
            
            }
            else {
                    
                    int operando1 = s->peek() ;
                    s->pop() ;
                    int operando2 = s->peek() ;            
                    s->pop();
                    int result = Aritmetica2(token,operando1,operando2);
                    s->push_back(result);  
            }
     }
    return s->peek();
}

  