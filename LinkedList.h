#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


#include <iostream>


template<class T>
class LinkedList{
public:
    class node{
    public:
        T data;
        node *prev = nullptr;
        node *next = nullptr;

        node(const T &data) : data(data) {}
    };

    int s = 0;
    node* head = nullptr;
    node* tail = nullptr;

    inline bool empty(){
        return s == 0;
    }

    inline bool size(){
        return s;
    }

    void push_front(const T &data);
    void push_back(const T &data);
    void insert(node* v, const T &data);
    void pop_front();
    void pop_back();
    node* pop(node* v);
    node* next(node* v);
    node* prev(node* v);

    template<class Type>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<Type>&);

};


template<class T>
void LinkedList<T>::push_front(const T& data){
    auto v = new node(data);
    if(empty()){
        head = v;
        tail = v;
    }
    else{
        head->prev = v;
        v->next = head;
        head = v;
    }
    s += 1;
}


template<class T>
void LinkedList<T>::push_back(const T& data){
    auto v = new node(data);
    if(empty()){
        head = v;
        tail = v;
    }
    else{
        tail->next = v;
        v->prev = tail;
        tail = v;
    }
    s += 1;
}


template<class T>
void LinkedList<T>::insert(LinkedList<T>::node* v2, const T& data){
    if(v2 == nullptr){
        push_back(data);
    }
    else{
        auto v = new node(data);
        auto v1 = v2->prev;
        v1->next = v;
        v2->prev = v;
        v->prev = v1;
        v->next = v2;
    }
    s += 1;
}


template<class T>
void LinkedList<T>::pop_front(){
    if(empty()){
        throw "Can not delete element from an empty list";
    }
    s -= 1;
    auto v = head->next;
    delete head;
    if(v != nullptr){
        v->prev = nullptr;
    }
    head = v;
    if(head == nullptr){
        tail = nullptr;
    }
}


template<class T>
void LinkedList<T>::pop_back(){
    if(empty()){
        throw "Can not delete element from an empty list";
    }
    s -= 1;
    auto v = tail->prev;
    delete tail;
    if(v != nullptr){
        v->next = nullptr;
    }
    tail = v;
    if(tail == nullptr){
        head = nullptr;
    }
}


template<class T>
typename LinkedList<T>::node* LinkedList<T>::pop(LinkedList<T>::node* v){
    if(v == nullptr){
        throw "Can not delete end(null) list elemet";
    }
    s -= 1;
    if(v == head){
        pop_front();
        return head;
    }
    else if(v == tail){
        pop_back();
        return nullptr;
    }
    else{
        auto v1 = v->prev;
        auto v2 = v->next;
        delete v;
        v1->next = v2;
        v2->prev = v1;
        return v2;
    }
}

template<class T>
typename LinkedList<T>::node* LinkedList<T>::next(LinkedList<T>::node* v){
    if(v == nullptr){
        throw "End(null) list elemet does not have next element";
    }
    return v->next;
}

template<class T>
typename LinkedList<T>::node* LinkedList<T>::prev(LinkedList<T>::node* v){
    if(v == head){
        throw "Begin list elemet does not have prev element";
    }
    if(v == nullptr){
        return tail;
    }
    return v->prev;
}


template<class Type>
std::ostream& operator<<(std::ostream& out, const LinkedList<Type>& lst){
    auto v = lst.head;
    while(v != nullptr){
        out << v->data << " ";
        v = v->next;
    }
    return out;
}


#endif //LINKEDLIST_LINKEDLIST_H
