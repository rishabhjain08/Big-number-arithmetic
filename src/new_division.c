#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tools.h"
#include "basic_ops.h"

#define PREC 200
#define ZERO_OFFSET '0'
#define DEBUG 0

char *_div( char *num , char *dnm ){
	if (num[0] == '.'){
		num = prepend(num, "0");
	}
	int num_len = strlen(num);
	int dnm_len = strlen(dnm);
	int num_dec_len = num_len - ( ( strstr ( num , "." )==NULL?num+num_len-1:strstr ( num , "." ) ) - num ) -1 ;
	int dnm_dec_len = dnm_len - ( ( strstr ( dnm , "." )==NULL?dnm+dnm_len-1:strstr ( dnm , "." ) ) - dnm ) -1 ;
	num = substr( num , 0 , num_len + dnm_dec_len + PREC , '.' , num_len , '0' );
	dnm = substr( dnm , 0 , dnm_len , '.' , dnm_len , '0' );
	num_len = strlen( num );
	dnm_len = strlen( dnm );
	int i=0,from=0,k=0,compare=0,digit = 0;
	char *remainder = NULL , *_divi , *ans = (char *) calloc ( num_len + 2 *2, sizeof ( char ) ) ;
	while( i < num_len ){
		if(DEBUG)
			printf("i is %d and num_len is : %d\n",i,num_len);
		if( remainder == NULL )
			_divi = substr( num , from , i+1 , '.' , num_len , '0' ); 		
		else
			_divi = prepend( substr( num , from , i+1 , '.' , num_len , '0' ) , remainder ); 		
		if(DEBUG)
			printf("_divi = \n%s\n",_divi);
		k=1;
		while(k <= 10){
			compare = -1*cmp( _divi , mul( dnm , int_char_array(k) ) );
			if(DEBUG)
				printf("\nk is %d and compare is %d\nand comparing to \n%s\n",k,compare , mul( dnm , int_char_array(k) ));
			if(k==1 && compare == 1 ){
				ans[digit++] = '0';
				break;
			}
			else if( compare == 0 ) {
				remainder = NULL;
				ans[digit++] = int_char_array(k)[0];
				from = i + 1;
				break;
			}
			else if ( compare == 1 ) {
				ans[digit++] = int_char_array(k-1)[0];
				remainder = sub ( _divi , mul ( dnm , int_char_array(k-1) ) );
				from = i + 1;
				break;
			}
			else if ( k== 10 ){
				if( DEBUG )
					printf("tried all from 1 to 10 and nothing fixes\n");
				//getchar();
			}
			k++;
		}
		if(DEBUG){
				printf("Denominator is : \n%s\n",dnm );
				printf("Digit is : \"%c\"\n",ans[digit-1]);
			}
		i++;
	}
	if(DEBUG)
		printf("Ans is : \n\"%s\"\n",ans);
	ans = insert_str( ans , "." , num_len - num_dec_len - PREC );
	if(DEBUG)
		printf("Final Ans is : \n\"%s\"\n",ans);
	
	ans = remove_leading_zeros( ans );
	//ans = chop(ans);
	return ans;
}
