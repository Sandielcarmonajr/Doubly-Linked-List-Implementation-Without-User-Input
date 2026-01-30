//DLinkedList.h

#include "DNode.h"

class DLinkedList {
private:
    DNode* head;     
    DNode* trailer;  
    int n;           
    
public:
    DLinkedList();             
    ~DLinkedList();           

    bool empty() const;        
    const int& front() const;  
    const int& back() const;   

    void addFront(const int& e);   
    void addBack(const int& e);    
    void removeFront();            
    void removeBack();             

    void print(bool front = true) const; 
    int size() const;                    
    int activeNodeCount() const;         
};