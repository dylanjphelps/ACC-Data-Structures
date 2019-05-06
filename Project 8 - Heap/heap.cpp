#include "heap.h"

void percolateDown(int array[], int size, int root){
     int tmp;
     int child = 2*root;
     while(child <= size){

             if (child <= size && array[child] < array[child+1]){
                       child++;
             }
             if(array[root] < array[child]){
                            tmp = array[root];
                            array[root] = array[child];
                            array[child] = tmp;
                            root = child;
                            child = 2* child;
             }
             else{
                  break;
             }
     }
}

void heapify(int array[], int size){
     for(int i = size / 2; i > 0; i--){
            percolateDown(array, size, i);
     }
}







