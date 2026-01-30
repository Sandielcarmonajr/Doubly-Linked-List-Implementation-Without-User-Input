//main.cpp

#include <iostream>
#include "DLinkedList.h"


int DNode::activeNodes = 0;

int main() {
    DLinkedList list;

    
    list.addFront(10);
    list.addFront(20);
    list.addFront(30);

 
    list.addBack(40);
    list.addBack(50);

  
    list.print(true);

    
    list.print(false);

   
    list.removeFront();
    list.removeBack();

   
    list.print(true);

    
    list.addFront(60);
    list.addBack(70);

    
    list.print(true);

 
    std::cout << "Total active nodes: " << list.activeNodeCount() << std::endl;

    return 0;
}