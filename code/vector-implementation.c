
#include <stdio.h>
#include <stdbool.h>

int totalElements = 16;
int totalCapacity = 16;
int inputs [16];
int itensInArray = 0;

int size() {
    return itensInArray;
}

int capacity(){
    return totalCapacity;
}

bool is_empty(){
    if(size() == capacity()){
        return true;
    }else {
        return false;
    }
}

int at(int index){
    return inputs[index];
}

void push(int item){

    for(int i = 0; i < totalElements; i++){
    
      if(inputs[i] == 0){
        inputs[i] = item;
        totalCapacity -= 1;
        itensInArray += 1;
        return;
      }
    }
}

void insert(int index, int item){

    for(int i = index; i< totalElements; i++){
        printf("caindo no for com i = %d", i);
        int valueToNextIndex = inputs[i];
        inputs[i] = item;
        item = valueToNextIndex;
        totalCapacity -= 1;
        totalElements += 1;
        if(item == 0){
            return;
        }
    }
}

void prepend(int item){
    insert(0, item);
}

int pop (){
    if (is_empty() == false){
        int result = inputs[totalElements-1];
        inputs[totalElements-1] = 0;
        return result;
    }
}

int main() {

    // printf("input on 5 position default is %d \n", inputs[7]);
    
    // printf("capacity is %d \n", capacity());
    // printf("size is %d \n", size());

    // for(int i = 1; i <= totalElements; i++){
    //     push(i);
    //     printf("capacity is %d \n", capacity());
    //     printf("size is %d \n", size());
    // }



    push(1);
    push(2);
    push(3);
    push(4);
    insert(2,8);

    for(int i = 0; i < 16; i++){
        printf("valor do array é %d \n", inputs[i]);
    }

    int lastResult = pop();
    printf("valor do pop é %d \n", lastResult);

        for(int i = 0; i < 16; i++){
        printf("valor do array é %d \n", inputs[i]);
    }
}

