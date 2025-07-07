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
Node *insertAtTail(Node *head,int x) {
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
Node* deleteByValue(Node* head, int value) {
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;

        if (current->data == value) {
            if (current == head) {
                head = nextNode;
                if (head != NULL) head->prev = NULL;
            } else {
                if (current->prev != NULL)
                    current->prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = current->prev;
            }

            free(current);
        }

        current = nextNode;
    }

    return head;
}
void printList(Node *head) {
    printf("\n");
    while (head!= NULL) {
        printf("%d <-> ",head->data);
        head = head->next;
    }
    printf("NULL");
}
int main() {
    Node *head = NULL;
    int n,x;
    int deleteValue;
    printf("Nhap so luong phan tu:");
    scanf("%d",&n);

    for (int i=0;i<n;i++) {
        printf("Nhap phan tu thu %d:",i+1);
        scanf("%d",&x);
        head = insertAtTail(head,x);
    }
    printList(head);
    printf("\nNhap gia tri muon xoa:");
    scanf("%d",&deleteValue);

    head = deleteByValue(head,deleteValue);

    printf("Danh sach sau khi xoa %d la:\n",deleteValue);
    printList(head);

    return 0;
}