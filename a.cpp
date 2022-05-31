#include <iostream>

class A{
public:
    virtual void teste() = 0;
};

class B : public A{
public:
    void teste(int b){
        std::cout << b << "\n";
    }
};

int main(){
    B b;
    b.teste(1);
}