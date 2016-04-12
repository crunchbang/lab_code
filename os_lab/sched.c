#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int n,w[10],i,j,h,t,tt;
float avg=0,tat=0;
int pName[100],burTime[100],arrTime[100];
int ptime[10],k=0,s=0,sum=0;
char name[10][10],temp[25];
int t1,prt[25];
int p[20],a[20],b[20],br[20],ta[20],pr[20],gantt[100][2],n1,n2,n3,n4,f=0,d,e=0,g,time=0,t2,t3,t4,t5,t6; 
float v1=0.0,v2=0.0;
int z[10],b1[10],z1[10],m[50],r,q,c=0;
float awt,att;

void fcfs();
void sjf();
void psjf();
void prio();
void ppr();
void rrs();
void rr();
void average();
void display(int[],int);

void main()
{
	int choice=1;
	while(choice!=7)
	{	
		printf("\n1.FCFS\n2.SJF-Non Preemptive\n3.SJF-Preemptive\n4.PS-Non preemptive\n5.PS-Preemptive\n6.RR\n7.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: fcfs();
				break;
			case 2: sjf();
				break;
			case 3: psjf();
				break;
			case 4: prio();
				break;
			case 5: ppr();
				break;
			case 6: rrs();
				break;
			case 7: exit(0);
				break;
			default: printf("Invalid Entry");
		}
	}
}


void fcfs()
{
	tat=0;
	printf("\n\tJOB SCHEDULING ALGORITHM[FCFS]");
	printf("\n\t*****************************\n");
	printf("\nEnter how many jobs:");
	scanf("%d",&n);
	printf("\nEnter burst time for corresponding job....\n");
	for(i=1;i<=n;i++)
	{
		printf("\nProcess %d:",i);
		scanf("%d",&b[i]);
		a[i]=i;
	}
	w[1]=0;
	printf("\nprocess %d waiting time is 0",a[1]);
	for(i=2;i<=n;i++)
	{
		w[i]=b[i-1]+w[i-1];
		printf("\nProcess %d waiting time: %d",a[i],w[i]);
		avg+=w[i];
	}
	for(i=1; i<=n; i++)
		tat = tat + b[i]+w[i];
	printf("\nTAT:%f\n",tat);	
	printf("\ntotal waiting time:%f",avg);
	printf("\n\nThe average waiting time is: %f\n",avg/n);
	printf("\n\nThe average turn around time is: %f\n",tat/n);
	printf("\nGantt Chart\n*********************\n\n");
	for(i=0;i<n;i++)
		printf(" ---");
	printf("\n");
	for(i=0;i<n;i++)
		printf("| %d ",i+1);
	printf("|\n");
	for(i=0;i<n;i++)
		printf(" ---");
	printf("\n");
	j=0;
	for(i=1;i<=n+1;i++)
	{
		printf("%d   ",j);
		j=j+b[i];
	}
}




void sjf()
{
	printf("\n\tJOB SCHEDULING ALGORITHM[SJF: NON-PREEMPTIVE]");
	printf("\n\t*****************************\n");
	printf("\nEnter how many jobs:");
	scanf("%d",&n);
	printf("\nEnter burst time for corresponding job....\n");
	for(i=1;i<=n;i++)
	{
		printf("\nProcess %d:",i);
		scanf("%d",&b[i]);
		a[i]=i;
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if(b[i]>b[j])
			{
				t=b[i];
				tt=a[i];
				b[i]=b[j];
				a[i]=a[j];
				b[j]=t;
				a[j]=tt;
			}
	w[1]=0;
	printf("\nprocess %d waiting time is 0",a[1]);
	for(i=2;i<=n;i++)
	{
		w[i]=b[i-1]+w[i-1];
		printf("\nProcess %d waiting time: %d",a[i],w[i]);
		avg+=w[i];
	}
	for(i=1; i<=n; i++)
		tat = tat + b[i]+w[i];
	printf("\ntotal waiting time:%f",avg);
	printf("\n\nThe average waiting time is: %f\n",avg/n);
	printf("\n\nThe average turn around time is: %f\n",tat/n);
	printf("\nGantt Chart\n*********************\n\n");
	for(i=0;i<n;i++)
		printf(" ---");
	printf("\n");
	for(i=1;i<=n;i++)
		printf("| %d ",a[i]);	
	printf("|\n");
	for(i=0;i<n;i++)
		printf(" ---");
	j=0;
	printf("\n");
	for(i=1;i<=n+1;i++)
	{
		printf("%d   ",j);
		j=j+b[i];
	}	
}



void getData()
{
	int i;
	printf("\nEnter the no. of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process name :");
		scanf("%d",&pName[i]);
		printf("\nEnter the arrival time for process %d :",pName[i]);
		scanf("%d",&arrTime[i]);
		printf("\nEnter the burst time for process %d :",pName[i]);
		scanf("%d",&burTime[i]);
	}
	printf("\n\n");
}

