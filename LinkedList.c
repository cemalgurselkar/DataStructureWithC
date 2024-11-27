#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linkedlist {
    int info;
    char message[50];
    struct linkedlist *next;
} simple_list;

simple_list *first = NULL;
simple_list *last = NULL;

int insert(simple_list *p) {
    if (first != NULL) {
        last->next = p;
        p->next = NULL;
        last = p;
    } else {
        first = p;
        last = p;
        p->next = NULL;  
    }
    return 0;
}

int displayList() {
    simple_list *p;
    p = first;
    if (p == NULL) {
        printf("List is empty!!\n");
        return -1;
    }
    while (p != NULL) {
        printf("Info: %d, Message: %s\n", p->info, p->message);
        p = p->next;
    }
    return 0;
}

simple_list *search(int key) {
    simple_list *p;
    p = first;
    while (p) {
        if (p->info == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

simple_list *deleteNode(int key){
    simple_list *p, *previous;
    p = first;
    previous = NULL;
    while (p) {
        if (key == p->info) {
            break;
        }
        previous = p;
        p = p->next;
    }

    if (p != NULL) {
        if (previous == NULL) {
            if (first == last) {
                first = NULL;
                last = NULL;
            } else {
                first = first->next;
            }
        } else {
            previous->next = p->next;
            if (previous->next == NULL) {
                last = previous;
            }
        }
        free(p);
        return p;
    } else {
        return NULL;
    }
}

int main(){
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
                newNode = (simple_list *)malloc(sizeof(simple_list));
                if (!newNode) {
                    printf("Memory allocation failed!\n");
                    break;
                }
                printf("Enter info (integer): ");
                scanf("%d", &newNode->info);
                printf("Enter message: ");
                getchar();
                fgets(newNode->message, sizeof(newNode->message), stdin);
                newNode->message[strcspn(newNode->message, "\n")] = '\0';
                insert(newNode);
                printf("Node inserted successfully.\n");
                break;

            case 2:
                displayList();
                break;

            case 3:
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
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                if (deleteNode(key)) {
                    printf("Node with key %d deleted successfully.\n", key);
                } else {
                    printf("Node with key %d not found!\n", key);
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}