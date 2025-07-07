#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int x) {
    Node *newNode = (Node *) malloc(sizeof(Node));
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

Node *deleteAtTail(Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

void printList(Node *head) {
    printf("\n");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {
    Node *head = NULL;
    int n, x;
    printf("Nhap so luong phan tu:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d:", i + 1);
        scanf("%d", &x);
        head = insertAtTail(head, x);
    }
    printList(head);
    printf("\nXoa node cuoi danh sach:\n");
    head = deleteAtTail(head);
    printList(head);
    return 0;
}
