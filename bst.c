#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createBST(int *list, int size);
void printBST(struct node *root);
void printBSTIterative(struct node *root);
void searchBST(struct node *root, int data);
int searchBSTIterative(struct node *root, int data);
void insertBST(struct node *root, int data);

int main(void){
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;

    // Create a tree like this:
    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7
    int list[] = {2, 4, 5, 6, 7, 3};
    int lens = sizeof(list)/sizeof(list[0]);
    //printf("Creating a BST with %d elements\n", lens);
    root = createBST(list, lens);
    printBSTIterative(root);
    printf("\n");
    if(searchBSTIterative(root, 0) == -1){
        printf("0 is found\n");
        insertBST(root, 0);
        printBSTIterative(root);
        printf("\n");
    }

    return 0;
}

//Create a Binary Search Tree from the given list
struct node *createBST(int *list, int size){
    if(size == 0){
        return NULL;
    }
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = list[0];
    root->left = createBST(list+1, size-1);
    root->right = createBST(list+1, size-1);
    return root;
}

//Insert a node into the BST
void insertBST(struct node *root, int data){
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
            insertBST(root->left, data);
        }
    }else{
        if(root->right == NULL){
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->right = newNode;
        }else{
            insertBST(root->right, data);
        }
    }
}

void printBST(struct node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    printBST(root->left);
    printBST(root->right);
}

void printBSTIterative(struct node *root){
    if(root == NULL){
        return;
    }
    struct node *curr = root;
    struct node *prev = NULL;
    while(curr != NULL){
        printf("%d ", curr->data);
        if(curr->left == NULL){
            curr = curr->right;
        }else{
            prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
}

void searchBST(struct node *root, int data){
    if(root == NULL){
        return;
    }
    if(root->data == data){
        printf("%d found\n", data);
        return;
    }
    searchBST(root->left, data);
    searchBST(root->right, data);

    //Turn not found into a recursive function
    printf("%d not found\n", data);
}

int searchBSTIterative(struct node *root, int data){
    while(root != NULL){
        if(root->data == data){
            printf("%d found\n", data);
            return 1;
        }else{
            if(data < root->data){
                root = root->left;
            }else{
                root = root->right;
            }
        }
    }
    printf("%d not found\n", data);

    return -1;
}