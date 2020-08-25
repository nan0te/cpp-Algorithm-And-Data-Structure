#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "BSTree.cpp"

int main() {
    BSTree<int> t;
    t.Insert(20);
    t.Insert(25);
    t.Insert(15);
    t.Insert(10);
    t.Insert(30);
    t.Display();
    t.Remove(20);
    t.Display();
    t.Remove(25);
    t.Display();
    t.Remove(30);
    t.Display();
    
    return 0; 
}