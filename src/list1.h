/*struct node
	{
		char x;
		struct node *next;
	
	};
*/
int createlist(void);
int attachlist(int ,char *);
char readlist(int ,int );
void replace(int , char * , char *);
int editlist( int ,char, int );
int deletelist( int , int );
char *list_to_string(int , int  , int );
void clearlist( int );
int insertlist( int , char* , int );
int printlist( int );
char * get_string( int  , int  ,int ) ;
int countlist( int );

/*
struct stack
	{
		int pile[100],top;
	}stock;
*/
int createstack( void );
int push(int ,int );
int pop(int );
int top(int );
int countstack( int );
