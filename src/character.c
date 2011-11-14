#include <stdlib.h>

char *char_to_string(char c){
	char * ret = (char * )calloc( 2  , sizeof( char ) );
	ret[ 0 ] = c;
	ret [ 1 ] = '\0';
	return ret;
}
