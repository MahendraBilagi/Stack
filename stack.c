#include<stdio.h>
#include<stdlib.h>


int getTop(int *element,int max,int top)
{
	if(top==-1)
	{
		printf("\nStack is UNDERFLOW\n");
		return top;
	}
	else
	{
		return element[top];
	}
}

int push(int *element,int max,int top)
{
	int value;
	if(top==max)
	{
		printf("\nStack OVERFLOW");
		return top;
	}
	else
	{
		printf("\nEnter element to push to Stack\n");
		scanf("%d",&value);
		element[++top]=value;
		return top;
	}
}
int pop(int *element,int max,int top)
{
	int value;
	if(top==-1)
	{
		printf("\nStack UNDERFLOW");
		return -1;
	}
	else
	{
		printf("\nPopped element from the stack is = %d\n",element[top--]);
		return top;
	}
}

void display(int top,int *element)
{
	for(int i=0;i<=top;i++)
	{
		printf("%d\t",element[i]);
	}
}

int main()
{
	int MAX_SIZE = 5,top = -1,element[100],choice,temp,newSize;
	do
	{
		printf("\n\nEnter the choice...\n1.Size of stack\n2.Top Element\n3.Set stack size(Default is 5)\n4.Push\n5.Pop\n6.Display\n7.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nSize of the stack is %d",top+1);
				break;
			case 2:
				temp = getTop(element,MAX_SIZE,top);
				if(temp!=-1 || temp!=MAX_SIZE)
				printf("\nTop element is = %d",temp);
				break;
			case 3:
				printf("\nPlease enter new stack size(size should be less than 100)\n");
				scanf("%d",&newSize);
				if(newSize>100)
					printf("\nSize should be less than 100\n");
				else
					MAX_SIZE = newSize;
				break;
			case 4:
				top = push(element,MAX_SIZE,top);
				break;
			case 5:
				top = pop(element,MAX_SIZE,top);
				break;
			case 6:
				printf("\nElements in the stack are...\n");
				display(top,element);
				break;
			case 7:
				exit(0);
			default:
				printf("\nPlease enter correct choice");
				break;
		}
	}while(choice!=7);
return 0;
}
