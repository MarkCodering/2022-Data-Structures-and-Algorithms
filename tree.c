#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root);
void preorder(struct node *root);
int inorderSearch(struct node *root, int key);

// Function to create a new node
int main(void){
    int key = 12;
    //Create a root
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 1;
    //Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    //Assign data to the new node
    newNode->data = 10;
    //Make left and right as NULL
    newNode->left = NULL;
    newNode->right = NULL;

    root->left = newNode;
    root->right = NULL;

    //Tree traversal
    printf("Inorder traversal of the given tree is \n");
    inorder(root);

    printf("\nPreorder traversal of the given tree is \n");
    preorder(root);

    printf("\nSearching for 11 in the given tree \n");
    int answers = inorderSearch(root, key);
    if (answers == key)
        printf("\nElement found\n");
    else
        printf("\nElement not found\n");

    return 0;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d \n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int inorderSearch(struct node *root, int key)
{
    if (root != NULL)
    {
        inorderSearch(root->left, key);
        if (root->data == key)
        {
            printf("Founded: %d \n", root->data);
            return root->data;
        }
        inorderSearch(root->right, key);
    }
}
