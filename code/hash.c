#include <stdio.h>
#include <stdbool.h>

long prime = 98923130209997;
long a = 34243249843;
long b = 83999900009;
long hashTable [10];
long size = 10;


int hash(long value , long size){
    int result = (int) (((a * value) + b) % prime ) % size;
    return result;
}

void add(int key, long value){
    int index = hash(key, size);
    hashTable[index] = value;
}

bool exists(int key){
    int index = hash(key, size);
    if(hashTable[index] != 0){
        return true;
    }

    return false;
}

long get(long key){
   return hashTable[hash(key,size)];
}

void removeItem(long key){
    int index = hash(key, size);
    hashTable[index] = 0;
}

int main (){
    int size = 10;

   add(1 , 422125);

   bool exist = exists(5);
   printf( "exists   is equal to = %d \n", exist);
   printf( "value get is equal to = %d \n", get(1));
   removeItem(1);
   printf( "value get is equal to after removed = %d \n", get(1));

}