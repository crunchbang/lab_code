#include<stdio.h>
#include<string.h>
void main(int argc, char *argv[])
{	char fn[10],pat[10],temp[200];
	FILE *fp;
	strcpy(fn,argv[1]);
	strcpy(pat,argv[2]);
	fp=fopen(fn,"r");
	while(fgets(temp,1000,fp)!=NULL)
		if(strstr(temp,pat))
			printf("%s",temp);
	fclose(fp);
}
