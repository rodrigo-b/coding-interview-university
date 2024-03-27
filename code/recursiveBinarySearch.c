#include <stdio.h>
#include <stdbool.h>

int sortedArray [] = {10,15,19,21,24,29,33,35,36,40,46,49};

int recursiveBinarySearch(int lo, int hi, int value){

    int mid = lo + (hi - lo) / 2;

    if(lo > hi){
        return -1;
    } else if(value > sortedArray[mid]){
        return recursiveBinarySearch((mid + 1),hi,value);
    } else if(value < sortedArray[mid]){
        return recursiveBinarySearch(lo, mid - 1,value);
    } else if(value == sortedArray[mid]){
        return sortedArray[mid];
    }    
}

int main (){

    int lo = 0;
    int hi = sizeof(sortedArray) / sizeof(sortedArray[0]);
   //{10,15,19,21,24,29,33,35,36,40,46,49};

    int value = 50;
    int result = recursiveBinarySearch(lo,hi,value);


    printf("Result equal to %d \n", result);

}