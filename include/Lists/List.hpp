#include <iostream>

namespace Lists{

template<typename T>
class List{
    
    template <typename U>
    class Node{
        Node<U>* next;
        Node<U>* previous;
        U* value;

    public:

        Node(U* value = nullptr){
            next = nullptr;
            previous = nullptr;
            this->value = value;
        }

        ~Node(){
            next = nullptr;
            previous = nullptr;
            value = nullptr;
        }

        Node<U>* getNext(){
            return next;
        }

        Node<U>* getPrevious(){
            return previous;
        }

        U* getValue(){
            return value;
        }

        void setNext(Node<U>* next){
            this->next = next;
        }

        void setPrevious(Node<U>* previous){
            this->previous = previous;
        }
        
        void setValue(U* value){
            this->value = value;
        }
    };

    Node<T>* begin;
    Node<T>* end;
    unsigned int size;

public:

    List();
    ~List();

    const unsigned int getSize() const{
        return size;
    }

    bool add(T* value);
    bool remove(T* value);   
    
    T* operator[](unsigned int index);
};

template<typename T>
List<T>::List(){
    begin = nullptr;
    end = nullptr; 
    size = 0;
}

template<typename T>
List<T>::~List(){

    Lists::List<T>::Node<T> *currentNode = begin;
    List::Node<T> *aux;

    while(currentNode){
        aux = currentNode->getNext();
        delete currentNode;
        currentNode = aux;
    }

    begin = nullptr;
    end = nullptr;
    size = 0;
}

template<typename T>
bool List<T>::add(T* value){
    if(!value){
        std::cout << "[List] Falha ao adicionar um novo nó a lista. Recebido nullptr\n";
        return false;
    }

    Node<T> *node = new Node<T>(value);

    if(!begin){
        begin = node;
        end = node;
    }else{
        end->setNext(node);
        node->setPrevious(end);
        end = node;
    }

    size++;
    return true;
}

template<typename T>
bool List<T>::remove(T* value){
    
    if(!value){
        std::cout << "[List] Falha ao remover um nó da lista. Recebido nullptr.\n";
        return false;
    }

    List<T>::Node<T> *searchNode = begin;

    while(searchNode){
        if(searchNode->getValue() == value) break;
        searchNode = searchNode->getNext();
    }

    if(!searchNode){
        std::cout << "[List] Falha ao remove um nó da lista. Valor inexistente.\n";
        return false;
    }

    if(searchNode == begin){
        begin = searchNode->getNext();
    }else if(searchNode == end){
        end = searchNode->getPrevious();
    }

    if(searchNode->getPrevious()){
        searchNode->getPrevious()->setNext(searchNode->getNext());
    }
    
    if(searchNode->getNext()){
        searchNode->getNext()->setPrevious(searchNode->getPrevious());
    }

    if(searchNode->getValue()){
        delete searchNode->getValue();
    }

    delete searchNode;
    size--;

    return true;
}

template<typename T>
T* List<T>::operator[](unsigned int index){
    if(index >= size) {
        std::cout << "[List] Erro ao obter um valor na lista. O index escolhido é maior que a lista.\n";
        return nullptr;
    }

    Node<T> *currentNode = begin;

    for(int i = 0; i < index; i++){
        currentNode = currentNode->getNext();
    }

    return currentNode->getValue();
}

}