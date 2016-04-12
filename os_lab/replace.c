#include<stdio.h>
#include<fcntl.h>
void main()
{	char orig[15],dup[15],buf[1000];
	int fd1,fd2,i,n;
	printf("\nEnter source file:");
	scanf("%s",orig);
	printf("\nEnter Destination file:");
	scanf("%s",dup);
	fd1=open(orig,O_RDONLY);
	fd2=open(dup,O_WRONLY);
	n=read(fd1,buf,1000);
	for(i=0;i<n;i++)
	{	switch(buf[i])
		{	case 'a':
			case 'A':
				buf[i]=' ';
				break;
			case 'e':
			case 'E':
				buf[i]=' ';
				break;
			case 'i':
			case 'I':
				buf[i]=' ';
				break;
			case 'o':
			case 'O':
				buf[i]=' ';
				break;
			case 'u':
			case 'U':
				buf[i]=' ';
				break;
		}
	}
	n=write(fd2,buf,n);
}
