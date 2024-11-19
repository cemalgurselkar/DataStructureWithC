#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the List
typedef struct linkedlist {
    int info;                 // Integer value
    char message[50];         // String data
    struct linkedlist *next;  // Pointer to the next element
} simple_list;

// Initially, the list is empty
simple_list *first = NULL;
simple_list *last = NULL;

// Function to insert a new node
int insert(simple_list *p) {
    if (first != NULL) {
        last->next = p;  // Link the current last node to the new node
        p->next = NULL;  // Set the new node's next pointer to NULL
        last = p;        // Update the last pointer
    } else {
        first = p;       // If the list is empty, the new node becomes the first
        last = p;        // and also the last
        p->next = NULL;  // Set the next pointer to NULL
    }
    return 0;
}

// Function to display the list
int displayList() {
    simple_list *p;
    p = first;
    if (p == NULL) {
        printf("List is empty!!\n");
        return -1;
    }
    while (p != NULL) {
        printf("Info: %d, Message: %s\n", p->info, p->message);
        p = p->next;  // Move to the next node
    }
    return 0;
}

// Function to search an element by its key
simple_list *search(int key) {
    simple_list *p;
    p = first;
    while (p) {
        if (p->info == key) {
            return p;  // Return the found node
        }
        p = p->next;
    }
    return NULL;  // Return NULL if not found
}

// Function to delete an element by its key
simple_list *deleteNode(int key) {
    simple_list *p, *previous;
    p = first;
    previous = NULL;

    // Search for the element to be deleted
    while (p) {
        if (key == p->info) {
            break;
        }
        previous = p;
        p = p->next;
    }

    if (p != NULL) {
        if (previous == NULL) {
            // If the first element will be deleted
            if (first == last) {
                // If list has one element
                first = NULL;
                last = NULL;
            } else {
                first = first->next;
            }
        } else {
            // Delete from middle or last
            previous->next = p->next;
            if (previous->next == NULL) {
                // Last element is deleted
                last = previous;
            }
        }
        free(p);  // Free the memory of the deleted node
        return p;
    } else {
        return NULL;
    }
}

int main() {
    int choice, key;
    char message[50];
    simple_list *newNode, *foundNode;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Display List\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert
                newNode = (simple_list *)malloc(sizeof(simple_list));
                if (!newNode) {
                    printf("Memory allocation failed!\n");
                    break;
                }
                printf("Enter info (integer): ");
                scanf("%d", &newNode->info);
                printf("Enter message: ");
                getchar(); // To consume newline character
                fgets(newNode->message, sizeof(newNode->message), stdin);
                newNode->message[strcspn(newNode->message, "\n")] = '\0'; // Remove newline
                insert(newNode);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                // Display
                displayList();
                break;

            case 3:
                // Search
                printf("Enter the key to search: ");
                scanf("%d", &key);
                foundNode = search(key);
                if (foundNode) {
                    printf("Found Node - Info: %d, Message: %s\n", foundNode->info, foundNode->message);
                } else {
                    printf("Node with key %d not found!\n", key);
                }
                break;

            case 4:
                // Delete
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                if (deleteNode(key)) {
                    printf("Node with key %d deleted successfully.\n", key);
                } else {
                    printf("Node with key %d not found!\n", key);
                }
                break;

            case 5:
                // Exit
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
