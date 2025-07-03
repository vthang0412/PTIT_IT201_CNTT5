#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;
node *createNode(int x) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
node *insertAtHead(node *head,int x) {
    node *newnode = createNode(x);
    newnode->next = head;
    return newnode;
}
node *deleteChoice(node *head, int x) {
    while (head != NULL && head->data == x) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    if (head == NULL) return NULL;

    node *prev = head;
    node *curr = head->next;

    while (curr != NULL) {
        if (curr->data == x) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

void printList(node *head) {
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
    int xoa;
    printf("\nNhap gia tri muon xoa: ");
    scanf("%d", &xoa);

    head = deleteChoice(head, xoa);

    printf("Danh sach sau khi xoa %d la:\n", xoa);
    printList(head);

    return 0;
}