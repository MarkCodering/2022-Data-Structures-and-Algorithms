#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void traverse(struct node *root);
void insert(struct node *root, int data);
void assignNewProirity(struct node *root, int curData, int newData);
void organizeProirity(struct node *root);

int main(void){
    //Create a max heap for priority queue
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    struct node *curr = root;
    struct node *prev = NULL;

    //Insert elements into the max heap
    for(int i = 2; i < 10; i++){
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = i;
        newNode->left = NULL;
        newNode->right = NULL;
        if(curr->data > newNode->data){
            curr->left = newNode;
            curr = curr->left;
        }else{
            curr->right = newNode;
            curr = curr->right;
        }
    }
    //Print the max heap
    printf("Max heap: ");
    traverse(root);
    printf("\n");

    //Assign an new priority to the element of 3 to be 1
    assignNewProirity(root, 3, 1);
    printf("Max heap: ");
    traverse(root);
    printf("\n");
    organizeProirity(root);
    printf("Max heap: ");
    traverse(root);
    printf("\n");

    return 0;
}

void assignNewProirity(struct node *root, int curData, int newData){
    //Assign new priority to the node with curData
    if(root == NULL){
        return;
    }
    if(root->data == curData){
        root->data = newData;
        return;
    }
    assignNewProirity(root->left, curData, newData);
    assignNewProirity(root->right, curData, newData);
}

void organizeProirity(struct node *root){
    //Organize the priority of the max heap
    if(root == NULL){
        return;
    }
    if(root->left != NULL){
        organizeProirity(root->left);
    }
    if(root->right != NULL){
        organizeProirity(root->right);
    }
    if(root->left != NULL && root->left->data > root->data){
        int temp = root->data;
        root->data = root->left->data;
        root->left->data = temp;
    }
    if(root->right != NULL && root->right->data > root->data){
        int temp = root->data;
        root->data = root->right->data;
        root->right->data = temp;
    }
}

void traverse(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    traverse(root->left);
    traverse(root->right);
}

void insert(struct node *root, int data){
    if(root == NULL){
        return;
    }
    if(data < root->data){
        if(root->left == NULL){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->left = newNode;
        }else{
            insert(root->left, data);
        }
    }else{
        if(root->right == NULL){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->right = newNode;
        }else{
            insert(root->right, data);
        }
    }
}