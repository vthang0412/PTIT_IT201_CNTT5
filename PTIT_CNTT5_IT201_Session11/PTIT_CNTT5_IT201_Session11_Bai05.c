#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}node;
node *createNode(int x) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
node *insertAtHead(node *head,int x) {
    node *newNode = createNode(x);
    newNode->next=head;
    if (head!=NULL) head->prev=newNode;
    return newNode;
}
void printList(node *head) {
    while (head!=NULL) {
        printf("%d <-> ",head->data);
        head = head->next;
    }
    printf("NULL");
}
int main() {
    node *head = NULL;
    int n,value;
    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtHead(head, value);
    }
    printList(head);
}