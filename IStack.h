#ifndef ISTACK_H
#define ISTACK_H

#include <iostream>
#include <stdlib.h>

template <class Type>
struct IStack {

    virtual bool isEmpty(void) = 0 ;
    virtual bool isFull(void) = 0  ;
    virtual void push_back(const Type&) = 0;
    virtual void pop() = 0 ;
    virtual Type& peek() = 0 ;
    virtual int size(void) = 0 ;
    virtual ~IStack(void) {}

};


#endif // ISTACK_H