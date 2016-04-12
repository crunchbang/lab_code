#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int pid;
	
void childprocess(int n,int array[100])
{
	int i,a,b,m,count=0,c=0;                                                  
	pid_t pid;
	pid=getpid();
	for(i=0;i<n;i++)
	{
		m=array[i];
		a=0;
		b=1;
		c=0;
		if(m==a||m==b)
		{count++;}
		while(m>c)
		{
			c=a+b;
			a=b;
			b=c;
		}
		if(m==c)
		{count++;
		}
	}
	printf("Result of Child Process with process ID %d:\nNo. of fibonacci numbers : %d\n",pid,count);		
}
void parentprocess(int n,int array[100])
{
	pid_t pid;
	int i,j=0,k=0,l,x,count=0,m,fg;
	pid=getpid();
	for(i=0;i<n;i++)
	{	
		m=array[i];
		j=2;
		fg=0;
		while(j<=m/2)
		{	
			if(m%j==0)
			{fg++;}
			j++;
		}
		if(fg==0)
		{count++;
		}			
	}
	printf("\n\nResult of Parent process with process ID %d\nNo. of prime numbers : %d\n",pid,count);
}
main()
{
	char filename[20],buff[1000];
	int fd,n,i,j,array[100],m=1;
	printf("Enter filename:");
	scanf("%s",filename);
	fd=open(filename,O_RDONLY);
	n=read(fd,buff,1000);
	for(i=0;i<100;i++)
	{array[i]=0;}
	i=0;
	for(j=0;j<n;)
	{
		if(buff[j]!=' ')
		{	
			switch(buff[j])
			{
				case '0': 
					array[i]=array[i]*10; 
					break;
				case '1': 
					array[i]=array[i]*10+1; 
					break;
				case '2': 
					array[i]=array[i]*10+2; 
					break;
 				case '3': 
					array[i]=array[i]*10+3; 
					break;
				case '4': 
					array[i]=array[i]*10+4; 
					break;
				case '5': 
					array[i]=array[i]*10+5; 
					break;
				case '6': 
					array[i]=array[i]*10+6; 
					break;
				case '7': 
					array[i]=array[i]*10+7; 
					break;
				case '8': 
					array[i]=array[i]*10+8; 
					break;
				case '9': 
					array[i]=array[i]*10+9; 
					break;
			}
		}
		else
		{	m++;
			i++;
		}
		j++;
	}
	pid=fork();
	if(pid==0)
	childprocess(m,array);
	else
	parentprocess(m,array);
	close(fd);
}
