#include <stdio.h>
#include <stdbool.h>
#define arraySize 5

int array [arraySize];
int read = 0;
int write = 0;

bool empty () {
    if(array[read] == 0){
        return true;
    } else {
        return false;
    }        
}

bool full() {

    if(empty()){
        return false;
    } else {
        return write % arraySize == read;
    }    
}

void enqueue(int value){

    if(full()){
        printf("Array is full, nothing was done \n");
    } else {
        array[write] = value;        
        write = (write + 1) % arraySize;        
    }
}

int dequeue (){

    if(empty()){
        return -10000;
    }else {
        int result = array[read];
        array[read] = 0;
        read = (read + 1) % arraySize;
        return result;
    }
}
    
int main() {

        printf("queue is empty ? %d \n", empty());
        printf("queue is full ? %d \n", full());
        enqueue(1);
        enqueue(2);
        enqueue(3);
        enqueue(4);
        enqueue(5);
        printf("queue is full ? %d \n", full());
        printf("queue is empty ? %d \n", empty());
        printf("dequeue result = %d \n", dequeue());
        printf("dequeue result = %d \n", dequeue());
        printf("dequeue result = %d \n", dequeue());
        printf("dequeue result = %d \n", dequeue());
        printf("dequeue result = %d \n", dequeue());
        printf("queue is full ? %d \n", full());
        printf("queue is empty ? %d \n", empty());
        enqueue(6);
        enqueue(7);
        enqueue(8);
        printf("dequeue result = %d \n", dequeue());
        enqueue(9);
        enqueue(10);
        enqueue(11);
        enqueue(12);
}





