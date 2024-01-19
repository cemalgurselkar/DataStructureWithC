#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}tree;

tree* newnodeCreate(int value)
{
	tree* newwnode = (tree*)malloc(sizeof(tree));
	newnode->data = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}

tree* searchNode(tree* root,int target)
{
	if (root == NULL || root->data == target);
	{
		return root;
	}
	if (root->data < target)
	{
		return searchNode(root->left,target);
	}
	return searchNode(root->right,target);
}

tree* insertNode(tree* node,int value)
{
	if (node == NULL)
	{
		return newnodeCreate(value);
	}
	if (value < node->data)
	{
		node->left = insertNode(node->left,value);
	}
	else if(value > node->data)
	{
		node->right = insertNode(node->right,value);
	}
	return node;
}

void postOrder(tree* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d ",root->data);
	}
}

void inOrder(tree* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf(" %d ",root->data);
		inOrder(root->right);
	}
}

void preOrder(tree* root)
{
	if(root != NULL)
	{
		printf(" %d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

tree* deleteNode(tree* root,int x)
{
	if (root == NULL)
	{
		return root;
	}
	if (x > root->data)
	{
		root->right = deleteNode(root->right,x);
	}
	else if(x < root->data)
	{
		root->left = deleteNode(root->left,x);
	}
	else
	{
		if (root->left == NULL)
		{
			tree* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			tree* temp = root->left;
			free(root);
			return temp;
		}
		//Node with two children: Get the inorder successor (smallest in the right subtree)
		tree* temp= root->right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		//Copy the inorder successor's content to this node
		root->data = temp->data;
		//Delete the inorder successor
		root->right = deleteNode(root->right,temp->data);
	}
	return root;
}

int main()
{

struct BstNode* root = NULL;
int x, choice;
while (1){
printf("\n1. Insert a node \n2. Delete a node \n3. List nodes \n4. Search for a node \n5. Exit \nEnter your choice: ");
scanf("%d",&choice);
switch (choice) {
case 1:
printf("Enter node to be inserted: ");
scanf("%d",&x);
root = insertNode(root, x);
break;
case 2:
printf("Enter node to be deleted: ");
scanf("%d",&x);
root = deleteNode(root,x);
if (root != NULL){
printf("Node Deleted and After Delete: \n");
inOrder(root);
}
else{
printf("Node to be deleted is not found\n");
}
break;
case 3:
if (root != NULL){

printf("Post-order traversal: \n");
postOrder(root);

printf("\nPre-order traversal\n");
preOrder(root);

printf("\nIn-order traversal\n");
inOrder(root);
}
else {
printf("Tree is empty\n");
}
break;
case 4:
printf("Enter node to be searched for: ");
scanf("%d",&x);
root = searchNode(root,x);
if (root == NULL){
printf("Item is not found\n");
}
else
printf("Item is found: %d \n", root->data);
case 5:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}
