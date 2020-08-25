#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "./datastructure/IQueue.h"
#include "./datastructure/queue.cpp"

char* JuegoPatata(char nom[10][10],int num );
int main () {


    char nombres[6][10] = { "hola", "jose", "pepo", "esteban", "juan", "nano" }; 
    char* result = JuegoPatata(nombres,3) ;
    printf(" juego patato : %s", result);

    return 0;
}
char* JuegoPatata (char nom[6][10],int num ) {

    IQueue<char*>* q = new queue<char*>;
      
    for (int i=0; i<10;i++) 
    
    { q->enqueue(nom[i]) ;
    }
    while ( (int)q->size() > 1) {
        
        for (int i = 0 ; i < num  ; i++ ) {

            q->enqueue(q->front()) ;
            q->dequeue();
        }
        q->dequeue();
    }
    char * result = q->front() ;

    return q->front();
}