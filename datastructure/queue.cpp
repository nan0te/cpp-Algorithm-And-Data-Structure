#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "IQueue.h"

template <class Object>
class queue : public IQueue<Object>
{
    class Node {
     public:
        Object item;
        int next;
    };

    public:
    queue(void);
    virtual ~queue(void) {}
    virtual Object& enqueue(const Object& item) ;
    virtual Object dequeue(void) ;
    virtual bool isEmpty(void) ;
    virtual bool isFull(void) ;
    virtual size_t size(void) ;
    virtual Object& front(void) ;
    
 

  private:
    enum { MAX_ITEMS = 1024 , null = -1} ;
    class Node rep[MAX_ITEMS];
    int free, first, last, newFree, count;
};

template <class Object>
queue<Object>::queue(void){
    first = null ; free= 0 ; last = null ; newFree = 0 ; count = 0 ;

    for (int i = 0 ; i < MAX_ITEMS ; i++ ){
        rep[i].item = 0 ;
        rep[i].next = i + 1 ; 
    }
    rep[MAX_ITEMS-1].next = null ;
}

template <class Object>
bool queue<Object>::isEmpty(void) {
    return count == 0 ;
}

template <class Object>
bool queue<Object>::isFull(void){
    return count == MAX_ITEMS;
}

template <class Object>
size_t queue<Object>::size(void) {
    return count;
}

template <class Object>
Object& queue<Object>::enqueue(const Object& item) {

    if(!isFull()){
        newFree = rep[free].next;
        rep[free].item = item ;
            if(isEmpty()) {
                first = free; last = free ;
                rep[last].next = null;
            }
            else {
                last = free;
                rep[last].next = null;
            }
       free= newFree;
       count++;     
    }
    return rep[last].item;

}


template <class Object>
Object queue<Object>::dequeue(void) {

    if (isEmpty()) exit(EXIT_FAILURE) ;

   Object obj = rep[first].item ;
   // std::cout << "el siguiente es : " << rep[last].next << std::endl ;
    first = (first + 1) % MAX_ITEMS ;
    count--;

    return obj;
}

template <class Object>
Object& queue<Object>::front(void) {

    if (isEmpty()) exit(EXIT_FAILURE) ;

    return rep[first].item ;
   

}

#endif



                                                                                 // enqueue last = ( first + count ) % MAX_ITEMS ; rep[last] = item; count++;
                                                                                // dequeue fisrt= (fisrt + 1) % MAX_ITEMS; count--; 




                                                                                // levelorder(root)
                                                                                // q-> empty queue , s empty stack
                                                                                // q.enqueue(root) 
                                                                                // mientras(!q.isempty()) 
                                                                                //node =  q.dequeue ,  s.psuh(node)
                                                                                //if ( node.right == null) q.enqueue(node.right)
                                                                                //if node.left null )  q.enqueue nodeleft
                                                                                //while !s.empty , node =  s.pop(); printf ( node )
                                                                            