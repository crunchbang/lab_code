#include<stdio.h>
#include<dirent.h>
#include<string.h>
void main(int argc, char *argv[])
{	char dirname[10];
	DIR *p;
	struct dirent *d;
	strcpy(dirname,argv[1]);
	p=opendir(dirname);
	if(p==NULL)
	{	perror("\nCannot find directory");
		//exit(-1);
	}
	while(d=readdir(p))
		printf("%s\n",d->d_name);
}
