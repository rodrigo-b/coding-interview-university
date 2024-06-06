#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct TreeNode {
      int value;
      struct TreeNode *left;
      struct TreeNode *right;
}
TreeNode;

int counterNodes;

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

int getNodeCount(TreeNode* root){

    if(root == NULL){                     
        return 0;
    }
            
    int counter = getNodeCount(root -> left);         

    counter = counter + getNodeCount(root -> right);     

    counter = counter + 1;    
    return counter;

}

void print_values(TreeNode* root){

    if(root == NULL){                     
        return;
    }
            
    print_values(root -> left);     
    printf("node value = %d \n", root->value); 
    print_values(root -> right);     
}

void delete_tree(TreeNode** root){

    if(*root == NULL){           
        return;
    }

    TreeNode *left = (*root) -> left;        
    delete_tree(&left);

    TreeNode *right = (*root) -> right;        
    delete_tree(&right);

    *root = NULL;
    left = NULL;
    right = NULL;

    free(*root);
    free(right);
    free(left);
  
    return;
}

bool is_in_tree(TreeNode* root, int value){

    if(root == NULL){
        return false;
    }

    if(value > root -> value){
        is_in_tree(root -> right, value);
    } else if (value < root -> value){
        is_in_tree(root -> left, value);
    } else {
        return true;
    }
}

int get_height(TreeNode* root){

 if(root == NULL){
        return -1;
 }

  int leftHeight = get_height(root -> left);
  int rightHeight = get_height(root -> right);


  int max = leftHeight > rightHeight ? leftHeight : rightHeight;
  return  max + 1;
}

int get_min(TreeNode* root){

  if(root == NULL){
    return -1;
  } else if(root -> left == NULL){
    return root -> value;
  }

  return get_min(root -> left);  
}


int main() {

    TreeNode* root = NULL;
    
    root = insert(20, root);
    root = insert(10, root);
    root = insert(31, root);
    root = insert(13, root);
    root = insert(45, root);
    root = insert(48, root);
    root = insert(47, root);
    root = insert(9, root);
    root = insert(51, root);
    root = insert(5, root);
    root = insert(19, root);

    printf("total itens = %d \n", getNodeCount(root));
    print_values(root);

    //delete_tree(&root);
    //printf("print value \n");
    //print_values(root);

    printf("Is in tree ? %s \n", is_in_tree(root, 51)? "true" : "false");

    int height = get_height(root);

    printf("height is = %d \n", height);

    int minValue = get_min(root);

    printf("min value = %d \n", minValue);
}