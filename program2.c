#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node*next;
	};
struct node *head=NULL;

void beg(int item)
{
struct node*newnode=malloc(sizeof(struct node));
newnode->data=item;
newnode->next=head;
head=newnode;

}
	void end(int item)
	{
        struct node*newnode=malloc(sizeof(struct node));
	newnode->data=item;
	newnode->next=NULL;
       	if(head==NULL)
	{
		head=newnode;
	}
	else{
        struct node*temp=head;
	while(temp->next!=NULL)
	{
        struct node*temp=head;
		temp=temp->next;
	}
	temp->next=newnode;
}
	}
void Inany(int item, int pos)
{
 
 struct node*temp=head;
 struct node*newnode=malloc(sizeof(struct node));
	if(pos<1)
	{
		printf("Invalid position");
	return;
	}

else if(pos==1)
	{
		newnode->data=item;
		newnode->next=head;
		head=newnode;

	}

else {
	for(int i=0;i<pos-2;i++)
	{
		temp=temp->next;

	}

	newnode->next=temp->next;
	newnode->data=item;
	temp->next=newnode;
}


}

	void d_beg()
	{
	struct node*temp;
	temp=head;
	int x=temp->data;
	head=temp->next;
	free(temp);
	printf("%d is deleted",x);
	}

void d_end()
{
	struct node*temp=head;
	struct node*x;
	if(temp==NULL){
	printf("List is empty");
	return;
	}

	else if(temp->next==NULL){
		free(temp);
		head=NULL;
	}
else{
	while(temp->next!=NULL)
	{
		x=temp;
		temp=temp->next;
	}
	x->next=NULL;
	free(temp);
	printf("%d is deleted",x->data);

}

	}


	void d_any(int pos)
	{
		struct node*temp=head;
		struct node*prev=NULL;
	if(pos<1){
	printf("Invalid");
	return;
	}
	if(pos==1){
	d_beg();
	return;
	}
	for(int i=2;i<=pos && temp!=NULL; i++){
	prev=temp;
	temp=temp->next;
	}

	if(temp==NULL){
	printf("Invalid choice");
	return;
	}
	prev->next=temp->next;
	free(temp);
}


void l_display()
{
struct node*temp=head;
if(head==NULL){
printf("\n List is empty");
return;
}
while(temp!=NULL)
{
	printf("%d \t",temp->data);
	temp=temp->next;
		}

return;
}

void e_search(int key)
{
int count=0;
struct node*temp=head;
	while(temp!=NULL)
	{
		if(key==temp->data)
		{
			count=count+1;
			break;
		}
	else
	temp=temp->next;
	}
if(count==1)
{
printf("The element found");
}
else
printf("Element not found");


}
void main()

{
int choice,item,key,pos;
	printf("Enter your choice from the following\n");
	while(1){
	printf("\n 1.Insert at beginning \n 2.Insert at end \n 3.Insert at any position \n 4.Delete from beginning\n 5.Delete from End\n 6.Delete from any position\n 7.List Traversal \n 8.List display\n 9.Exit\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the Item to be inserted at begining\n");
				scanf("%d",&item);
				beg(item);
				break;
                        case 2:

                                printf("\nEnter the Item to be inserted at the end of the list\n ");
                                scanf("%d",&item);
                                end(item);
				break;

			case 3:
				printf("\nEnter the Item to be inserted\n");
                                scanf("%d",&item);
                                printf("\nEnter the position which item needs to be inserted\n");
				scanf("%d",&pos);
				Inany(item,pos);
				break;

                        case 4:
                                d_beg();
                                break;

			case 5:
				d_end();
				break;

			case 6:
				printf("Enter the position you need to delete");
				scanf("%d",&pos);
				d_any(pos);
				break;

			case 7:
				printf("Enter the item to searched");
				scanf("%d",&key);
				e_search(key);
				break;

                        case 8:
                                l_display();
                                break;

			case 9:
				printf("Exited......");
				return;
			default:
				printf("Invalid choice");
	}
				}
}
