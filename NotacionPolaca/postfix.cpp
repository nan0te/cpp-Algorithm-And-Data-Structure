#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <string.h>
#include "./../IStack.h"
#include "./../Stack.cpp"
#include <stack>

bool Contain( char token, const char* string ) {

        bool contain = false ;
        
        for ( int index = 0 ;  index < (int)strlen(string) ; index++ ) {
                if ( token == string[index]  ) 
                    {
                        contain = true ;
                        break;
                    }
        }

    return contain ;       
}

char* InfijaToPostfija ( const char* infija) {

    IStack<char> * stack = new Stack<char> ;
    const char* cad = "ABCDFGHIJKLMNOPQRSVTUQYXZ";
    const char* cad2 = "0123456789" ;

    std::unordered_map<char,int> precedencia;
    precedencia['*'] = 3 ;
    precedencia['/'] = 3 ;
    precedencia['+'] = 2 ;
    precedencia['-'] = 2 ;
    precedencia['('] = 1 ;

    int N = 0 ;
    char result[N];
    int len = strlen(infija);

    for ( int i = 0 ; i < len ; i++) // for each  
    {   
         char token = infija[i];
         if(token == 32) { continue; } 
        
        else if (Contain(token,cad) ) {
            
            result[N] = token ;
            N++;
        }
        else if ( Contain(token,cad2)) {
            result[N] = token ;
            N++;
        }
        else if (token == '(') {
            stack->push_back(token) ;
            
        }
        else if (token == ')'){
            char top = stack->peek() ;
            stack->pop();
                while(top != '(') {
                    result[N] = top ; N++ ;
                    top = stack->peek();
                    stack->pop();
                }
        }
        else { // si es * / + - )
            while ( (stack->size() != 0) && ( precedencia[stack->peek()] >= precedencia[token])) {
                    result[N] = stack->peek(); N++; 
                    stack->pop();
                    
            }
     
            stack->push_back(token);

           // std::cout << "token : " << token << std::endl ;
        }
    }
    
    while( stack->size() >= 1 ) {
     
        result[N] = stack->peek() ;           
        N++;
        stack->pop();
    }
    
    // std::cout << "size :" << stack->size() << std::endl ;
    result[N] = '\0' ;
    char* _postfija = new char[N] ;

  //  for( int  i = 0 ; i < N+1 ; i ++) std::cout << result[i] ;
    strcpy(_postfija,result) ;

    return _postfija;
}

int Aritmetica( char _operator, char operando2, char operando1) {
    
        int result = 0 ;
        if ( _operator == '*') result = operando1 * operando2;
        else if (_operator == '/') result = operando1 / operando2 ;
        else if (_operator == '+') result = operando1 + operando2 ;
        else if ( _operator == '-') result = operando1 - operando2 ;
        return result ; 
}

int Calculate ( char* postfija ) {

        IStack<int>* stack = new Stack<int> ;
        //std::stack<int> s ;
        const char* numbers = "0123456789" ;

        int len = strlen(postfija);
        
        int result = 0 ;    
        for ( int i = 0 ; i < len ; i++ ) {
                
                if( Contain(postfija[i],numbers) ) {
                    stack->push_back( int(postfija[i])-48 );
                   // s.push(int(postfija[i])- 48);
                }
                else {
                    
                    int operando2 = stack->peek() ;
                    stack->pop();
                    int operando1 = stack->peek();
                    stack->pop();
                    result = Aritmetica(postfija[i],operando1,operando2);
                    
                    stack->push_back( result );
                                  
                }
        }
        
        
    
    return stack->peek() ;

}