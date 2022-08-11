#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int listLens(int array[]);
struct node* insert(struct node *root, int input);
void printTree_inorder(struct node *root);

int main(){
    //Initialize an array for the heap
    int array[] = {1, 23, 14, 54, 3};
    int lens = sizeof(array)/sizeof(array[0]);
    //printf("%u\n", lens);

    //Initialize a root node
    struct node *root = (struct node *)malloc(sizeof(struct node));
    for (int i = 0; i < lens; i++){
        root = insert(root, array[i]);
    }
    //Inserting the nodes into the tree in the correct order (Max Heap)s
    printTree_inorder(root);

    return 0;
}

struct node* insert(struct node *root, int input){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = input;
    newNode->left = NULL;
    newNode->right = NULL;
    if(root == NULL){
        root = newNode;
        return root;
    }
    struct node *temp = root;
    while(temp != NULL){
        if(temp->data > input){
            if(temp->left == NULL){
                temp->left = newNode;
                return root;
            }
            temp = temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right = newNode;
                return root;
            }
            temp = temp->right;
        }
    }
    return root;
}

void printTree_inorder(struct node *root){
    if (root != NULL)
    {
        printTree_inorder(root->left);
        printf("%d \n", root->data);
        printTree_inorder(root->right);
    }
}