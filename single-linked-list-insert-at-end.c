#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

//Function to create a node with data as a parameter
struct Node* createNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert the node at the end of the list
void inertAtEnd(int data) {
    struct Node* newNode = createNewNode(data);
    
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    //Traversing
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

//Display Function
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
    //Orignal List [NULL]
    printf("Orginal List: ");
    display();
    
    //Updated List
    printf("New List: ");
    inertAtEnd(10);
    inertAtEnd(20);
    inertAtEnd(30);
    inertAtEnd(40);
    
    display();
    return 0;
}