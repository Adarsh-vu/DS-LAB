#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head=NULL;

struct node* createnode(int item){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void display()
{
if(head==NULL){
printf("The list is empty\n");
return;
}
struct node*temp=head;

	while(temp!=NULL){
	printf("%d \t",temp->data);
	temp=temp->next;
	}
}

void beg(int item)
{
struct node*newnode=createnode(item);
newnode->next=head;
	if(head!=NULL){
 		head->prev=newnode;
	}
head=newnode;
display();
return;
}

void iend(int item)
{
struct node*newnode=createnode(item);
	if(head==NULL){
	head=newnode;
	display();
	return;
	}
 struct node*temp=head;
 	while(temp->next!=NULL){
 	temp=temp->next;
	}
temp->next=newnode;
newnode->prev=temp;
display();
return;
}

void iany(int item,int pos)
{
struct node*newnode=createnode(item);
if(pos<=0){
	printf("\nInvalid Position entered");
	return;
	}
	if(pos==1){
	beg(item); 
	return;
	}
struct node*temp=head;
int i=1;
	while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
    printf("Position out of range\n");
    free(newnode);
    return;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
if(temp->next!=NULL){
temp->next->prev=newnode;
}
    temp->next=newnode;
    display();
    return;
}

void dbeg()
{
    if (head==NULL){
	printf("List is empty\n");
	return;
    }
    struct node*temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev = NULL;
    }
	printf("The element %d is deleted \n",temp->data);
	free(temp);
	return;
}

void dend()
{
    if(head==NULL){
        printf("List is empty\n");
        return;
	}
    struct node* temp=head;
    while(temp->next!=NULL){
	temp=temp->next;
	}
	if(temp->prev!=NULL){
	temp->prev->next=NULL;
	}
	else{
		head=NULL;
	}
	printf("The element %d is deleted \n",temp->data);
	free(temp);
	display();
}

void dany(int pos)
{
	if(head==NULL) {
	printf("List is empty\n");
	return;
    }
if(pos<=0){
printf("Invalid position provided");
return;
  }
    if(pos==1){
        dbeg();
        return;
    }
    struct node*temp=head;
    for (int i=0;i<pos-1 && temp!=NULL;i++) 
{
        temp = temp->next;
	}
    if (temp == NULL) {
        printf("Provided Position out of Range\n");
        return;
    }
    if (temp->prev!=NULL) {
        temp->prev->next=temp->next;
    }
    if (temp->next!=NULL) {
        temp->next->prev =temp->prev;
    }
	printf("The element %d is deleted \n",temp->data);
	free(temp);
	return;

}

void search(int key) {
        if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    while(temp!=NULL){
        if(temp->data ==key){
            printf("Element %d found in the list.\n", key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", key);
}


int main()
{
	int item,choice,pos,key;
	while(1){
	printf("\n \n Enter your choice from the following\n 1.Insert at begining\n 2.Insert at end \n 3.Insert at any position\n 4.Delete from Begining\n 5.Delete from End\n 6.Delete from any position\n 7.Display the list \n 8.Search an element\n 9.Exit\n  ");
	scanf("%d",&choice);
switch (choice){
	case 1://insert at begining
		printf("\nEnter your element to insert: ");
                scanf("%d",&item);
                beg(item);
                break;
        case 2://insert at end
                printf("\n Enter the element to be inserted at end:");
                scanf("%d",&item);
                iend(item);
                break;
        case 3://insert at any pos
                printf("\n Enter the element to insert:");
                scanf("%d",&item);
                printf("\n Enter the position to insert:");
                scanf("%d",&pos);
                iany(item,pos);
                break;
        case 4://delete from beg
                dbeg();
                display();
                break;
        case 5://delete from end
                dend();
                break;
        case 6://delete from any
                printf("\n Enter the position to delete: ");
                scanf("%d",&pos);
                dany(pos);
                break;
        case 7://display
                display();
                break;
        case 8://search
                printf("\n Enter the element to search: ");
                scanf("%d",&key);
                search(key);
                break;

        case 9:
                printf("\nExiting.........");
                exit(0);
        default:
                printf("\n Invalid choice");
                exit(0);

	}
    }
        return 0;
}
