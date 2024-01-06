#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{

    int number;
    struct node *next;

} 
node;

node *head = NULL;

int size(){
    int count = 0;

    node *tmp = head;    
    while(tmp != NULL){        
        tmp = tmp->next;                        
        count += 1;        
    }
    tmp = NULL;
    free(tmp);
    return count;
}

bool empty(){

    if(size() == 0){
        return true;
    }
    return false;
}

int value_at(int index){

    if(index == 1){
        return head-> number;
    }

    node *tmp = malloc(sizeof(node));
    tmp = head;
    for(int i = 0; i < index - 1; i++){
        tmp = tmp->next;
    }

    int result = tmp->number;
    tmp = NULL;
    free(tmp);        
    return result;
}

void push_front(int value){

    if(head == NULL){
        head = malloc(sizeof(node));
        head->number = value;
        head->next = NULL;
    }else {
        node *newNode = malloc(sizeof(node));
        newNode->number = value;
        newNode->next = head;

        head = newNode;
    }   
}

int pop_front(){
    node *auxiliary = head;
    int result = head->number;
    head = head->next;
    free(auxiliary);
    return result;
}

void push_back(int value){
    
    if(head == NULL){
        head = malloc(sizeof(node));
        head->number = value;
        head->next = NULL;
    } else {
        node *newNode = malloc(sizeof(node));
        newNode->number = value;
        newNode->next = NULL;

         node *tmp = head;

         while(tmp->next != NULL){
               tmp = tmp->next;
         }
         tmp->next = newNode;     

         tmp = NULL;
         free(tmp);          
    }    
}

int pop_back() {

    node *tmp = head;
    node *beforeNode = NULL;
    while(tmp->next != NULL)
    {
        beforeNode = tmp;                   
        tmp = tmp->next;                                
    }
  
    int result = tmp -> number;
    beforeNode->next = NULL;
    beforeNode = NULL;
    free(tmp);
    free(beforeNode);
    return result;
}

int front(){

    if(empty() == 0){
        return head -> number;
    }else {
        return 0;
    }

}

int back (){

    if(empty() == 0){

        node *tmp = head;

        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        int finalValue = tmp ->number;
        tmp = NULL;
        free(tmp);
        return finalValue;
    }else {
        return 0;
    }

}

void insert(int index, int value){

    node *newNode = malloc(sizeof(node));
    newNode->number = value;

    if(index == 1){
        newNode -> next = head;
        head = newNode;
        newNode = NULL;
        free(newNode);
    }else {
        node *tmp = malloc(sizeof(node));
        tmp = head;
        node *tmpBefore = malloc(sizeof(node));
        for(int i = 0; i < index - 1; i++){
            tmpBefore = tmp;
            tmp = tmp->next;
        }

        newNode->next = tmp;
        tmpBefore->next = newNode;

        tmp = NULL;
        tmpBefore = NULL;
        newNode = NULL;
        free(tmp);
        free(tmpBefore);
        free(newNode);
    }

}

void erase(int index){

    if(index == 1){
        node *tmp = head->next;
        head = tmp;
        tmp = NULL;
        free(tmp);
    }else {
        node *tmp = malloc(sizeof(node));
        tmp = head;
        node *tmpBefore = malloc(sizeof(node));
        for(int i = 0; i < index - 1; i++){
            tmpBefore = tmp;
            tmp = tmp->next;
        }

        tmpBefore->next = tmp->next;
        tmp = NULL;
        free(tmp);
    }



}

int value_n_from_end(int n){

    node *tmp = malloc(sizeof(node));
    tmp = head;    
    int values [size()];

    for(int i = 0; i < size(); i++){
        values[i] = tmp->number;         
        tmp = tmp->next;
    }

    int result;
    for(int i = size() -1; i >= size() - n; i--){
        printf("value val = %d \n ", values[i]);
        result = values[i];
    }

    tmp = NULL;
    free(tmp);    

    return result;
}

void reverse(){

    node *tmp = malloc(sizeof(node));
    tmp = head;    
    int values [size()];

    for(int i = 0; i < size(); i++){
        values[i] = tmp->number;         
        tmp = tmp->next;
    }

    tmp = NULL;
    tmp = head;
    for(int i = size() -1; i >= 0; i--){
        tmp ->number = values[i];          
        tmp = tmp->next;
    }

    tmp = NULL;
    free(tmp);
}

