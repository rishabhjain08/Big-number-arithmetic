#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tools.h"
#include "basic_ops.h"

#define ZERO_OFFSET 48
#define DEBUG 0

char * mul_digit ( char * a , char b ) {
	 int a_len = strlen ( a );
	char * mul_result = ( char * ) calloc ( a_len + 1 +1 *2, sizeof( char ) );
	mul_result [ a_len + 1 ] = '\0';
	int i = a_len , carry = 0;
	while ( i > 0 ) {
		  mul_result[i] = ( ( b - '0' ) * ( a [ i - 1 ]  - '0' ) + carry ) % 10 + '0';
		  carry = ( b - '0' ) * ( a [ i - 1 ]  - '0' ) / 10;
	  	  i--;
	  }
	  mul_result[i] = carry + '0';
	 return mul_result ;
 }
 
 char * mul ( char * a , char * b ) {
 	int a_len = strlen ( a );
 	int b_len = strlen ( b );
 	int a_dec_len = a_len - ( ( strstr ( a , "." )==NULL?a+a_len-1:strstr ( a , "." ) ) - a ) -1 ;
	int b_dec_len = b_len - ( ( strstr ( b , "." )==NULL?b+b_len-1:strstr ( b , "." ) ) - b ) -1 ;
	a = substr ( a , 0 , a_len , '.' , a_len , '0' );
	b = substr ( b , 0 , b_len , '.' , b_len , '0' );
	a_len-= ( a_dec_len == 0 ? 0 :  1 );
	b_len-= ( b_dec_len == 0 ? 0 :  1 );
	int i = b_len - 1 , mul_len = 0;
	char *mul_result = '\0' ,*sum_result = int_char_array ( 0 );
	char *rem_dest;
	if( DEBUG ){
		printf("\\0 is printed as \"%c\"\n",'\0' ); 
		printf("a is %s and b is %s after removing the decimal\n",a,b);
		printf("a_dec_len : %d and b_dec_len : %d\n",a_dec_len , b_dec_len );
	}
	while ( i >= 0 ) {
		if( DEBUG )
			printf("Multiplying %s and %c", a , b[i] );
		//destroy ( mul_result );
		//getchar();
		mul_result = mul_digit ( a , b [ i ] );
		if( DEBUG )
			printf("\nand the result is : %s\n" , mul_result );
		mul_len = strlen ( mul_result );
		//rem_dest = sum_result;
		if( DEBUG ){
			printf("Adding \"%s\" and \"%s\" and the result is \"%s\"\n", sum_result , substr ( mul_result , 0 , mul_len + b_len - i - 1 , '.' , mul_len , '0' ) , add( sum_result , substr ( mul_result , 0 , mul_len + b_len - i - 1 , '.' , mul_len , '0' )  ) );
		}
		sum_result = add( sum_result , substr ( mul_result , 0 , mul_len + b_len - i - 1 , '.' , mul_len , '0' ) );
		//destroy ( rem_dest );
		if( DEBUG )
			printf("Sum is %s\n",sum_result );
		i--;
	}
	if( DEBUG )
		printf("Sum result = %s\n",sum_result );
	if( a_dec_len + b_dec_len != 0 )
		sum_result = insert_str ( sum_result , "." , strlen ( sum_result ) - ( a_dec_len + b_dec_len ) );
	sum_result = remove_leading_zeros ( sum_result );
	return sum_result;
}
