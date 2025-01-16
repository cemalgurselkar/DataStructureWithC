// Binary Trees

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bTree{
    int info;
    char message[100];
    struct bTree *left;
    struct bTree *right;
}tree;

tree *root = NULL;

void insert(tree *treeRoot, tree *newNode){
    if (treeRoot == NULL){
        root = newNode;
    }
    else{
        if (newNode->info < treeRoot->info){
            if (treeRoot->left == NULL){
                treeRoot->left = newNode;
            }
            insert(treeRoot->left, newNode);
        }
        else{
            if(treeRoot->right == NULL){
                treeRoot->right = newNode;
            }
            insert(treeRoot->right, newNode);
        }
    }
}

void traverse(tree *treeRoot){
    while (treeRoot != NULL){
        printf("%d %s\n", treeRoot->info, treeRoot->message);
        traverse(treeRoot->left);
        traverse(treeRoot->right);
    }
}

tree *search(tree *treeRoot, int item){
    while ((treeRoot != NULL) && (treeRoot->info) != item){
        if (item < treeRoot->info){
            treeRoot = treeRoot->left;
        }
        treeRoot = treeRoot->right;
    }
    return treeRoot;
}

tree *delete(tree *treeRoot, int item){
    tree *qa, *q, *qc, *sa, *s;
    if (treeRoot == NULL){
        return NULL;
    }
    q = treeRoot;
    qa = NULL;
    //find the item to be deleted
    while ((q != NULL) && (q->info != item)){
        qa = q;
        if (item < q->info){
            q = q->left;
        }
        q = q->right;
    }
    if (q == NULL){
        printf("Item to be deleted is not found!!\n");
        return NULL;
    }
    //if q is found and it has 2 children
    if ((q->left != NULL) && (q->right != NULL)){
        s = q->left;
        sa = q;
        //find item having the max value in the left
        //subtree. So, take the rightmost node
        // in the left subtree.
        while (s->right != NULL){
            sa = s;
            s = s->right;
        }
        q->info = s->info;
        strcpy(q->message, s->message);
        q = s;
        qa = sa;
    }
    //noew q has at most 1 child, and find it
    if ((q->left != NULL)){
        qc = q->left;
    }
    else{
        qc = q->right;
    }
    //delete q
    if (q == treeRoot){
        root = qc;
    }
    else{
        if (q == qa->left){
            qa->left = qc;
        }
        qa->right = qc;
    }
    free(q);
    return q;
}

tree *readNode(){
    tree *newNode;
    newNode = (tree *)malloc(sizeof(tree));
    if (newNode == NULL){
        return NULL;
    }
    printf("Enter info: ");
    scanf("%d",&(newNode->info));

    printf("Enter message:");
    scanf("%s",newNode->message);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int countNode(tree *treeRoot, int sum){
    if (treeRoot == NULL){
        return sum;
    }
    sum++;
    sum = countNode(treeRoot->left, sum);
    sum = countNode(treeRoot->right, sum);
    return sum;
}

int main() {
    tree *n, *a;
    int i, count, choice;

    while (1) {
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. List nodes\n");
        printf("4. Search for a node\n");
        printf("5. Count number of nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            n = readNode();
            insert(root, n);
        } else if (choice == 2) {
            printf("Enter node to be deleted: ");
            scanf("%d", &i);
            a = delete(root, i);
            if (a != NULL)
                printf("Deleted\n");
            else
                printf("Item to be deleted is not found\n");
        } else if (choice == 3) {
            if (root != NULL)
                traverse(root);
            else
                printf("Tree is empty\n");
        } else if (choice == 4) {
            printf("Enter node to be searched for: ");
            scanf("%d", &i);
            a = search(root, i);
            if (a == NULL)
                printf("Item is not found\n");
            else
                printf("%d %s\n", a->info, a->message);
        } else if (choice == 5) {
            count = countNode(root, 0);
            printf("Number of nodes in the tree = %d\n", count);
        } else {
            break;
        }
    }
    return 0;
}