void preSJF()
{
	int i,j,prefIndex,timeSlice[100],totBurTime=0,burTimeRem[100];
	for(i=0;i<n;i++)
		totBurTime+=burTime[i];
	for(i=0;i<n;i++)
		burTimeRem[i]=burTime[i];
	i=0;
	while(i<totBurTime)
	{
		for(j=0;j<n;j++)
			if(burTimeRem[j]!=0)
			{	prefIndex=j;
				break;
			}
		for(j=0;j<n;j++)
		{
			if(arrTime[j]<=i && burTimeRem[j]!=0 && burTimeRem[j]<burTimeRem[prefIndex])
			prefIndex=j;
		}
		timeSlice[i]=pName[prefIndex];
		burTimeRem[prefIndex]-=1;
		i++;
	}
	display(timeSlice,totBurTime);
}


void display(int timeSlice[100],int totBurTime)
{
	int i,j,count,loc,prName,trnArndTme=0,wTime[100],totWait=0;
	printf("\nGANTT CHART:\n");
	for(i=0;i<totBurTime*4;i++)
		printf("-");
	i=0;
	printf("\n|");
	while(i<totBurTime)
	{
		prName=timeSlice[i];
		for(count=1;timeSlice[i+count]==prName;count++);
		for(j=0;j<(count*2)-1;j++)
			printf(" ");
		printf("%d",prName);
		for(j=0;j<(count*2)-1;j++)
			printf(" ");
		printf("|");
		i+=count;
	}
	printf("\n");
	for(i=0;i<totBurTime*4;i++)
		printf("-");
	i=0;
	printf("\n0");
	while(i<totBurTime)
	{
		prName=timeSlice[i];
		for(count=1;timeSlice[i+count]==prName;count++);
			for(j=0;j<(count*4)-1;j++)
				printf(" ");
		i+=count;
		trnArndTme+=i;
		printf("%d",i);
	}
	printf("\n");

	//Waiting Time
	for(i=0;i<n;i++)
	{
		for(j=0;j<totBurTime;j++)
			if(timeSlice[j]==pName[i])
				loc=j;
		j=loc;
		while(timeSlice[j]==pName[i]) 
		j++;
		wTime[i]=loc-(burTime[i]-(j-loc));
	}
	printf("\nProcess\tWaiting Time");
	for(i=0;i<n;i++)
		printf("\n%d\t%d",pName[i],wTime[i]);
	printf("\nTotal turn around time:%d",trnArndTme);
	printf("\nAverage turn around time:%.2f",((float)trnArndTme/n));
	for(i=0;i<n;i++)
		totWait+=wTime[i];
	printf("\nTotal waiting time:%d",totWait);
	printf("\nAverage waiting time:%.2f",(float)totWait/n);
	printf("\n");
}


void psjf()
{	printf("SCHEDULING ALGORITHM : [SJF-PREEMPTIVE]\n");
	printf("****************************************\n");
	getData();
	preSJF();
}


