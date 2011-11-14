#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

#define CHAR_OFFSET '0'

char * add (char *a, char *b){
	// a is the first number in string format
	// b is the second number in string format

	//printf("adding a : %s b : %s\n", a, b);

	int dec_pos_a = get_decimal_position(a);
	int dec_pos_b = get_decimal_position(b);
	int dec_pos_c = max(dec_pos_a, dec_pos_b) + 1;
	
	//printf("%s %s\n", a, b);
	
	//printf("%d %d %d\n", dec_pos_a, dec_pos_b, dec_pos_c);
	int len_a = strlen(a);
	int len_b = strlen(b);
	int len_c = max(len_a, len_b) + 1;
	
	//printf("%d %d %d\n", len_a, len_b, len_c);

	int len_frac_a = len_a - dec_pos_a - 1;
	int len_frac_b = len_b - dec_pos_b - 1;
	int len_frac_c = max(len_frac_a, len_frac_b);
	
	//printf("%d %d %d\n", len_frac_a, len_frac_b, len_frac_c);

	//char c[len_c];
	char * c = (char *) calloc(len_c *2, sizeof(char));
	
	int k;
	for (k = 0; k < len_c; k++){
		c[k] = '0';
	}
	c[len_c] = '\0';
	
	c[dec_pos_c] = '.';
	
	//printf("%s\n", c);
	int i;
	int carry = 0;
	int tmp;
	for (i = len_frac_c; i > 0; i--){
		if (i > len_frac_a){
			tmp = b[dec_pos_b + i] + carry - CHAR_OFFSET;
		}
		else if (i > len_frac_b){
			tmp = a[dec_pos_a + i] + carry - CHAR_OFFSET;
		}
		else{
			tmp = a[dec_pos_a + i] + b[dec_pos_b + i] + carry - 2 * CHAR_OFFSET;
		}
	
	//printf("tmp: %d\n", tmp);	
	    carry = 0;
		if (tmp >= 10){
            tmp -= 10;
            carry = 1;
		}
	c[dec_pos_c + i] = tmp + CHAR_OFFSET;
	
	//printf("%s\n", c);
	}
	
	//printf("%s\n", c);
	
	for (i = 1; i < dec_pos_c; i++){
		if (i > dec_pos_a){
			tmp = b[dec_pos_b - i] + carry - CHAR_OFFSET;
		}
		else if (i > dec_pos_b){
			tmp = a[dec_pos_a - i] + carry - CHAR_OFFSET;
		}
		else{
			tmp = a[dec_pos_a - i] + b[dec_pos_b - i] + carry - 2 * CHAR_OFFSET;
		}
		//printf("tmp: %d\n", tmp);
        carry = 0;
		if (tmp >= 10){
            tmp -= 10;
            carry = 1;
		}
		c[dec_pos_c - i] = tmp + CHAR_OFFSET;
		//printf("%s\n", c);
	}
	
	c[dec_pos_c - i] = carry + CHAR_OFFSET;
	//printf("%s\n", c);
	if (len_frac_c < 0){
		c[len_c] = '\0';
	}
	if (c[0] == '0'){
		//printf("%s\n", c + 1);
		return c + 1;
	}
	//printf("%s\n", c);
//	c = chop(c);
	//printf("RETURNING %s\n",c);
	return c;
}
