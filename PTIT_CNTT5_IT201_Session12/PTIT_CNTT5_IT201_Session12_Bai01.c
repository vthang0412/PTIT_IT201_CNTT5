#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node *createNode(int x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
Node *insertAtHead(Node *head,int x) {
    Node *newNode = createNode(x);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}
void printList(Node *head) {
    while (head!= NULL) {
        printf("%d <-> ",head->data);
        head = head->next;
    }
    printf("NULL");
}
int main() {
    Node *head = NULL;
    int n,x;
    printf("Nhap so luong phan tu:");
    scanf("%d",&n);

    for (int i=0;i<n;i++) {
        printf("Nhap phan tu thu %d:",i+1);
        scanf("%d",&x);
        head = insertAtHead(head,x);
    }
    printList(head);
    return 0;
}