void prio()
{
	printf("SCHEDULING ALGORITHM :[PS-NON PREEMPTIVE]\n");
	printf("******************************************\n");
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the name of the process");
		printf("%d\t",i+1);
		scanf("%s",name[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("enter the process time for ");
		printf("%s\t",name[i]);
		scanf("%d",&ptime[i]);
	}
	for(i=0;i<n;i++)
	{
		printf("enter the priority for %s\t",name[i]);
		scanf("%d",&prt[i]);
	}
	printf("processname\t processtime\t priority\n");
	for(i=0;i<n;i++)
		printf("%s\t\t%d\t\t%d\n",name[i],ptime[i],prt[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(prt[i]<prt[j])
			{
				t=prt[i];prt[i]=prt[j];prt[j]=t;
				t1=ptime[i];
				ptime[i]=ptime[j];ptime[j]=t1;
				strcpy(temp,name[j]);	
				strcpy(name[j],name[i]);
				strcpy(name[i],temp);
			}
		}	
	}
	printf("Process Name\t Process time\t Priority\n");
	for(i=0;i<n;i++)
		printf("%s\t\t%d\t\t%d\n",name[i],ptime[i],prt[i]);
	printf("\t PRIORITY SCHEDULING\n");
	for(i=0;i<n;i++)
	{
		printf("Process %s from %d to %d \n\n",name[i],k,(k+ptime[i]));
		k=k+ptime[i];
	}
	printf("Waiting time\n");
	for(i=0;i<=(n-1);i++)
	{
		printf("Waiting time of %s is %d\n",name[i],s);
		if(i<(n-1))
		{
			s+=ptime[i];
			sum+=s;
		}
	}
	awt=(float)sum/n;
	printf("Average waiting time is:");
	printf("%2f\n\n",awt);
	sum=s=0;
	printf("Turn around time\n");
	for(i=0;i<n;i++)
	{
		s+=ptime[i];
		sum+=s;
		printf("Turn around time of %s is %d\n",name[i],s);
	}
	att=(float)sum/n;
	printf("Average turnaround time is ");
	printf("%2f\n",att);
	printf("\nGANTT CHART\n\n");
	for(i=0;i<n;i++)
		printf(" ---");
	printf("\n");
	for(i=0;i<n;i++)
		printf("| %s ",name[i]);
	printf("|\n");
	for(i=0;i<n;i++)
		printf(" ---");
	printf("\n");
	j=0;
	for(i=0;i<=n;i++)
	{	
		printf("%d   ",j);
		j=j+ptime[i];
	}	
}


void ppr()
{	printf("SCHEDULING ALGORITHM :[PS-PREEMPTIVE]");
 	printf("\n************************************\n");
 	printf("Enter the number of processes:");
	scanf("%d",&n);
	e=0;
	while (e<n) 
 	{ 
		printf("Enter process name:");
		scanf("%d",&p[e]);
		printf("Enter process arrival time:");
		scanf("%d",&a[e]);
		printf("Enter process burst time:");
		scanf("%d",&b[e]);
		printf("Enter the process priority:");
		scanf("%d",&pr[e]);
	  	br[e]=b[e]; 
  		e++; 
 	} 
 	while (1) 
 	{	 
   		for (i=1;i<e;i++) 
    			if ((br[0]==0 || time<a[0]?1:pr[i]<pr[0]) && time>=a[i] && br[i]!=0) 
    			{ 
     				t1=p[0]; 
     				t2=a[0]; 
     				t3=b[0];; 
     				t4=pr[0];; 
     				t5=br[0]; 
     				t6=ta[0]; 
	     			p[0]=p[i]; 
     				a[0]=a[i]; 
     				b[0]=b[i]; 
     				pr[0]=pr[i]; 
     				br[0]=br[i]; 
     				ta[0]=ta[i]; 
				p[i]=t1; 
     				a[i]=t2; 
     				b[i]=t3; 
     				pr[i]=t4; 
     				br[i]=t5; 
     				ta[i]=t6; 
    			}  	 
 	 	if (a[0]>time || br[0]==0) 
  		{ 
   			if (f==0 || gantt[f-1][0]!=-1) 
   			{ 
    				gantt[f][0]=-1; 
    				gantt[f++][1]=time; 
   			} 
  		} 
  		else if (br[0]!=0) 
  		{ 
   			if (f==0 || gantt[f-1][0]!=p[0]) 
   			{ 
    				gantt[f][0]=p[0]; 
    				gantt[f++][1]=time; 
   			} 
   			if (--br[0]==0) 
   	 		ta[0]=time+1-a[0]; 
  		} 
		time++; 
	  	c=0; 
  		for (i=0;i<e;i++) 
   			if (br[i]!=0) 
    				c=1; 
  		if (c==0) 
   			break; 
 	} 
 	gantt[f][1]=time; 
	printf ("%8s%8s%8s%8s%8s%8s\n\n","P","A","B","Pri","W","TAT"); 
 	for (i=0;i<e;i++) 
  	printf ("\n%8d%8d%8d%8d%8d%8d\n",p[i],a[i],b[i],pr[i],ta[i]-b[i],ta[i]); 
 	for(i=0;i<e;i++) 
 	v1+=ta[i]-b[i]; 
 	printf("\n\nAverage waiting time is:%f\n\n",v1/e);  

 	for(i=0;i<e;i++) 
  		v2+=ta[i]; 
 	printf("\n\nAverage turnaround time is:%f\n\n",v2/e);   
 	printf ("\n\nTHE GANTT CHART IS:\n\n "); 
 	for (i=0;i<f;i++) 
  		printf ("--- "); 
 	printf ("\n|"); 
 	for (i=0;i<f;i++) 
  		printf (gantt[i][0]==-1?"   |":" %d |",gantt[i][0]); 
 	printf ("\n "); 
 	for (i=0;i<f;i++) 
  		printf ("--- "); 
 	printf ("\n0"); 
 	for (i=1;i<=f;i++) 
  		printf ("  %2d",gantt[i][1]);  
}


void rrs()
{
	printf("\n\tJOB SCHEDULING ALGORITHM[RR]");
	printf("\n\t****************************\n");
	printf("\nEnter how many jobs:");
	scanf("%d",&n);
	n1=n;
	printf("\nEnter burst time for corresponding job...\n");
	for(i=1;i<=n;i++)
	{
		printf("\nProcess %d: ",i);
		scanf("%d",&b[i]); z[i]=b[i];
		b1[i]=b[i];
		z1[i]=b[i];
	}
	printf("\nENTER THE TIME SLICE VALUE:");
	scanf("%d",&q);
	rr();
	average();
	printf("\n\nGANTT CHART\n\n");
	for(i=1;i<=n1;i++)
		c=c+b1[i];
	c=c/q;
	for(i=0;i<=c;i++)
		printf(" ---");
	j=1;
	printf("\n");
	for(i=0;i<=c;i++)
	{	
		while((z1[j]<=0)||(j>n1))
		{
			if(z1[j]<=0)
				j++;
			if(j>n1)
				j=1;
		}	
  
		if(z1[j]>0)
		{	printf("| %d ",j);
	    	  	z1[j]=z1[j]-q;
		  	j++;
		}
	}
	printf("|\n");
	for(i=0;i<=c;i++)
		printf(" ---");
	printf("\n");
	j=1;
	t=0;
	printf("%d   ",t);
	for(i=0;i<=c;i++)
	{	while((j>n1)||(b1[j]==0))
		{
			if(j>n1)
				j=1;
			if(b1[j]==0)
				j++;
		}	
		if((b1[j]>=q)&&(j<=n1))
		{	t=t+q;
			b1[j]=b1[j]-q;	
		}
		else if((b1[j]<q)&&(b1[j]>0))
		{
			t=t+b1[j];
			b1[j]=0;
		}
		printf("%d   ",t);
		j++;
	}
}



void rr()
{
	int max=0;
	max=b[1];
	for(j=1;j<=n;j++)
		if(max<=b[j])
			max=b[j];
	if((max%q)==0)
		r=(max/q);
	else
		r=(max/q)+1;
	for(i=1;i<=r;i++)
	{
		printf("\nround %d",i);
		for(j=1;j<=n;j++)
		{
			if(b[j]>0)
			{
				b[j]=b[j]-q;
				if(b[j]<=0)
				{
					b[j]=0;
					printf("\nprocess %d is completed",j);
				}
				else
					printf("\nprocess %d remaining time is %d",j,b[j]);
			}
		}
	}

}


void average()
{
	for(i=1;i<=n;i++)
	{
		e=0;
		for(j=1;j<=r;j++)
		{
			if(z[i]!=0)
			{
				if(z[i]>=q)
				{	m[i+e]=q; 
					z[i]-=q;
				}
				else
					m[i+e]=z[i]; z[i]=0;
			}
			else
				m[i+e]=0;
			e=e+n;
		}
	}
	for(i=2;i<=n;i++)
		for(j=1;j<=i-1;j++)
			avg=avg+m[j];
	for(i=n+1;i<=r*n;i++)
	{
		if(m[i]!=0)
			for(j=i-(n-1);j<=i-1;j++)
				avg=m[j]+avg;
	}
	f=avg/n;
	printf("\nTOTAL WAITING:%f",avg);
	printf("\n\nAVERAGE WAITING TIME:%d\n",f);
}

