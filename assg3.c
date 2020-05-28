#define _XOPEN_SOURCE
#include<stdio.h>
#include <ctype.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "%s salt key\n", argv[0]);
        return 1;
    }
    char *encrypted = NULL;
  
    if((encrypted = crypt(argv[2], "$1$BDrJtvL0$")) == NULL)
    {
        fprintf(stderr, "crypt error:%s\n", strerror(errno));
    }

    printf("%s encrypted:%s\n", argv[2], encrypted);
    printf("===============\n");
    //char *key;
    char *key = (char*)malloc(sizeof(char)*12);
    *key='C';
    *(key+1)='*';
    *(key+11)='c';
    *(key+10)='s';
    *(key+9)='m';
    *(key+12)='\0';
    for(int i=2;i<9;i++){
	*(key+i) = '0';
    }
    //key[2]='1';
    printf("%s\n",key);
    for(int i=0;i<9999999;i++){
	//itoa(100,key+2,10);
	char str[8]="0000000";
	sprintf(str,"%07d",i);
	for(int j=0;j<7;j++){
		char t = str[j];
		//printf("%c",t);
		*(key+2+j) = t;
		//printf("%c",key[2+j]);
	}
	printf("%s\n",key);
	
	encrypted = crypt(key,"$1$BDrJtvL0$");
    	printf("\n%s encrypted:%s\n", key, encrypted);
	if(strcmp(encrypted,"$1$BDrJtvL0$fXwIUSo2ynkgx3uq.ptry.")==0){
		printf("result:%s\n",key);
		break;
	}
    }	
    return 0;
}
