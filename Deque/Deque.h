#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <iostream>
#include <cstddef>

template<typename T>
class Deque
{
    public:
        Deque();
        ~Deque();
        void push_front(const T& value);
        void push_back(const T& value);
        T    pop_front();
        T    pop_back();
        T    peek_front() const;
        T    peek_back() const;
        void clear();

        inline bool empty() const;
        inline std::size_t get_Size() const;

    private:
        std::size_t size;
        
        struct node
        {
            T value;
            node *next;
            node *prev;
        } *head, *tail;
        
    template<typename T1>
    friend std::ostream& operator<<(std::ostream& os, const Deque<T1>& d);
};

template<typename T>
Deque<T>::Deque():head(nullptr), tail(nullptr), size(0)
{}

template<typename T>
Deque<T>::~Deque()
{
    clear();
}

template<typename T>
void Deque<T>::push_front(const T& value)
{
    node *tmp  = new node;
    tmp->value = value;
    tmp->prev  = nullptr;
    
    if (empty())
    {
        tmp->next = nullptr;
        head = tail = tmp;
    }
    else
    {
        tmp->next  = head;
        head->prev = tmp;
        head       = tmp;
    }
    
    size++;
}

template<typename T>
void Deque<T>::push_back(const T& value)
{
    node *tmp  = new node;
    tmp->value = value;
    tmp->next  = nullptr;    
    
    if(empty())
    {
        tmp->prev = nullptr;
        head = tail = tmp;
    }
    else
    {
        tmp->prev  = tail;
        tail->next = tmp;
        tail       = tmp;
    }
    
    size++;
}

template<typename T>
T Deque<T>::pop_front()
{
    if(empty())
    {
        throw "Deque is empty";
    }

    node *tmp  = head;
    T value    = head->value;
    head       = head->next;
    
    delete tmp;
    size--;
    
    return value;
}

template<typename T>
T Deque<T>::pop_back()
{
    if(empty())
    {
        throw "Deque is empty";
    }
    
    node *tmp  = tail;
    T    value = tail->value;
    tail       = tail->prev;
    
    delete tmp;
    size--;
    
    return value;
}

template<typename T>
T Deque<T>::peek_front() const
{
    if(empty())
    {
        throw "Deque is empty";
    }
    
    return head->value;
}

template<typename T>
T Deque<T>::peek_back() const
{
    if(empty())
    {
        throw "Deque is empty";
    }
    
    return tail->value;
}

template<typename T>
void Deque<T>::clear()
{
    while(!empty())
    {
        node *tmp = head;
        head      = head->next;
        
        delete tmp;
    }
    
    head = tail = nullptr;
}

template<typename T>
inline bool Deque<T>::empty() const
{
    return !head;
}

template<typename T>
inline std::size_t Deque<T>::get_Size() const
{
    return size;
}

template<typename T1>
std::ostream& operator<<(std::ostream& os, const Deque<T1>& d)
{
    typename Deque<T1>::node *tmp = d.head;
    
    while(tmp)
    {
        os << tmp->value << " ";
        tmp = tmp->next;
    }
    
    return os;
}

#endif
