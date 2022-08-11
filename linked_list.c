#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printList(struct node *head);
void searchTarget(struct node *head, int key);
void insertFromTail(struct node *head, int input);
struct node* insertFromHead(struct node *head, int inputHead);
void deleteForTail(struct node *head);
void deleteTarget(struct node *head, int key);
void sortList(struct node *head);

int main(void){
    struct node *head = NULL;
    struct node *node1 = (struct node*)malloc(sizeof(struct node));
    struct node *node2 = (struct node*)malloc(sizeof(struct node));

    head = node1;
    node1->data = 1;
    node1->next = node2;

    node2->data = 8;
    node2->next = NULL;

    printList(head);
    printf("\n");

    //searchTarget(head, 8);
    //printf("\n");

    insertFromTail(head, 5);
    printList(head);
    printf("\n");

    head = insertFromHead(head, 10);
    printList(head);
    printf("\n");

    sortList(head);
    printList(head);
    printf("\n");

    deleteForTail(head);
    printList(head);
    printf("\n");

    deleteTarget(head, 1);
    printList(head);
    printf("\n");

    return 0;
}

void printList(struct node *head){
    while (head!=NULL)
    {
        /* code */
        printf("%d ", head->data);
        head = head->next;
    }
}

void searchTarget(struct node *head, int key){
    while(head!=NULL){
        if(key==head->data){
            printf("Key Founded: %d", head->data);
        }
        head = head->next;
    }

    printf("Target Not Found\n");
}

void insertFromTail(struct node *head, int input){
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    while(head!=NULL){
        if(head->next == NULL){
            head->next = temp;
            temp->data = input;
            temp->next = NULL;        
        }

        head = head->next;
    }
}

struct node* insertFromHead(struct node *head, int inputHead){
    struct node *temp = (struct node*)malloc(sizeof(struct node));

    //Insert a node from head
    temp->data = inputHead;
    temp->next = head;
    head = temp;

    return head;
}

void deleteForTail(struct node *head){
    //Delete a node from tail
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

void  deleteTarget(struct node *head, int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==key){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void sortList(struct node *head){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    while(temp->next!=NULL){
        if(temp->data > temp->next->data){
            int tempData = temp->data;
            temp->data = temp->next->data;
            temp->next->data = tempData;
        }
        temp = temp->next;
    }
}