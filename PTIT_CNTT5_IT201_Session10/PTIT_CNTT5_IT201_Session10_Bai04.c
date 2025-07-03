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
node *deleteAtTail(node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
void *printList(node *head) {
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
        head = insertAtHead(head,x);
    }
    printf("Danh sach lien ket ban dau:\n");
    printList(head);
    head = deleteAtTail(head);
    printf("\nSau khi xoa:\n");
    printList(head);
    return 0;
}