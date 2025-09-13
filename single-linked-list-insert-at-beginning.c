#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(int data) {
    struct Node* newNode = createNewNode(data);
    
    struct Node* temp = head;
    while(temp != NULL) {
        temp = temp->next;
    }
    
    newNode->next = head;
    head = newNode;
}

void display() {
    struct Node* temp = head;
    printf("[");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL]\n");
}

int main() {
    printf("Orginal List: ");
    display();
    
    printf("New List: ");
    insertAtBegin(10);
    insertAtBegin(20);
    insertAtBegin(30);
    insertAtBegin(40);
    
    display();
    return 0;
}