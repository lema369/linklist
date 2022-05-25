#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	int ch,entry,count=0,position=0,num;
	while(1)
	{
		printf("\n1:Instert\n2:Display Forward\n3:Display Reverse\n4:Delete an element\n5:Exit");
		printf("\n Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("\n Enter the data:");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					
					tail->next->next=NULL;
					tail=tail->next;
				}
			break;
			}
			case 2:
			{
				pos=head;
				printf("\n elements are");
				while(pos!=NULL)
				{
					printf("\t %d",pos->data);
					pos=pos->next;
				}
			break;
			}
			case 3:
			{
				pos=tail;
				printf("the elements are");
				while(pos!=NULL)
				{
					printf("\t %d",pos->data);
					pos=pos->prev;
				}
			}
			break;
			case 4:
			{
				struct node *del=head;
				if(entry==0)
				{
					head=head->next;
					del->next=NULL;
					head->prev=NULL;
					free(del);
				}
				else{
				struct node *temp=head;
				printf("enter position");
				scanf("%d",&entry);
				for(int i=0;i<entry-1;i++)
				{
					temp=temp->next;
				}
				struct node *del=temp->next;
				temp->next=temp->next->next;
				temp->next->prev=temp;
				del->prev=NULL;
				del->next=NULL;
				free(del);
				}
			break;
			}	
			case 5:
			{
				printf("Good bye");
				exit(0);
			}
		}
	}
}
