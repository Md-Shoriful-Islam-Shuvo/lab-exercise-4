#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
int main()
{
	int size;
	printf("Enter the size of the list: ");
	scanf("%d",&size);
	
     struct node *head = malloc(sizeof(struct node)); //creating the head of the link list
     printf("Enter tha datas of the list: \n");
	 scanf("%d",&(head->data));
     head->link =NULL;
     
     int i;
     struct node *ptr;
     ptr=head;
     for(i=1;i<size;i++){                     //creating rest the link list	 
     struct node *current = malloc(sizeof(struct node));
     scanf("%d",&(current->data));
     current->link= NULL;
     ptr->link =current;
     ptr=ptr->link;
    }
    ptr=head;
	printf("listed items are: ");
	while(ptr!=NULL){                //Traverse each node of the list.
	printf("%d ",(ptr->data));
	ptr=ptr->link;
}
    return 0;
}

