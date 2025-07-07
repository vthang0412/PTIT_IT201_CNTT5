#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *createNode(int x) {
    node *newNode = (node *) malloc(sizeof(node));
    if (!newNode) {
        printf("Cap phat bo nho that bai!\n");
        exit(1);
    }
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

node *insertAtTail(node *head, int x) {
    node *newNode = createNode(x);
    if (head == NULL) return newNode;

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(node *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sortList(node *head) {
    if (head == NULL) return;

    for (node *i = head; i != NULL; i = i->next) {
        for (node *j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void freeList(node *head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    node *head = NULL;
    int n, x;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &x);
        head = insertAtTail(head, x);
    }

    printf("Danh sach truoc khi sap xep:\n");
    printList(head);

    sortList(head);

    printf("Danh sach sau khi sap xep tang dan:\n");
    printList(head);

    freeList(head);
    return 0;
}
