#include<stdio.h>
int main()
{
	int i,num,fact=1,prime=1;
	printf("Enter a number:");
	scanf("%d",&num);
	while(num!=0)
	{
	
	for(i=1; i<=num; i++)
	{
		fact=fact*i;
	}
	printf("\n\nthe factorial value of that number is %d \n\n",fact);

	if(num==1)
	{
		printf("1 is not a prime number or a non-primr number\n\n");
	}
	else
	{
		for(i=2; i<num; i++)
		{
			if(num%i==0)
			{
				prime=0;
				break;
			}
		}
	}
	if (prime)
	{
		printf("%d is a prime number\n\n",num);
	}
	else
	{
		printf("%d is not a prime number\n\n",num);
	}

	if(num%2==0)
	{
		printf("%d is a even number\n",num);
	}
	else
	{
		printf("%d is a odd number",num);
	}
	printf("\n\n\n\nEnter a number:");
	scanf("%d",&num);
   }   
printf("U have entered 0");
	return 0;
} 

