#include <iostream>
#include "Deque.h"

int main()
{
    using std::cout;
    using std::endl;
    
    Deque<int> deq;
    
    deq.push_back(2);
    deq.push_back(10);
    deq.push_front(5);
    deq.push_front(7);
    
    cout << "current deque: " << deq << endl;
    
    deq.clear();
    cout << endl << "deque after cleaning: " << deq << endl;
    
    deq.push_back(5);
    deq.push_front(9);
    
    cout << endl << "deque after insertion of two elements: " << deq << endl;
    
    return 0;
} 