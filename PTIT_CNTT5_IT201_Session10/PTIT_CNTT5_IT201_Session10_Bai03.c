#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

node *createNode(int x) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
node *insertAtTail(node *head,int x) {
    node *newNode = createNode(x);
    if (head == NULL) return newNode;
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void *printList(node *head) {
    printf("DSLK them cuoi:\n");
    while (head != NULL) {
        printf("%d -> ",head->data);
        head = head->next;
    }
    printf("NULL");
}
int main() {
    node *head = NULL;
    int n,x;
    printf("Nhap so luong phan tu:");
    scanf("%d",&n);

    for (int i=0;i<n;i++) {
        printf("Nhap phan tu thu %d:",i+1);
        scanf("%d",&x);
        head = insertAtTail(head,x);
    }
    printList(head);
    return 0;
}