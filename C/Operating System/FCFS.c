#include<stdio.h>		//header files
#include<stdlib.h>
struct s			//node structure
{
	int at; 
	int bt; 
	int name;  
	int wt;   
	int tat;  

};
typedef struct s node;
 
void display(node p[10],int n)		//display function
{
  int i;
 
  printf("\n\n\n\tPname   at     bt      wt      tat\n");
  for(i=0;i<n;i++)
  {
    printf("\n\tP%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat);
 
  }
 
}
void fcfs(node p[10], int n)		//function for fcfs

{
   int i,curr_time,tot_wt,tot_tat;
   float av_wt,av_tat;
  tot_wt=0;
  tot_tat=0;
   curr_time = p[0].at;
   printf(" \n\n          GANTT CHART              \n\n\n");
   printf("%d\n",curr_time);
   
   for(i=0;i<n;i++)		//for printing gantt chart
     {
    printf("|--P%d--|",p[i].name);
    curr_time = curr_time + p[i].bt;
    p[i].tat = curr_time - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;
    tot_wt=tot_wt+p[i].wt;
    tot_tat=tot_tat+p[i].tat;
    
    printf("%d",curr_time);
    if(i<n-1 && curr_time < p[i+1].at)
        {
           printf("|-IDLE-|");
           curr_time=p[i+1].at;
           printf("%d",curr_time);
        }
     
     }
      
      display(p,n);
      av_wt=(float)tot_wt/n;
      av_tat=(float)tot_tat/n;
      printf("\n average waiting time is %f\n",av_wt);		//printing average
      printf("\n average turnaround time is %f\n",av_tat);
}
 
 
 
void sort(node process[10],int n)		//sorting function
{
  int i,j;
  node t;
  for(i=0;i<n-1;i++)
   {
      for(j=i+1;j<n;j++)
    {
       if(process[i].at > process[j].at)
          {
        t= process[i];
        process[i] = process[j];
        process[j] = t;
          }
    }
   }
}
void read_data(node process[10],int n)		//function for accepting processes
{
  int i;
  for(i=0; i<n; i++)
  {
    printf("enter details for process P%d \n",i+1);
    process[i].name = i+1;
    printf("enter arrival time ");
    scanf("%d",&process[i].at);
    printf("enter burst time ");
    scanf("%d",&process[i].bt);
    process[i].wt = 0;
    process[i].tat = 0;
  }
}
int main()
{
  node process[10]; 
  int n;
 
  printf("enter no of processes\n");
  scanf("%d",&n);
  read_data(process,n);
  sort(process,n);
 
  
  fcfs(process,n);
  
  return 0;
}


