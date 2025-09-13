#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a node with data as a parameter
struct Node *createNewNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert the node at the end of the list
void inserAtspecificPosition(int data, int pos)
{
    struct Node *newNode = createNewNode(data);

    if (pos < 1){
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    if (pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traversing
    struct Node *temp = head;
    int currentPosition = 1;
    while (temp->next != NULL && currentPosition < pos-1){
        temp = temp->next;
        currentPosition++;
    }
    
     if (temp == NULL) {
        printf("Position out of bounds. The list is not long enough \n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display Function
void display()
{
    struct Node *temp = head;
    printf("[");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL]\n");
}

int main()
{
    // Orignal List [NULL]
    printf("Orginal List: ");
    display();

    // Updated List
    printf("New List: ");
    inserAtspecificPosition(10, 1);
    inserAtspecificPosition(20, 3);
    inserAtspecificPosition(30, 4);
    inserAtspecificPosition(40, 2);

    display();
    return 0;
}