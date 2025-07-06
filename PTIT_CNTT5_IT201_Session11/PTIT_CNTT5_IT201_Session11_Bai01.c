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
    if (head != NULL) head->prev = newNode;
    return newNode;
}
void printList(Node *head) {
    printf("\nNULL <-> ");
    while (head != NULL) {
        printf("%d <-> ",head->data);
        head= head->next;
    }
    printf("NULL");
}
int main() {
    Node *head = NULL;
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