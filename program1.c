#include<stdio.h>
#include<stdlib.h>
#define max 8

struct node{
	int data;
	struct node*next;
};
struct node *top=NULL;
void push(int item)
{
	{
		struct node*newnode=malloc(sizeof(struct node*));
		newnode->data=item;
		newnode->next=top;
		top=newnode;
	}

}

void pop()
{
	int val,temp;
	if(top==NULL){
		printf("Stack underflow\n");
		}
	else
	{
		struct node*temp=top;
		val=temp->data;
		top=temp->next;
		free(temp);
		printf("%d is popped",val);
	}

}
void display()
{
	struct node*temp;
        if(top==NULL){
                printf("Stack is empty");
                }
	else
	{
		temp=top;
		while(temp!=NULL){
			printf("%d \t",temp->data);
			temp=temp->next;
	}

}
}
void search(int key)
{
	struct node*temp=top;
	int count=0;
	while(temp!=NULL){
		if(temp->data==key)
		{
			printf("The element %d is  found\n",temp->data);
			count=count+1;
			break;
		}
			else
			{
				temp=temp->next;
			}

		}
	if(count==0){
		printf("\nElement not found\n");
}

}

void  main()
{
int choice;
	while(1){
	printf("\nEnter your choice \n 1.Push \n 2.Pop\n 3.Display\n 4.Search \n 5.Exit\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:
				int item;
				printf("Enter the item to be inserted \n");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;

			case 3:
				display();
				break;
			case 4:
				int key;
				printf("Enter the Item to search\n");
				scanf("%d",&key);
				search(key);
				break;

			case 5:
				printf("Exited Successfully");
				exit (0);
		default:
			printf("Invalid entry");
			}
				}

}

