#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include "basic_ops.h"
#include "tools.h"

#define CHAR_OFFSET '0'
#define PREC 100
#define DEBUG 0

char * _sqrt(char * n){
    int len_n = strlen(n);
    int len_sqrt = ( len_n + 1 ) / 2;
    char a[len_sqrt];
    a[0] = '1';
    int i;
    for (i = 1; i < len_sqrt; i++){
        a[i] = '0';
    }
    a[i] = '\0';
    char * iter = a;
    char *free_pointer;
    for (i = 0; i < PREC; i++){
        free_pointer  = _div(n, iter) ;
        char * term2 = chop ( free_pointer , PREC );
        //free(free_pointer);
        free_pointer = add(iter, term2) ;
        char * sum = chop ( free_pointer, PREC );
        //free(free_pointer);
       if(DEBUG)
        	printf("%d: iter is %s, term2 is %s, sum is %s\n", i, iter, term2, sum);

       // free(term2);
        
        free_pointer = _div(sum, "2") ;
        char * iter2 = chop ( free_pointer , PREC );
     //   free(sum);
   //     free(free_pointer);
        if (strcmp(iter, iter2) == 0 && i > 20){
        	iter = iter2;
        	break;
        }
        free_pointer = iter;
        iter = iter2;
 //       free(free_pointer);
    }
    if( DEBUG ) printf("Returning %s\n",iter);
    return iter;
}
