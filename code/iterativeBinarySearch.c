#include <stdio.h>
#include <stdbool.h>

int sortedArray [] = {10,15,19,21,24,29,33,35,36,40,46,49};

int iterativeBinarySearch(int value){

    int initPosition = 0;
    int finalPosition = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int mid = (finalPosition + initPosition) / 2;
    
    printf("finalPosition is equal to %d \n", finalPosition);

    while(initPosition <= finalPosition){
        
        printf("mid is equal to %d \n", mid);
        printf("array value is equal to %d \n",sortedArray[mid]);

        if(value > sortedArray[mid]){
            initPosition = mid + 1;          
        }else if(value < sortedArray[mid]){
            finalPosition = mid - 1;                        
        }else {
            return sortedArray[mid];
        }

        printf("init is equal to %d \n", initPosition);      
        printf("final is equal to %d \n", finalPosition);      

        mid = (finalPosition + initPosition) / 2;
    }
    return -1;
}

int main (){
   int value = 66;
   int result = iterativeBinarySearch(value);
   printf("Result is equal %d", result); 
}