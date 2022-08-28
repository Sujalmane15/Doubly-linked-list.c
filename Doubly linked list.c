#include<stdio.h>
#include<stdlib.h> 

struct node
{
	int data;
	struct node*next;
	struct node*prev;
};
struct node *head,*tail,*temp;
int lenght(void);
void insert();
void insert_big();
void insert_end();
int insert_pos();
void delete_big();
void delete_end();
void delete_pos();
void reverse();



int main()
{
	int ch,flag=1;
       
      
	while(flag==1)
	{
		printf("\n LINKED LIST MENU:");
		printf("\n PRESS 1 FOR INSERT:");
		printf("\n PRESS 2 FOR INSERT BEGINNING:");
		printf("\n PRESS 3 FOR INSERT END:");
		printf("\n PRESS 4 FOR INSERT POSITION:");
		printf("\n PRESS 5 FOR DELETE FIRST ELEMENT:");
		printf("\n PRESS 6 FOR DELETE TO END ELEMENT:");
		printf("\n PRESS 7 FOR DELETE TO POSITION:");
		printf("\n PRESS 8 FOR REVERSE:");
		
		
		
		
		 printf("\n ENTER THE YOUR OPTION:");
               scanf("%d",&ch);
      
		 switch(ch)
            {
       	 case 1:insert();
       	       break;
       	 case 2:insert_big();
       	       break;
       	 case 3:insert_end();
		       break;
		 case 4:insert_pos();
		       break;
		 case 5:delete_big();
		       break;
		 case 6:delete_end();
		       break;	      
		 case 7:delete_pos();
		       break;
		 case 8:reverse();
		       break;
               
       	       
       	 default:printf("ENTER THE CORRECT OPTION:");
                     break;
        	}
	printf("\n PRESS 1 FOR LINKED LIST MENU:");
       scanf("%d",&flag);
 
	}
	return 0;
	
}
void insert()
{
	struct node *newnode;
	int ch=1,cout;
	head=0;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n ENTER THE DATA:");
		scanf("%d",&newnode->data);
		newnode->prev=NULL;
		newnode->next=NULL;
		
		if(head==0)
		{
			head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
		printf("\n DO YOU WANT TO CONTINUE(PRESS 1):");
		scanf("%d",&ch);
		
	}
	printf("\n DISPLAY THE ELEMENT:");
	 temp=head;
        while(temp!=NULL)
      {
   	   printf("\n%d",temp->data);
   	   temp=temp->next;
   	   cout++;
      }
	

}
void insert_big()
{
    int cout,ch=1;
    struct node *newnode;
    while(ch)
    {
    
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n ENTER THE DATA:");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    
    if(head==NULL)
    { 
    	head=tail=newnode;
    }
    else
    {
    
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    }
    
        printf("\n DO YOU WANT TO CONTINUE(PRESS 1):");
        scanf("%d",&ch);
}
       printf("\n DISPLAY THE ELEMENT:");
       
	temp=head;
        while(temp!=0)
      {
   	   printf("\n%d",temp->data);
   	   temp=temp->next;
   	   cout++;
      }
    
}
void insert_end()
{
	int cout;
	struct node *newnode;
	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER THE DATA:");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=NULL;
	
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
	
	printf("\n DISPLAY THE ELEMENT:");
	temp=head;
        while(temp!=NULL)
      {
   	   printf("\n%d",temp->data);
   	   temp=temp->next;
   	   cout++;
      }
		
}
int insert_pos()
{
	int i=1,l,cout,pos;

	printf("\n ENTER THE POSITION:");
	scanf("%d",&pos);
        l=lenght();
        printf("\n lenght list: %d",l);
        
	if(pos>l || pos<0)
	{
		printf("\n INVALID POSITION !");
	}
	else if(pos==1)
	{
		insert_big();
	}

      else
	{
		struct node *newnode;
		temp=head;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n ENTER THE DATA:");
		scanf("\n%d",&newnode->data);
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
	}
		
	printf("\n DISPLAY THE ELEMENT:");
	temp=head;
        while(temp!=NULL)
      {
   	   printf("\n%d",temp->data);
   	   temp=temp->next;
   	   cout++;
      }
     return 0;
}
void delete_big()
{
	int cout;
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		printf("\n DELETE ELEMENT:%d",temp->data);
		free(temp);
		
       }
       printf("\n DISPLAY THE ELEMENT:");
	temp=head;
        while(temp!=NULL)
      {
   	   printf("\n%d",temp->data);
   	   temp=temp->next;
   	   cout++;
      }
}	
void delete_end()
{
	int cout;
	if(tail==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
	  temp=tail;
	  tail=tail->prev;
	  tail->next=NULL;
	  printf("\n DELETE ELEMENT:%d",temp->data);
	  free(temp);
	  
	}
	printf("\n DISPLAY THE ELEMENT:");
	temp=head;
        while(temp!=NULL)
      {
   	   printf("\n%d",temp->data);
   	   temp=temp->next;
   	   cout++;
      }
}
void delete_pos()
{
	int pos,cout,i=1,l;
	
	temp=head;
	
	printf("\n ENTER THE POSITION:");
	scanf("%d",&pos);
	 
        if(pos==1)
	{
		delete_big();
	}
	else 
	{
		while(i<pos)
	{
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	printf("DELETE ELEMENT:%d",temp->data);
	free(temp);
	
	printf("\n DISPLAY THE ELEMENT:");
	temp=head;
        while(temp!=NULL)
      {
   	   printf("\n%d",temp->data);
   	   temp=temp->next;
   	   cout++;
      }
     }

}
void reverse()
{     
       int cout; 
	 temp=tail;
       while(temp!=NULL)
   {
   	printf("\n%d",temp->data);
   	temp=temp->prev;
   	cout++;
   }
}
int lenght()    
{
 	int count;
 	temp=head;
 	while(temp!=NULL)
 	{
 	       count++;
 		temp=temp->next;
	}

	return(count);
 }
