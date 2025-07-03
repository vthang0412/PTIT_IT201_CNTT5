#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

node *creatNode(int x) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
node *insertAtHead(node *head,int x) {
    node *newnode = creatNode(x);
    newnode->next = head;
    return newnode;
}
void *printList(node *head) {
    while (head != NULL) {
        printf("%d",head->data);
        if (head->next != NULL) printf("->");
        head= head->next;
    }
    printf("->NULL");
}
void *printData(node *head) {
    while (head != NULL) {
        printf("data: %d\n",head->data);
        head= head->next;
    }
}
int main() {
    node *head = NULL;
    int n,x;
    printf("Nhap so luong phan tu:");
    scanf("%d",&n);

    for (int i=0;i<n;i++) {
        printf("Nhap phan tu thu %d:",i+1);
        scanf("%d",&x);
        head = insertAtHead(head,x);
    }
    printf("danh sach lien ket:\n");
    printList(head);
    printf("\nCac gia tri trong danh sach:\n");
    printData(head);
    return 0;
}