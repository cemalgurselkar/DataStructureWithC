#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct double_list{
    int info;
    char message[100];
    struct double_list *previous;
    struct double_list *next;
}d_list;

d_list *first = NULL;
d_list *last = NULL;

/* Insert at the end
last->next = p;
p->previous = last;
p->next = NULL;
last = p;
*/
int insert(d_list *p){
    if (first != NULL){
        last->next = p;
        p->previous = last;
        p->next = NULL;
        last = p;
    }
    else{
        first = p;
        last = p;
        first->previous = NULL;
        last->next = NULL;
    }
    return 0;
}

int display(){
    d_list *p;
    p = first;
    if (p == NULL){
        printf("List is empty\n");
        return -1;
    }
    while (p){
        printf("%d %s\n",p->info,p->message);
        p = p->next;
    }
    return 0;
}

d_list *search(int key){
    d_list *p;
    p = first;
    while (p){
        if (key == p->info){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

d_list *delete(int key){
    d_list *p;
    p = search(key);
    if (p==NULL){
        printf("The element to be deleted is not in the list\n");
        return NULL;
    }
    if (p == first){ //Delete the first element
        if (first == last){ //list has 1 element
            first = NULL;
            last = NULL;
        }
        else{ //list has more than one element
            first = p->next;
            first->previous = NULL;
        }
    }
    else{
        if (p == last){ //Delete from last
            last = p->previous;
            last->next = NULL;
        }
        else{ //Delete from middle
            p->previous->next = p->next;
            p->next->previous = p->previous;
        }
    }
    free(p);
    return p;
}

int main() {
    d_list *node1 = (d_list *)malloc(sizeof(d_list));
    d_list *node2 = (d_list *)malloc(sizeof(d_list));
    d_list *node3 = (d_list *)malloc(sizeof(d_list));

    if (!node1 || !node2 || !node3) {
        printf("Memory allocation failed\n");
        return -1;
    }

    // İlk düğümü ekleme
    node1->info = 1;
    strcpy(node1->message, "First Node");
    insert(node1);

    // İkinci düğümü ekleme
    node2->info = 2;
    strcpy(node2->message, "Second Node");
    insert(node2);

    // Üçüncü düğümü ekleme
    node3->info = 3;
    strcpy(node3->message, "Third Node");
    insert(node3);

    // Listeyi yazdırma
    printf("List after insertion:\n");
    display();

    // Eleman arama
    int key = 2;
    d_list *found = search(key);
    if (found) {
        printf("Node found: %d %s\n", found->info, found->message);
    } else {
        printf("Node with key %d not found.\n", key);
    }

    // Eleman silme
    printf("Deleting node with key 2...\n");
    delete(key);

    // Listeyi tekrar yazdırma
    printf("List after deletion:\n");
    display();

    return 0;
}
