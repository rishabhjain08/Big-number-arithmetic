#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "basic_ops.h"
#define CHAR_OFFSET 48
#define DEBUG 0

char * sub (char a[], char b[]){
	// a is the first number in string format
	// b is the second number in string format
    if (cmp(a, b) == 0){
        return "0";
    }
    else if (cmp(a, b) == -1){
        char * s = sub(b, a);
        int len_s = strlen(s);
        char * r = (char *) calloc((len_s + 2) *2, sizeof(char));
        r[0] = '-';
        int i;
        for (i = 0; i < len_s; i++){
            r[1 + i] = s[i];
        }
        return r;
    }
	if (DEBUG) printf("%s %s\n", a, b);

	int dec_pos_a = get_decimal_position(a);
	int dec_pos_b = get_decimal_position(b);
	int dec_pos_c = max(dec_pos_a, dec_pos_b) + 1;
	
	if (DEBUG) printf("%s %s\n", a, b);
	
	if (DEBUG) printf("%d %d %d\n", dec_pos_a, dec_pos_b, dec_pos_c);
	int len_a = strlen(a);
	int len_b = strlen(b);
	int len_c = max(len_a, len_b) + 1;
	
	if (DEBUG) printf("%d %d %d\n", len_a, len_b, len_c);

	int len_frac_a = len_a - dec_pos_a - 1;
	int len_frac_b = len_b - dec_pos_b - 1;
	int len_frac_c = max(len_frac_a, len_frac_b);
	
	if (DEBUG) printf("%d %d %d\n", len_frac_a, len_frac_b, len_frac_c);

	//char c[len_c];
	char * c = (char *) calloc(len_c *2, sizeof(char));
	
	int k;
	for (k = 0; k < len_c; k++){
		c[k] = '0';
	}
	c[len_c] = '\0';
	
	c[dec_pos_c] = '.';
	
	if (DEBUG) printf("%s\n", c);
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
			tmp = a[dec_pos_a + i] - b[dec_pos_b + i] + carry;
		}
	
	if (DEBUG) {printf("tmp: %d\n", tmp);}
	    carry = 0;
		if (tmp < 0){
            tmp += 10;
            carry = -1;
		}
	c[dec_pos_c + i] = tmp + CHAR_OFFSET;
	
	if (DEBUG) printf("%s\n", c);
	}
	
	if (DEBUG) printf("%s\n", c);
	
	for (i = 1; i < dec_pos_c; i++){
		if (i > dec_pos_a){
			tmp = b[dec_pos_b - i] + carry - CHAR_OFFSET;
		}
		else if (i > dec_pos_b){
			tmp = a[dec_pos_a - i] + carry - CHAR_OFFSET;
		}
		else{
			tmp = a[dec_pos_a - i] - b[dec_pos_b - i] + carry;
		}
		if (DEBUG) printf("tmp: %d\n", tmp);
        carry = 0;
		if (tmp < 0){
            tmp += 10;
            carry = -1;
		}
		c[dec_pos_c - i] = tmp + CHAR_OFFSET;
		if (DEBUG) printf("%s\n", c);
	}
	
	c[dec_pos_c - i] = carry + CHAR_OFFSET;
	if (DEBUG) printf("%s\n", c);
	if (len_frac_c < 0){
		c[len_c] = '\0';
	}
    
    c = remove_leading_zeros(c);
    remove_ending_zeros(c);
	if (DEBUG) printf("%s\n", c);
	//c = chop( c , PREC);
	return c;
	
}


