#include<stdio.h>
#include<stdlib.h>
void display();
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

    display(head);
    int choice=1;
    while(choice>0){
    	printf("\npress 1 to add at the beginning \n");
    	printf("Press 2 to add at the end\n");
    	printf("Press 3 to add in the link list\n");
    	printf("Enter any kye to exit\n");
    	scanf("%d",&choice);
    
		switch(choice){
    		struct node *newnode, *temp;
    			int count,position;
			case 1:
    			newnode = malloc(sizeof(struct node));
    			printf("Enter the data to add at the beginning");
    			scanf("%d",&(newnode->data));
    			newnode->link=head;
    			head=newnode;
    			break;
    		case 2:
				newnode=malloc(sizeof(struct node));
				printf("Enter the data to add at the End");
    			scanf("%d",&(newnode->data));
    			newnode->link=NULL;
    			ptr=head;
    			while(ptr->link!=NULL){
    				ptr=ptr->link;
				}
				ptr->link= newnode;
				break;
			case 3:
				newnode=malloc(sizeof(struct node));
				printf("Enter the data to add in the link");
    			scanf("%d",&(newnode->data));
				ptr=head;
				while(ptr!=NULL){
					ptr=ptr->link;
					count++;
				}
				printf("choice where do u want insert new node bettwen 2 to %d\n",count);
				invalid:
				scanf("%d",&position);
				if (position<2 || position>count){
					printf("Invalid input enter again");
					goto invalid;
				}
				ptr=head;
				for(i=2; i<position; i++){
					ptr=ptr->link;
				}
				temp=ptr->link;
				ptr->link=newnode;
				newnode->link=temp;
				break;
			default:
				choice==0;
				break;
		}
		printf("\n");
    	display(head);
	}
    
    
    return 0;
}
void display(struct node *ptr){

printf("listed items are: ");
while(ptr!=NULL){
	printf("%d ",(ptr->data));
	ptr=ptr->link;
}
printf("\n");
}
