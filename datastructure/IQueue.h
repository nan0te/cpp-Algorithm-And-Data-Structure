#ifndef IQUEUE_H
#define IQUEUE_H

#include <iostream>
#include <stdlib.h>

template <class Object>
struct IQueue {

        virtual Object& enqueue(const Object&) = 0 ;
        virtual Object dequeue(void) = 0 ;
        virtual bool isEmpty(void) = 0 ;
        virtual bool isFull(void) = 0 ;
        virtual size_t size(void) = 0;
        virtual Object& front(void) = 0 ;
        virtual ~IQueue<Object>(void) {}

};



#endif

