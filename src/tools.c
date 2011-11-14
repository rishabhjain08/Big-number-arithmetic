#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int get_decimal_position(char * a){
	int i = 0;
	while (a[i] != '\0'){
		if (a[i] == '.'){
			return i;
		}
		i++;
	}
	//a[i] = '.';
	//a[i + 1] = '\0';
	return i;
}

int max(int a, int b){
	if (a > b){
		return a;
	}
	return b;
}

char * remove_leading_zeros(char * a){
    int i;
    for (i = 0; a[i] != '\0'; i++){
        if (a[i] != '0'){
            if (a[i] == '.')
            {
                return a + i - 1;
            }
            return a + i;
        }
    }
    return a + i - 1;
}

void _remove_ending_zeros(char * a){
    int len = strlen(a);
    int dec = get_decimal_position(a);
    int i;
    for (i = len; i > 0; i--){
        if (i < dec){
            return;
        }
        if (a[i] != '\0' && a[i] != '0'){
            a[i + 1] = '\0';
            return;
        }
    }
}

void remove_ending_zeros(char * a){
    int len = strlen(a);
    int dec = get_decimal_position(a);
    int i;
    for (i = len - 1; i >= dec; i--){
        if (a[i] != '0'){
            if (a[i] == '.'){
                a[i] = '\0';
                return;
            }
            a[i + 1] = '\0';
            return;
        }
    }
}


char * append(char * a, char * suffix){
    int len_a = strlen(a);
    int len_suffix = strlen(suffix);
    char * ret = (char *) calloc((len_a + len_suffix + 1) *2, sizeof(char));
    ret[0] = 0;
    strcpy(ret, a);
    strcat(ret, suffix);
    ret[len_a + len_suffix] = '\0';
    return ret;
}

char *substr( char *str , int from , int to ,char exclude , int length , char padd_with ) {
	char * c = (char *) calloc((to-from+1)*2,sizeof(char));
	int i=0;
	int offset=0;
	char ch;
	while(i<to-from){
		if ( from + i >= length )
			ch = padd_with ; 
		else if(*(str+from+i)==exclude){
			offset++;
			i++;
			continue;
		}
		else
			ch = *(str+from+i); 
		c[i-offset] = ch;
		i++;
	}
	c[i]='\0';
	return c;
}

char *prepend(char *c1,char *c2){
	int c1_len=strlen(c1);
	int c2_len=strlen(c2);
	int i=0,new_len=c1_len+c2_len;
	//printf("\nI am here");
	char *newc=(char *)calloc((new_len+1)*2,sizeof(char));
	while( i < new_len ){
		if(i<c2_len)
			*(newc + i ) = *(c2 + i);
		 else
		 	*(newc + i ) = *( c1 + i - c2_len );
		i++;
	}
	*( newc + i ) = '\0';
//	printf("\nI reached here");
	return newc;
}

char *int_char_array(int i){
	int count = 0;
	int rem_i = i;
	while( i != 0 ) {
		i/=10;
		count++;
	}
	char *ret_arr = calloc(count + 1 *2, sizeof( char ) );
	ret_arr[count] = '\0';
	i=count - 1;
	while(i >= 0 ) {
		ret_arr[i] =  rem_i%10 + '0' ;
		rem_i/=10;
		i--;
	}
	return ret_arr;
}

char *insert_str(char *str , char *s, int index){
	int s_len = strlen( s );
	int str_len = strlen( str );
	int i=0,offset=0;
	char *new_str=(char *)calloc( s_len + str_len + 1 *2, sizeof( char ) );
	while ( i < s_len + str_len ) {
		while( i == index && offset<s_len){	
			new_str[i+offset] = s[offset];
			offset++;
		}
		new_str[i+offset] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return new_str;
}

char *clone ( char * c ) {
	int c_len = strlen ( c );		
	char *new_c = ( char * ) calloc ( c_len + 1 *2, sizeof( char ) );
	int i = 0;
	while ( i < c_len ) {
		new_c[ i ] = c[ i ];
		i++;
	}
	new_c[ i ] = '\0';
	return new_c;
}

void destroy( char * c ){
	int i=0;
	while ( c[i] != '\0' ) {
		free ( c + i );
		i++;
	}
	free ( c + i );
	return;
}

char *reverse_string ( char * s ) {
	int s_len = strlen ( s );
	char *new_s = (char * )malloc( sizeof( char ) * (s_len + 1 ) );
	int i = 0;
	while( i < s_len ){
		new_s[i] = s[ s_len - i -1];
		i++;
	}
	new_s[i] = '\0';
	return new_s;
}
