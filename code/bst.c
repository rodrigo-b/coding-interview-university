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

TreeNode* get_max(TreeNode* root){

    if(root == NULL){
        TreeNode* nullNode = NULL;
        return nullNode;
    }

    while(root -> right != NULL){
        root = root -> right;
    }

    return root;
}

bool is_binary_search_tree(TreeNode* root, int min, int max){

    if(root == NULL){
        return true;
    }
    
    is_binary_search_tree(root -> left, min , root -> value);
    is_binary_search_tree(root -> right,root->value , max);        

    printf("root value = %d \n", root -> value);
    printf("min value = %d \n", min);
    printf("max value = %d \n", max);

    if(root -> value > min || root -> value < max){        
        return true;
    }

    return false;
}

TreeNode* delete(TreeNode* root,int data){

    if(root == NULL){    
        return root;
    }
    
    if(data > root -> value){
        root -> right = delete(root -> right, data);
    } else if (data < root -> value){
        root -> left = delete(root -> left, data);
    } else {

        if(root -> left == NULL && root -> right == NULL){
            root = NULL;
            free(root);                      
        } else if(root -> left == NULL){
            TreeNode* tmp = malloc(sizeof(TreeNode));
            tmp = root;
            root = root -> right;
            tmp = NULL;
            free(tmp);
        } else if(root -> right == NULL){
            TreeNode* tmp = malloc(sizeof(TreeNode));
            tmp = root;
            root = root -> left;
            tmp = NULL;
            free(tmp);
        }else {            
            TreeNode* max = malloc(sizeof(TreeNode));        
            max = get_max(root -> left);    
            root -> value = max -> value;                    
            root -> left = delete(root -> left, max -> value);            
        }        
    }

    return root; 
}

int get_sucessor(TreeNode* root,int data){

    if(root == NULL){
        return -1;
    }

    int sucessor = get_sucessor(root -> left, data);

    if(root -> value > data && sucessor < data){
        return root -> value;
    } else if(sucessor == -1){
        sucessor = get_sucessor(root -> right, data);
    }

    return sucessor;
}

//pseudocode for a better implementation
int get_sucessor_2(TreeNode* root , int data){

       if(root == NULL){
       return -1;
       }

      //TreeNode* node = findRoot(root);
      // if(node -> right != NULL){
      // return findMin(node -> right);
      //}
      //else {

        //TreeNode* sucessor = NULL;
        //TreeNode* ancestor = root;

        //while(ancestor != current){

            //if(node -> data < ancestor -> data){
                //sucessor = ancestor;
              //  ancestor = ancestor -> left;
            //} else {
             //   ancestor = ancestor -> right;
          //  }

        //}

        //return sucessor -> value;

      //}
      return 0;
}

int main() {

    TreeNode* root = NULL;
    
    root = insert(20, root);
    root = insert(12, root);
    root = insert(31, root);
    root = insert(13, root);
    root = insert(45, root);
    root = insert(48, root);
    root = insert(47, root);
    root = insert(9, root);
    root = insert(51, root);
    root = insert(5, root);
    root = insert(19, root);
    root = insert(6, root);
    root = insert(11, root);
    root = insert(10, root);

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

    TreeNode* rootWithMaxValue = get_max(root);

    printf("max value = %d \n", rootWithMaxValue -> value);

    printf("is_binary_search_tree = %s \n", is_binary_search_tree(root,-999999,99999) ? "true": "false");

    //delete(root, 12);
    print_values(root);

    printf("Sucessor is equal to %d \n", get_sucessor(root,10));
    //printf("is_binary_search_tree = %s \n", is_binary_search_tree(root,-999999,99999) ? "true": "false");

}