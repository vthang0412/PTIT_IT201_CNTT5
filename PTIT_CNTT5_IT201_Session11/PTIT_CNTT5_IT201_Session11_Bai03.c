#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *insertAtTail(Node *head, int x) {
    Node *newNode = createNode(x);
    if (head == NULL) return newNode;

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printList(Node *head) {
    printf("\nNULL <-> ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int searchList(Node *head, int target) {
    while (head != NULL) {
        if (head->data == target)
            return 1;
        head = head->next;
    }
    return 0;
}

int main() {
    Node *head = NULL;
    int n, value;

    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri thu %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtTail(head, value);
    }

    printList(head);

    int search;
    printf("Nhap so can tim: ");
    scanf("%d", &search);

    if (searchList(head, search))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
