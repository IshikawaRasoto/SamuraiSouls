// #include <iostream>

// namespace Math{

// template<typename T>
// class Vector2{
// public:
//     T x;
//     T y;

//     Vector2(T x, T y);
//     Vector2();
//     ~Vector2(){}

//     void operator=(Vector2<T> other);
//     void operator+=(Vector2<T> other);
//     void operator-=(Vector2<T> other);
//     void operator/=(Vector2<T> other);
//     void operator*=(Vector2<T> other);
//     void operator*=(double multiplier);
//     void operator/=(double divider);

//     Vector2<T> operator+(Vector2<T> other);
//     Vector2<T> operator-(Vector2<T> other);
//     Vector2<T> operator/(Vector2<T> other);
//     Vector2<T> operator/(double divider);
//     Vector2<T> operator*(Vector2<T> other);
//     Vector2<T> operator*(double multiplier);
// };

// typedef Vector2<float> Vector2f;
// typedef Vector2<double> Vector2d;
// typedef Vector2<int> Vector2i;
// typedef Vector2<unsigned int> Vector2ui;

// template<typename T>
// Vector2<T>::Vector2(T x, T y): 
//     x(x), y(y)
// {}

// template<typename T>
// Vector2<T>::Vector2(){
//     x = 0;
//     y = 0;
// }

// template<typename T>
// void Vector2<T>::operator=(Vector2<T> other){
//     x = other.x;
//     y = other.y;
// }


// template<typename T>
// void Vector2<T>::operator+=(Vector2<T> other){
//     x += other.x;
//     y += other.y;
// }

// template<typename T>
// void Vector2<T>::operator-=(Vector2<T> other){
//     x -= other.x;
//     y -= other.y;
// }

// template<typename T>
// void Vector2<T>::operator/=(Vector2<T> other){
//     if(other.x == 0 || other.y == 0){
//         std::cout << "[Vector2] Erro ao dividir um Vector2 por outro Vector2. Não é possível dividir por zero.\n";
//         return;
//     }

//     x /= other.x;
//     y /= other.y;
// }

// template<typename T>
// void Vector2<T>::operator*=(Vector2<T> other){
//     x *= other.x;
//     y *= other.y;
// }

// template<typename T>
// void Vector2<T>::operator*=(double multiplier){
//     x *= multiplier;
//     y *= multiplier;
// }

// template<typename T>
// void Vector2<T>::operator/=(double divider){

//     if(divider == 0.0f){
//         std::cout << "[Vector2] Erro ao dividir um Vector2 por escalar. Não é possível dividir por zero.\n";    
//         return;    
//     }   

//     x /= divider;
//     y /= divider;
// }

// template<typename T>
// Vector2<T> Vector2<T>::operator+(Vector2<T> other){
//     return Vector2(x+other.x, y+other.y);
// }

// template<typename T>
// Vector2<T> Vector2<T>::operator-(Vector2<T> other){
//     return Vector2(x-other.x, y-other.y);
// }

// template<typename T>
// Vector2<T> Vector2<T>::operator/(Vector2<T> other){

//     if(other.x == 0 || other.y == 0){
//         std::cout << "[Vector2] Erro ao dividir um Vector2 por outro Vector2. Não é possível dividir por zero.\n";
//         return Vector2(-1,-1);
//     }

//     return Vector2(x/other.x, y/other.y);
// }

// template<typename T>
// Vector2<T> Vector2<T>::operator/(double divider){

//     if(divider == 0){
//         std::cout << "[Vector2] Erro ao dividir um Vector2 por escalar. Não é possível dividir por zero.\n";
//         return Vector2(-1,-1);
//     }

//     return Vector2(x/divider, y/divider);
// }

// template<typename T>
// Vector2<T> Vector2<T>::operator*(Vector2<T> other){
//     return Vector2(x*other.x, y*other.y);
// }

// template<typename T>
// Vector2<T> Vector2<T>::operator*(double multiplier){
//     return Vector2(x*multiplier, y*multiplier);
// }

// }

