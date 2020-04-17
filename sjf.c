#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
 
int main() 
{ 
 
  int count,i,j;
  int m=0,n;
  int y=0,time;
  int remain=0,min;
  int flag=0; 
  int wait_time=0;
  int turn_a_time=0;
  int a_time[10];
  int b_time[10];
  int p[10];
  int z[10];
  float k=0,x=0; 
  printf("Enter total number of Process you want:\t "); 
  scanf("%d",&n); 
  printf("\n\t for the first 3 sec cpu remain itself idle and the arival time should be greater than 2 sec \n");
  printf("\n\t the Burst time should be less than 10\n");
  for(count=0;count<n;count++) 
  { 
    printf("Enter Time of arival and  Time of burst for Process Process Number %d :",count+1); 
    scanf("%d",&a_time[count]); 
    scanf("%d",&b_time[count]);  
  } 

for(i=0;i<n;i++)
{
	if(a_time[i]==0)
	{
		printf("\nS Arival time is invalid \n");
		getch();
		exit(1);
	}
}
for(i=0;i<n;i++)
{
	if(a_time[i]<3)
	{
		printf("\nS INVALID Arrival Time it should be greater than 3\n");
		getch();
		exit(1);
	}
}
  printf("\n\n\tProcess\t|Turnaround Time|Waiting Time\n\n"); 
  printf("\t===========================================\n");
for(i=0;i<n;i++)
{
	m=m+b_time[i];
}
min=m;
time=m;
for(i=0;i<n;i++)
{
	if(a_time[i]<time)
	{
		time=a_time[i];
	}
}
for(i=time;i<=m;i=i+b_time[j])
{
	min=m;
	remain=0;
	flag=0;

	for(count=0;count<n;count++)
	{
	
		if(a_time[count]<=i)
		{

			if(b_time[count]<min)
			{

				min = b_time[count];
				j=count;
				flag=1;
			}
			remain=1;	 
		}
	}
	if(flag==1&&remain==1)
	{
		wait_time=i-a_time[j];
		turn_a_time=wait_time+b_time[j];
		printf("\tP[%d]\t|\t%d\t|\t%d\n",j+1,turn_a_time,wait_time); 
		k=k+wait_time;
		x=x+turn_a_time;
	
		a_time[j]=m+1;
		p[y]=j+1;
		z[y]=i;
		y++;
	}
}
printf("\n\n the Average Waiting Time= %.2f\n",k/n); 
printf("the Avg Turnaround Time = %.2f",x/n); 
printf("\n\n\n the Total time taken by processor to complete all the jobs : %d",m);  
printf("\n\n the Queue  for order of execution:\n");
printf("\n\n    the Process		");

for(i=0;i<n;i++)
{
	printf(" P[%d]   ",p[i]);
	if(i==(n-1))
	{
		printf("End");
	}
	return 0;
}
}
