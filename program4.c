#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *root = NULL;

void ins(int item){
    if (root==NULL){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->left = NULL;
	newnode->right = NULL;
	return;
    }
    struct node *current = root;
    struct node *parent = NULL;

    while (1) {
        parent = current;
        if (item<current->data) {
            current=current->left;
              if (current==NULL) {
                parent->left=(struct node*)malloc(sizeof(struct node));
                parent->left->data=item;
                parent->left->left=parent->left->right = NULL;
                printf("Inserted %d to the left of %d\n", item,parent->data);
                return;
            }
        } else {
            current=current->right;
            if (current==NULL) {
                parent->right = (struct node*)malloc(sizeof(struct node));
                parent->right->data = item;
                parent->right->left = parent->right->right = NULL;
                printf("Inserted %d to the right of %d\n", item, parent->data);
                return;
            }
        }
    }
}


void cnode(int key) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root==NULL) {
        root=newnode;
        printf("Created root node: %d\n", root->data);
	return;
    }
	if(root!=NULL){
		ins(key);
	}
}


struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* del(struct node* root, int item) {
    if (root == NULL) return root;

    if (item < root->data)
        root->left = del(root->left, item);
    else if (item > root->data)
        root->right = del(root->right, item);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}



void search(int item) {
    struct node *current = root;
    while(current!=NULL){
        if(current->data==item){
           printf("Node %d found.\n", item);
           return;
        }
        current=(item<current->data)?current->left:current->right;
    }
    printf("Node %d not found.\n",item);
}

void inorderTraversal(struct node*root){
 if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d \t",root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct node *root){
    if(root!=NULL){
        printf("%d \t",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct node*root){
    if (root!=NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d \t",root->data);
    }
}
int main(){
    while(1){
        int choice;
        printf("\n Enter your choice from the Following\n\n1.Create a node\n2.Insert a Node\n3.Delete a Node\n4.Search\n5.INORDER TRAVERSAL\n6.PREORDER TRAVERSAL\n7.POSTORDER TRAVERSAL\n8.Exit\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                int key;
                printf("\nEnter the element of Node:");
                scanf("%d", &key);
                cnode(key);
                break;

            case 2:
                int key1;
                printf("\nEnter the key to be inserted:");
                scanf("%d", &key1);
                ins(key1);
                break;

            case 3:
                int key2;
                printf("\nEnter the key to be deleted:");
                scanf("%d",&key2);
                root= del(root,key2);
                break;

            case 4:
                int key3;
                printf("\nEnter the key to be searched:");
                scanf("%d", &key3);
                search(key3);
                break;

            case 5:
                printf("Inorder Traversal:");
                inorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 8:
                printf("\nExiting.....\n");
                exit(0);
            default:
                printf("INVALID CHOICE\n");
        }
    }
    return 0;
}