void remove_value(int value){

    if(head->number == value){
        node *tmp = head->next;
        head = tmp;
        tmp = NULL;
        free(tmp);
    }else {
        node *tmp = malloc(sizeof(node));
        tmp = head;
        node *tmpBefore = malloc(sizeof(node));
        for(int i = 0; i < size() - 1; i++){
            tmpBefore = tmp;
            tmp = tmp->next;
            if(tmp -> number == value){
                break;
            }
        }
        tmpBefore->next = tmp->next;
        tmp = NULL;
        free(tmp);
    }


}

int main () {

    push_front(1);
    push_front(2);
    printf("size is %d \n" , size());
    printf("size is %d \n" , size());

    printf("isEmpty ? %d \n" , empty());

    int index = 2;
    printf("ValueAt index 2  ? %d \n" , value_at(index));

    printf("result of pop front = %d \n", pop_front());
    printf("result of pop front = %d \n", pop_front());
    printf("size is %d \n" , size());

    push_back(3);
    push_back(4);
    push_back(5);
    push_back(6);

    printf("size is %d \n" , size());
    printf("ValueAt index 1  ? %d \n" , value_at(1));
    printf("ValueAt index 2  ? %d \n" , value_at(2));
    printf("ValueAt index 3  ? %d \n" , value_at(3));
    printf("ValueAt index 4  ? %d \n" , value_at(4));

    printf("pop back value  ? %d \n" , pop_back());

    printf("size is %d \n" , size());

    printf("front value is %d \n" , front());
    printf("back value is %d \n" , back());
    insert(1,20);
    printf("size is %d \n" , size());
    printf("ValueAt index 1  ? %d \n" , value_at(1));
    printf("ValueAt index 2  ? %d \n" , value_at(2));
    printf("ValueAt index 3  ? %d \n" , value_at(3));
    printf("ValueAt index 4  ? %d \n" , value_at(4));
    printf("\n");
    insert(1,21);
    printf("ValueAt index 1  ? %d \n" , value_at(1));
    printf("ValueAt index 2  ? %d \n" , value_at(2));
    printf("ValueAt index 3  ? %d \n" , value_at(3));
    printf("ValueAt index 4  ? %d \n" , value_at(4));
    printf("ValueAt index 5  ? %d \n" , value_at(5));
    printf("\n");
    insert(3,30);
    insert(5,33);
    printf("ValueAt index 1  ? %d \n" , value_at(1));
    printf("ValueAt index 2  ? %d \n" , value_at(2));
    printf("ValueAt index 3  ? %d \n" , value_at(3));
    printf("ValueAt index 4  ? %d \n" , value_at(4));
    printf("ValueAt index 5  ? %d \n" , value_at(5));
    printf("ValueAt index 6  ? %d \n" , value_at(6));
    printf("ValueAt index 7  ? %d \n" , value_at(7));
    erase(1);
    erase(4);
    printf("erased position 1 and 4 \n");
    printf("\n");
    printf("ValueAt index 1  ? %d \n" , value_at(1));
    printf("ValueAt index 2  ? %d \n" , value_at(2));
    printf("ValueAt index 3  ? %d \n" , value_at(3));
    printf("ValueAt index 4  ? %d \n" , value_at(4));
    printf("ValueAt index 5  ? %d \n" , value_at(5));
    printf("size is %d \n" , size());
    printf("value from end position with n equal 3 = %d \n",value_n_from_end(3));
    printf("value from end position with n equal 2 = %d \n",value_n_from_end(2));
    printf("value from end position with n equal 1 = %d \n",value_n_from_end(1));
    reverse();
    printf("list reversed  \n");
    printf("ValueAt index 1  ? %d \n" , value_at(1));
    printf("ValueAt index 2  ? %d \n" , value_at(2));
    printf("ValueAt index 3  ? %d \n" , value_at(3));
    printf("ValueAt index 4  ? %d \n" , value_at(4));
    printf("ValueAt index 5  ? %d \n" , value_at(5));
    printf("remove value 30 \n");
    remove_value(30);
    printf("size is %d \n" , size());
    printf("ValueAt index 1  ? %d \n" , value_at(1));
    printf("ValueAt index 2  ? %d \n" , value_at(2));
    printf("ValueAt index 3  ? %d \n" , value_at(3));
    printf("ValueAt index 4  ? %d \n" , value_at(4));
    
}