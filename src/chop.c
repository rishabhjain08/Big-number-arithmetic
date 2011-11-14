#include "tools.h"
#include<string.h>

char *chop ( char * a , int PREC) {
 	
 	char  *new_a = clone ( a );
	int dec = get_decimal_position( new_a );
	int len_new_a = strlen(new_a);
	if( dec != len_new_a){
		if(dec + PREC <= len_new_a){
			new_a[dec + PREC] = '\0';
			}
	}
	return new_a;
//	return a;
}
