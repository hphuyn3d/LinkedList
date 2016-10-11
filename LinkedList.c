/**
 * Hung Huynh
 * 4/19/16
 * ASSIGNMENT 5
 * Program which implements a Linked List of integers.
 * It should display a menu like:
 * 1.	Add Item
 * 2.	Remove Item
 * 3.	Print List
 * 4.	Exit
 * Depending on the users selection, the program should respond appropriately. 
 * The program handles all cases such as adding an int to the list or removing one
 */
#include<stdio.h>
#include<stdlib.h>

// Structure for node
struct node	{
	int data;
	struct node *next;
}*head;
/*---------------------------------------------------------------------*/

//Adds int to the end of list
static void insert(int num)	{	
	struct node *temp,*r;
	temp= (struct node *)malloc(sizeof(struct node));
	temp->data=num;
	r=(struct node *)head;
	while(r->next != NULL)
		r=r->next;
		r->next =temp;
		r=temp;
		r->next=NULL;
}
/*---------------------------------------------------------------------*/ 

//Adds first integer
static void add(int num) {
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	if (head== NULL) {
		head=temp;
		head->next=NULL;
	}
	else {
		temp->next=head;
		head=temp;
	}
}
/*---------------------------------------------------------------------*/

//Adds after the first integer
static void addAfterwards(int num, int location) {
	int i;
	//l stands for left and r stands for right
	struct node *temp,*l,*r;
	r=head;
	for(i=1;i<location;i++) {
		l=r;
		r=r->next;
	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	l->next=temp;
	l=temp;
	l->next=r;
	return;
}
/*---------------------------------------------------------------------*/

void additem(int num) {
	int c=0;
	struct node *temp;
	temp=head;
	if(temp==NULL) {
		add(num);
	}
	else {
		//If list is not null, increase count
		while(temp!=NULL) {			
			if(temp->data<num)
				//Moves from the head
				c++;			
			temp=temp->next; 
		}
		//First int is added here
		if(c==0) {		
			add(num);
		}
		//After count, adds the int
		else if (c<size()) { 		
			addAfterwards(num,++c);
		}
		else {
			insert(num);
		}
	}
}

/*---------------------------------------------------------------------*/ 
int removeitem(int num){
	struct node *temp, *prev;
	temp=head;
	while(temp!=NULL) {
		if(temp->data==num) {
			//Removes initial int
			if(temp==head) {
				head=temp->next;
				free(temp);
				return 1;
			}
			else				
			{
				prev->next=temp->next;		
				free(temp);
				return 1;
			}
		}
		else {
			prev=temp;
			temp= temp->next;
		}
	}
	return 0;
}

/*---------------------------------------------------------------------*/ 
void  printlist(struct node *node) {
	node=head;
	if(node==NULL)
	{
		return;
	}
	while(node!=NULL)
	{
		printf("%d ",node->data);
		node=node->next;
	}
}

/*---------------------------------------------------------------------*/ 
//Checks list size
int size() {		
	struct node *node;
	int c=0;
	node=head;
	while(node!=NULL)
	{
		node=node->next;
		c++;
	}
	return c;
}
/*---------------------------------------------------------------------*/ 

int  main() {
	struct node *n;
	head=NULL;
	int i,num;
	while(1)
	{
		printf("*****************************\n");
		printf("1.Add Item\n");
		printf("2.Remove Item\n");
		printf("3.Print list\n");
		printf("4.Exit\n");
		printf("*****************************\n");
		printf("What would you like to do: ");
		if(scanf("%d",&i)<=0){
			printf("Only Integers are allowed\n");
			exit(0);
		} else {
			switch(i)
			{
			case 1:   
				printf("Enter an item: ");
				scanf("%d",&num);
				additem(num);
				break;
			case 2: 
				if(head==NULL)
					printf("List is Empty\n");
				else{
					printf("Which item to remove? : ");
					scanf("%d",&num);
					if(removeitem(num))
						printf("Item removed successfully\n");
					else
						printf("Item not found\n");
				}
				break;    
			case 3: 
				if(head==NULL)
				{
					printf("List is Empty\n");
				}
				else
				{
					printf("Printing list: ");
				}
				printlist(n);
				printf("\n");
				break;
			case 4:     
				return 0;
			default:    
				printf("Not an option\n");
			}
		}
	}
	return 0;
}