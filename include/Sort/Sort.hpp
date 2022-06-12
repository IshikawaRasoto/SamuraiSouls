#pragma once

#include <vector>

template<class T>
class Sort{
public:
    static void quickSortWithPointers(std::vector<T> &v);
    static void quickSortWithPointers(std::vector<T> &v, int begin, int end);
};

template<class T>
void Sort<T>::quickSortWithPointers(std::vector<T> &v){
    quickSortWithPointers(v, 0, v.size()-1);
}

template<class T>
void Sort<T>::quickSortWithPointers(std::vector<T> &v, int begin, int end){

    int i = begin,
        j = end;

    T pivot = v[(end+begin)/2],
      aux;

    while (i <= j){

        while((*v[i]) > *pivot) i++;
        while((*v[j]) < *pivot) j--;

        if(i <= j){
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;

            i++;
            j--;
        }   
    }
    
    if(j > begin) quickSortWithPointers(v, begin, j);
    if(i < end) quickSortWithPointers(v, i, end);
}