#include<stdio.h>
main()
{
int f[50],i,st,j,len,c,k,count=0;
int index[50],n;
int p,a,ch=1;
printf("1.Sequential\n2.Indexed\n3.Linked\n4.Exit\nEnter your choice:");
scanf("%d",&ch);
while(ch!=4){
switch(ch)
{
case 1:
	for(i=0;i<50;i++)
	f[i]=0;
	X:
	printf("\n enter starting block & length of files");
	scanf("%d%d",&st,&len);
	//printf("\n file not allocated(yes-1/no-0)");
	for(k=st;k<(st+len);k++)
	if(f[k]==0)
	count++;
	if(len==count)
	{
	for(j=st;j<(st+len);j++)
	if(f[i]==0)
	{
	f[j]=1;
	printf("\n%d\t%d",j,f[j]);
	if(j==(st+len-1))
	printf("\n the file is allocated to disk");
	}
	}
	else
	printf("file is not allocated");
	count=0;
	printf("\n if u want to enter more files(y-1/n-0)");
	scanf("%d",&c);
	if(c==1)
	goto X;
	else
	break;
case 2:
	for(i=0;i<50;i++)
	f[i]=0;
	Y:
	printf("enter index block");
	scanf("%d",&i);
	if(f[i]!=1)
	{
	f[i]=1;
	printf("enter no of files on index");
	scanf("%d",&n);
	}
	y:
	for(i=0;i<n;i++)
	scanf("%d",&index[i]);
	if(f[index[i]]==0)
	count++;
	if(count==n)
	{
	for(j=0;j<n;j++)
	f[index[j]]=1;
	printf("\nallocated");
	printf("\n file indexed");
	for(k=0;k<n;k++)
	printf("\n%d->%d:%d",i,index[k],f[index[k]]);
	}
	else
	{
	printf("\n file in the index already allocation");
	printf("\nenter another file indexed");
	goto y;
	}
	printf("\n index is already allocated");
	count=0;
	printf("\n if u enter one more block(1/0)");
	scanf("%d",&c);
	if(c==1)
	goto Y;
	break;
case 3:
	for(i=0;i<50;i++)
	f[i]=0;	
	printf("enter how many blocks already allocated");
	scanf("%d",&p);
	printf("\nenter the blocks nos");
	for(i=0;i<p;i++)
	{
	scanf("%d",&a);
	f[a]=1;
	}
	Z:
	printf("enter index sarting block & length");
	scanf("%d%d",&st,&len);
	k=len;
	if(f[st]==0)
	{
	for(j=st;j<(k+st);j++)
	{
	if(f[j]==0)
	{
	f[j]=1;
	printf("\n%d->%d",j,f[j]);
	}
	else
	{
	printf("\n %d->file is already allocated",j);
	k++;
	}
	}
	}
	else
	printf("\nif u enter one more (yes-1/no-0)");
	scanf("%d",&c);
	if(c==1)
	goto Z;
	break;	
	default:("Invalid entry! Try again!");
}
}
}
