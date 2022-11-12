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
    while(choice>0){                  //taking choice where from delete  the node
    	printf("\npress 1 to delete from the beginning \n");
    	printf("Press 2 to delete from the end\n");
    	printf("Press 3 to delete node in the link list\n");
    	printf("Enter any kye to exit\n");
    	scanf("%d",&choice);
    
		switch(choice){
    		struct node *newnode, *temp;
    			int count,position;
			case 1:
    			ptr=head;
    			head=head->link;
    			ptr->link=NULL;
    			break;
    		case 2:
				ptr=head;
				while(ptr->link->link!=NULL){
					ptr=ptr->link;
				}
				ptr->link=NULL;
				break;
				
			case 3:
				ptr=head;
				while(ptr!=NULL){
					ptr=ptr->link;
					count++;
				}
				printf("choice where from You want to delete node bettwen 2 to %d\n",count);
				invalid:
				scanf("%d",&position);
				if (position<2 || position>count){         //invalid input warning
					printf("Invalid input enter again");
					goto invalid;
				}
				ptr=head;
				for(i=2; i<position; i++){
					ptr=ptr->link;
				}
				ptr->link=ptr->link->link;
				break;
			default:
				choice==0;
				break;
		}
			printf("\n");
    	display(head);      //displaying the new link list
	}
    
    
    return 0;
}
void display(struct node *ptr){  //Traversing to print link list

printf("listed items are: ");
while(ptr!=NULL){
	printf("%d ",(ptr->data));
	ptr=ptr->link;
}
printf("\n");
}
