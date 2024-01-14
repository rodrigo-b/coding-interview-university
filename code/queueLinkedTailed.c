#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    struct node *next;
    int value;
}  
node;

node *head = NULL;
node *tail = NULL;

void enqueue (int newValue){

    if(head == NULL){
        head = malloc(sizeof(node));
        tail = malloc(sizeof(node));

        head->value = newValue;
        head-> next = NULL;
        tail->value = newValue;
        tail->next = NULL;
    }else{
        node *tmp = malloc(sizeof(node));
        tmp -> value = newValue;
        tmp -> next = NULL;

        tail -> next = tmp;
        tail = tail -> next;

        tmp = NULL;
        free(tmp);

        if(head -> next == NULL){
            head->next = tail;
        }
    }


}

int dequeue (){

    if(head == NULL){
        return -10000;
    }

    int result = 0;
    if(head -> next != NULL){        
        node * tmp = malloc(sizeof(node));
        tmp = head;
        head = head -> next;
        result  = tmp-> value;
        free(tmp);
    } else {     
        result = head->value;
        free(head);
        head = NULL;
        tail = NULL;
    }

    return result;
}

bool empty(){

    if(head == NULL){
        return true;
    } else{
        return false;
    }
    
}

int main () {
    printf("queue is empty ? %d \n", empty());
    enqueue(1);
    printf("queue is empty ? %d \n", empty());
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("queue is empty ? %d \n", empty());
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());
    printf("dequeue result = %d \n", dequeue());

} 