#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "list1.h"

struct node
	{
		char x;
		struct node *next;
	
	};

int createlist(void)
{
		struct node *add1;
		add1=(struct node *)malloc(sizeof(struct node));
		add1->next=NULL;
		add1->x=0;
		return (int)add1;
}

int attachlist(int name,char *n)
{
	struct node *p; 	
	p=(struct node *)(name);	
	while(p->next!=NULL)
	{		
		p=p->next;
	}		

		int i = 0 , n_len = strlen ( n );
		while( i < n_len ){
			p->next = (struct node *)malloc(sizeof(struct node));
			p = p->next;
			p->x = n[i];
			p->next = NULL;
			i++;
		}
		return 0;
}

char readlist(int name,int n){
	struct node *p;
	p=(struct node *)(name);	
	int a;
	for(a=0;a<=n;a++)
	{
		if(p->next==NULL)
		{	
			//printw("\nTHERE IS NO SUCH ENTRY at %d\n",n);
			return -1;
		}
		
		p=p->next;
	}
	if(n==-1)
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
	}
	
	
			return p->x;
}

void replace(int name,char *s,char *new_s){
	struct node *p,*newnode,*father,*add_node,*remp;
	p=(struct node *)(name);
	remp=(struct node *)malloc(sizeof(struct node));
	char ch;
	//printf("s is : %s",s);
	int slength=strlen(s),k=0,i=0;
	//printf("\nI am replacing\n");
	while(p!=NULL){
		father=p;
		p=p->next;
		remp=p;
		i=0;
		while(p!=NULL&&i<slength){
			ch=p->x;
			p=p->next;
			if(*(s+i)!=ch){
				break;
			}
			/*else
				printf("%c",ch);*/
			i++;
			
		}
		//printf("\ni = %d slength = %d\n",i,slength);
		if(i==slength){
			//printf("Word match found");
			k=0;
			newnode=(struct node *)malloc(sizeof(struct node));
			//printf("father : %c",father->x);
			father->next=newnode;
			newnode->x=*(new_s+k);
			k++;
			while(k<strlen(new_s)){	
				add_node=(struct node *)malloc(sizeof(struct node));
				newnode->next=add_node;
				add_node->x=*(new_s+k);
				newnode=add_node;
				k++;	
			}
			newnode->next=p;
			p=newnode;
		}
		else
			p=remp;			
	}
}


int editlist(int name,char n,int num)
{
	struct node *p;
	p=(struct node *)(name);	
	int i=0;
	while(i<=num)
	{
		if(p->next==NULL&&i==num)
		break;
		if(p->next==NULL&&i!=num)
		{
			//printw("\nNO SUCH ENTRY\n");
			return -1;
		}
		p=p->next;
		i++;
	}	
	
	p->x=n;
	return 0;
}

int deletelist(int name,int n)
{
		struct node *p,*temp;
		p=(struct node *)(name);	
		int i=0;
		while(i!=n&&p!=NULL&&n>=0)
		{
			p=p->next;
			if(p->next==NULL)
			{
				//printw("\nTHERE IS NO ENTRY TO DELETE\n");
				return -1;
			}
			i++;
		}
		
		//printf("\nDELETING %d",p->next->x);
		temp=p->next;
		p->next=p->next->next;
		temp=NULL;
		free(temp);
		return 0;
}
char *list_to_string(int name , int from , int to ){
	struct node *p=(struct node *)(name);	
	char *c = 	(char * )malloc(sizeof(char)*(to-from+2));
	int counter=0;
	p = p->next;
	while( p != NULL ){
		if( counter >= from && counter < to )
			c[counter - from] = p->x;
		else if(counter == to){
			c[counter - from] = '\0';
			break;
		}
		p = p->next;
		counter++;
	}
	if( p == NULL )
		c[counter - from ] = '\0';
	return c;
}

void clearlist(int name){
	struct node *p=(struct node *)(name);	
	//p->next=NULL;
	//return;
	struct node *rem_next;
	p=p->next;
		while(p!=NULL){
		rem_next = p->next;
		free(p);
		p = rem_next;
	}
	p = (struct node *)(name);
	p->next = NULL;
}
	
int insertlist(int name,char *ch,int n) {
		n--;
		struct node *p,*temp;
		p=(struct node *)(name);	

	int i=-1;
	while(i!=n)
	{
		if(p->next==NULL)
		{
			//printw("\nCHECK LIST HERE\n");
		}
		p=p->next;
		i++;
	}
	temp=p->next;
	struct node *char_;
	i = 0;
	int ch_len = strlen( ch );
	while( i < ch_len ) {
		char_ = (struct node *)malloc(sizeof(struct node));
		char_->x = ch[i];
		p->next = char_;
		p = p->next;
		i++;
	}
	p->next = temp;
	return 0;
}

int printlist(int name)
{
	struct node *p;
	p=(struct node *)(name);	
	
	int i=0,tot=countlist(name);
	printf("\nList is : \"");
	while(i<tot)
	{
		//if(readlist(name,i)=='?')
		//printf("%c",'-');
		//else
		printf("%c",readlist(name,i));
		i++;
	}
	printf("\"\n");
	return 0;

}

char * get_string(int name , int from ,int to ) {
	char *s = ( char *  )malloc( ( to - from + 2  ) * sizeof( char ) );
	struct node *p=(struct node *)(name);	
	p = p->next;
	int counter=0;
	while ( p != NULL ) {
		if( counter >= from && counter < to ){
			s[counter - from] = p->x;
		}
		else if ( counter == to )
			s[ counter - from + 1 ] = '\0';
		p = p->next;
		counter++;
	}		
	return s;
}
	
int countlist(int name)
{
	struct node *p;
	p=(struct node *)(name);	

		int n=0;
		while(p->next!=NULL)
		{
			p=p->next;
			n++;
		}
	return n;
}
	
//////////////////////stack

struct stack
	{
		int pile[100],top;
	};

int createstack()
{
	struct stack *name;
	name=(struct stack *)malloc(sizeof(struct stack));
	name->top=-1;
	return (int)name;
}


int push(int tower1,int n)
{
	struct stack *tower;
	tower=(struct stack *)(tower1);
	tower->top=tower->top+1;
	tower->pile[tower->top]=n;
	return 0;
}
	
int pop(int tower1)
{
	struct stack *tower;
	tower=(struct stack *)tower1;

	if(tower->top==-1)
	{
		printf("\n\nSTACK ID : %d\nERROR : STACK EMPTY\n\n",tower1);
		return -1;
	} 
	else
	{	
		int temp=tower->pile[tower->top];
		tower->pile[tower->top]=0;
		tower->top--;
		return temp;
	}
}

int top(int tower1)
{
	struct stack *tower;
	tower=(struct stack *)tower1;
	int ret=tower->pile[tower->top];
	return ret;
}

int countstack(int tower1)
{
	struct stack *tower;
	tower=(struct stack *)tower1;

	return tower->top;
}
