#include<stdio.h>
#include<fcntl.h>
#include<string.h>
void palindrome(char temp[1000],int pid)
{	int l,i,j,k,f,j1,i1;
	int count=0;
	char word[15],temp2[15],k1;
	printf("\nThe parent process.\t Process id:\t%d\n",pid);
	for(i=0;i<strlen(temp);i++)
	{
		for(j=0;(!isspace(temp[i])) && temp[i]!='\0';j++,i++)
			word[j]=temp[i];
		word[j]='\0';
		l=strlen(word);
		strcpy(temp2,word);

		for (i1 = 0, j1 = strlen(temp2)-1; i1 < j1; i1++, j1--) 
		{
			k1 = temp2[i1];
			temp2[i1] = temp2[j1];
			temp2[j1] = k1;
		}

		if(strcmp(word,temp2)==0)
			count++;		
	}
		printf("\nNo of palindrome=\t%d\n",count);
}
void space(char temp[1000],int pid)
{	int i,count=0;
	printf("\nThe child process.\t Process id:\t%d\n",pid);
	for(i=0;i<strlen(temp);i++)
		if(temp[i]==' ')
			count++;
	printf("\nThe no of spaces is:\t%d\n",count);
}
void main()
{	int pid,fid,n,j,i,k,count=0;
	char file[15],buf[1000],temp[15];
	printf("\nEnter the file:\t");
	scanf("%s",file);
	fid=open(file,O_RDONLY);
	n=read(fid,buf,1000);
	buf[n]='\0';	
	pid=fork();
	if(pid!=0)
	{		
		palindrome(buf,pid);
	}	
	else
	{	
		space(buf,pid);
	}
}
