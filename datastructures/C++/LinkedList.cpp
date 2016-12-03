#include <stddef.h>
#include <stdio.h>

/*
 * Generic node for singly linked list
 */
template <class T> class Node {
    private:
        Node<T> *next;
        T data;

    public:
        void setData(T const&);
        T getData();
        void setNext(Node<T> const&);
        Node<T> getNext();

};

template <class T> 
void Node<T>::setData(T const& inData) {
    data = inData;
}

template <class T> 
T Node<T>::getData() {
    return data;
}

template <class T> 
void Node<T>::setNext(Node<T> const& n) {
    nexr = n;
}

template <class T> 
Node<T> Node<T>::getNext() {
    return *next;
}

/*
 * Generic singly linked list
 */
template <class T> class SinglyLinkedList {
    private:
        Node<T> *root;     

    public:
        void insert(T data) {

        }
};


int main() {
    Node<int> n1;
    n1.setData(5);
    printf("%i\n", n1.getData());

    Node<int> n2;
    n2.setData(7);

    n1.setNext(n2);
    printf("%i\n", n1.getNext.getData());

    return 0;
}