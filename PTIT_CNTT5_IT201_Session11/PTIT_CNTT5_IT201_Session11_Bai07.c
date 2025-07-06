#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *insertAtTail(Node *head, int value) {
    Node *newNode = createNode(value);
    if (head == NULL) return newNode;

    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node *insertAtPosition(Node *head, int value, int pos) {
    if (pos <= 0) return head;
    Node *newNode = createNode(value);

    if (pos == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    Node *current = head;
    int count = 1;

    while (current != NULL && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL)
        current->next->prev = newNode;

    current->next = newNode;

    return head;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    head = insertAtTail(head, 1);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);

    printf("Danh sach ban dau:\n");
    printList(head);

    int value, pos;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them: ");
    scanf("%d", &pos);

    head = insertAtPosition(head, value, pos);

    printf("Danh sach sau khi them:\n");
    printList(head);

    return 0;
}
