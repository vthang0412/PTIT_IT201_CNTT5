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
node *insertAtHead(node *head,int x) {
    node *newnode = createNode(x);
    newnode->next = head;
    return newnode;
}
void *printList(node *head){
    printf("Danh sach lien ket:\n");
    while (head != NULL) {
        printf("%d ",head->data);
        head = head->next;
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
    printList(head);
    return 0;
}