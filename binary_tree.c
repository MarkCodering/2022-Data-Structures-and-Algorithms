#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void search(struct node *root, int target){
    while(root!=NULL){
        if(root->data == target){
            printf("%d is found\n", target);
            return;
        }else{
            if(target < root->data){
                root = root->left;
            }else{
                root = root->right;
            }
        }
    }
    printf("%d is not found\n", target);
}

int main()
{
    // Level 1: Root Level
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    // Level 2:
    struct node *leftL2Node = (struct node *)malloc(sizeof(struct node));
    struct node *rightL2Node = (struct node *)malloc(sizeof(struct node));

    leftL2Node->data = 23;
    root->left = leftL2Node;
    root->right = rightL2Node;

    // Right side of level 2
    rightL2Node->data = 14;
    rightL2Node->left = NULL;
    rightL2Node->right = NULL;

    struct node *leftL3Node_L = (struct node *)malloc(sizeof(struct node));
    struct node *leftL3Node_R = (struct node *)malloc(sizeof(struct node));

    leftL3Node_L->data = 54;
    leftL2Node->left = leftL3Node_L;
    leftL2Node->right = leftL3Node_R;
    leftL3Node_L->left = NULL;
    leftL3Node_L->right = NULL;

    leftL3Node_R->data = 3;
    leftL3Node_R = NULL;
    leftL3Node_R = NULL;

    inorder(root);
    printf("\n");

    search(root, 3);

    return 0;
}