#include<stdio.h>
#include "list1.h"

#define ZERO '0'
//#define A 'A'
//#define a 'a'
#define unary -1
#define invalid_no_op -2
#define ok 1 
#define LEFT -1
#define RIGHT 1
#define no_need -1
#define DEBUG 0

int enclose_in_brackets(int , int );
int mov_dir(int  , int ,int );
char * enclose ( char *  , int );

char *bodmas( char *exp )
{	
	//printf("\nBODMASSING : %s and length is : %d\n",exp,countlist(_func));
	int _func = createlist();
	insertlist(_func , exp , 0 );
	insertlist(_func,"(",0);
	insertlist(_func,")",countlist(_func));
	int tot=countlist(_func);
	int i=0;
	char ch;
	while(i<tot)
	{
		if(readlist(_func,i)=='-')
		{
				//editlist(_func,'+',i);
				//insertlist(_func,"?",i + 1);
			if(i-1 >= 0)
				ch = readlist ( _func , i-1 );
			if(i-1<0){
					editlist(_func,'?',i);
					ch = readlist ( _func , i-1 );
			}
			else if( ch == ')' ||  ( ch > ZERO && ch < ZERO + 10 ) ) {
				editlist(_func,'+',i);
				insertlist(_func,"?",i +1);
			}
			else{
				editlist(_func,'?',i);
			}
		}
	i++;
}
	enclose_in_brackets(_func , '/');
	enclose_in_brackets(_func , '*');
	enclose_in_brackets(_func , '-');
	enclose_in_brackets(_func , '+');
	char * bodmassed = list_to_string(_func , 0 , countlist(_func) );
	return bodmassed ;
}

char * enclose( char *a , int op ){
	int _temp = createlist();
	
	if( DEBUG ) printf("id : l0 and a is %s\n",a);
	
	insertlist( _temp , a , 0 );
	
	if( DEBUG ) printf("id : l1\nprintlist is : ");
	if( DEBUG ) printlist(_temp);
	if( DEBUG ) printf("\n");
	//exit(9);
	
	enclose_in_brackets ( _temp , op );
	
	if( DEBUG ) printf("After enclosing %c printlist is : " , op );
	if( DEBUG ) printlist(_temp);
	if( DEBUG ) printf("\n");
	
	 char *enclosed = list_to_string ( _temp , 0 ,countlist ( _temp ) );
	
	if( DEBUG ) printf("Returning after bracketing : %s\n"  , enclosed ); 
	
	return enclosed;
}

int enclose_in_brackets(int _func , int op){
	if( DEBUG ) printf("\noperator is : %c and the expression is : ",op);
	if( DEBUG ) printlist(_func);
	if( DEBUG ) printf("\n");
	int i=0;
	int tot=countlist(_func),lpos,rpos;
	while(i<tot){
			//printf("\nChar at i : %d\n",i);
			if(readlist(_func,i)==op){
				if( DEBUG ) printf("\nChecking at i : %d\n",i);
				lpos=mov_dir(_func , i , LEFT);
				if( DEBUG ) printf("\nReturned from left and lpos : %d\n",lpos);
				rpos=mov_dir(_func , i , RIGHT);
				if( DEBUG ) printf("\nReturned from right and rpos : %d\n",rpos);
				if(lpos!=no_need&&rpos!=no_need){
					insertlist(_func,"(",lpos);
					insertlist(_func,")",rpos + 1);
					tot+=2;
					i=rpos+1;
				}
			}
		i++;
	}
	if( DEBUG ) printf("Insertied in _func and func is : ");
	if( DEBUG ) printlist(_func);
	
	return _func;
}

int mov_dir(int _func , int pos,int dir){
	//int stack = createstack ( ) ;
	int brackets = -1;
	char ch;
	int i = pos+dir , bracket_count=0;
	//int pop_value;
	ch=readlist(_func,pos+dir);
	//int func_length=countlist(_func);
	if(ch==')'||ch=='(')
		brackets=1;
	if( DEBUG ) printf("list is : ");
	if( DEBUG ) printlist(_func);
	if( DEBUG ) printf("\n");
	while ( 1 ) {
		ch = readlist( _func , i );
		if( DEBUG ) printf("%c",ch);
		if ( brackets == 1 ) {
			if( ( ( dir == LEFT && ch == ')' ) || ( dir == RIGHT && ch == '(' ) ) )
				bracket_count++;//push(stack,((dir==LEFT)?')':'('));
			else if(((dir==LEFT&&ch=='(')||(dir==RIGHT&&ch==')')))
				bracket_count--;//pop_value = pop(stack);
			if(bracket_count<0)//will never occur for a correct expression
				return no_need;
			else if(bracket_count==0){//countstack(stack)==0){
/*				ch=readlist(_func,i+dir);
				if(i+dir>-1&&i+dir<func_length&&( ( ( dir == LEFT && ch == '(' ) || ( dir == RIGHT && ch == ')' ) ) ) ) {
					return no_need;		
				}
*/
				if( DEBUG ) printf("\ni to the dir %d is : %d and returning : %d ",dir,i,(i + (( dir == LEFT ) ?0:1)));
				return (i+((dir==LEFT)?0:1));
			}
		}
		else{
			if((ch>ZERO+9||ch<ZERO)&&ch!='.'&&ch!='?'){
				if( DEBUG ) printf("\ni to the dir %d is : %d and returning : %d ",dir,i,(i + (( dir == LEFT ) ?1:0)));
				return ( i + (( dir == LEFT ) ?1:0)) ;
			}
		}
		i += dir;
		//printf ("id : xpsc\nI am in a infine loop");
}
}
