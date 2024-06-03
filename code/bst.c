#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
      int value;
      struct TreeNode *left;
      struct TreeNode *right;
}
TreeNode;


TreeNode* insert(int value, TreeNode* root){

if(root == NULL){
        root = malloc(sizeof(TreeNode));
        root->value = value;
        root-> left = NULL;
        root -> right = NULL;
        return root;
    } 

     TreeNode* temp = malloc(sizeof(TreeNode));
    TreeNode* aux = malloc(sizeof(TreeNode));

    temp = root;

    while(temp != NULL){
        
        if(value > temp -> value ){            
            if(temp -> right == NULL){                
                aux -> value = value;
                aux -> left = NULL;
                aux -> right = NULL;
                temp -> right = aux;
                break;
            }
            temp = temp->right;
        }else if(value <= temp -> value) {
            if(temp -> left == NULL){
                aux -> value = value;
                aux -> left = NULL;
                aux -> right = NULL;
                temp -> left = aux;
                break;
            }
            temp = temp->left;
        }        
    }   

    temp = NULL;
    aux = NULL;
    free(temp);
    free(aux);
    return root;

}

int main() {

    TreeNode* root = malloc(sizeof(TreeNode));
    insert(20, root);

}