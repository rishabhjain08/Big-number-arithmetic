#include "basic_ops.h"
#include "tools.h"
#include "parser.h"
#include <stdio.h>
#include<stdlib.h>
#include "io.h"

int main(int argc, char * argv[]){
    if(argc == 1){
    output ( parse ( input (  ) ) );
		//printf("Output Written to the file\nThe output is : %s\n", parse(input()) );
	}
	else if (argv[1][0] == 'a'){
        printf("%s\n", add(argv[2], argv[3]));
    }
    else if (argv[1][0] == 's'){
        printf("%s\n", sub(argv[2], argv[3]));
    }
    else if (argv[1][0] == 'm'){
        printf("%s\n", mul(argv[2], argv[3]));
    }
    else if (argv[1][0] == 'd'){
        printf("%s\n", _div(argv[2], argv[3]));
    }
    else if (argv[1][0] == 'c'){
        printf("%d\n", cmp(argv[2], argv[3]));
    }
    else if (argv[1][0] == 'l'){
        printf("%s\n", remove_leading_zeros(argv[2]));
    }
    else if (argv[1][0] == 'e'){
        remove_ending_zeros(argv[2]);
        printf("%s\n", argv[2]);
    }
    else if (argv[1][0] == 'q'){
        printf("%s\n", _sqrt(argv[2]));
    }
    else if(argv[1][0] == 'i' ){
    	printf("%d\n",-cmp(argv[2] , argv[3]));
	}
	else if(argv[1][0] == 'p' ){
		printf("%s\n",parse(argv[2]));
	}
	else if(argv[1][0] == 'f' ){
		output ( parse ( input (  ) ) );
		//printf("Output Written to the file\nThe output is : %s\n", parse(input()) );
	}
	return 0;
}
