#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <iostream>
#include <cstddef>

template<typename T>
class Deque;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& d);

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

        inline bool        is_empty() const;
        inline std::size_t size() const;

    private:
        std::size_t _size;
        
        struct node
        {
            T value;
            node *next;
            node *prev;
        } *head, *tail;

    friend std::ostream& operator<<<>(std::ostream& os, const Deque<T>& d);
};

template<typename T>
Deque<T>::Deque():head(nullptr), tail(nullptr), _size(0)
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
    
    if (is_empty())
    {
        tmp->next   = nullptr;
        head = tail = tmp;
    }
    else
    {
        tmp->next  = head;
        head->prev = tmp;
        head       = tmp;
    }
    
    ++_size;
}

template<typename T>
void Deque<T>::push_back(const T& value)
{
    node *tmp  = new node;
    tmp->value = value;
    tmp->next  = nullptr;    
    
    if(is_empty())
    {
        tmp->prev   = nullptr;
        head = tail = tmp;
    }
    else
    {
        tmp->prev  = tail;
        tail->next = tmp;
        tail       = tmp;
    }
    
    ++_size;
}

template<typename T>
T Deque<T>::pop_front()
{
    if(is_empty())
    {
        throw "Deque is empty";
    }

    node *tmp  = head;
    T value    = head->value;
    head       = head->next;
    
    delete tmp;
    --_size;
    
    return value;
}

template<typename T>
T Deque<T>::pop_back()
{
    if(is_empty())
    {
        throw "Deque is empty";
    }
    
    node *tmp  = tail;
    T    value = tail->value;
    tail       = tail->prev;
    
    delete tmp;
    --_size;
    
    return value;
}

template<typename T>
T Deque<T>::peek_front() const
{
    if(is_empty())
    {
        throw "Deque is empty";
    }
    
    return head->value;
}

template<typename T>
T Deque<T>::peek_back() const
{
    if(is_empty())
    {
        throw "Deque is empty";
    }
    
    return tail->value;
}

template<typename T>
void Deque<T>::clear()
{
    while(!is_empty())
    {
        node *tmp = head;
        head      = head->next;
        
        delete tmp;
    }
    
    head = tail = nullptr;
    _size       = 0;
}

template<typename T>
inline bool Deque<T>::is_empty() const
{
    return !head;
}

template<typename T>
inline std::size_t Deque<T>::size() const
{
    return _size;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& d)
{
    auto tmp = d.head;
    
    while(tmp)
    {
        os << tmp->value << " ";
        tmp = tmp->next;
    }
    
    return os;
}

#endif
