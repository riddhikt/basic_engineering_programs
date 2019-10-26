#include<stdio.h>
#include<stdlib.h>
struct term
{
int at;   
int bt;  
int rt; 
int name;
int wt;    
int tat;  
};
typedef struct term sjterm;
 
void sjfpm(sjterm p[10], int n)
{
   int i,j,min,curr_time,min_index;
       int tot_wt,tot_tat;
          float av_wt,av_tat;
            tot_wt=0;
  tot_tat=0;
   curr_time = p[0].at;
   printf("\n\n           GANT CHART               \n");
   printf("%d",curr_time);
   while(1)
   {
     min = 999;
     min_index= -1;
     i=0;
     while (i<n && p[i].at <= curr_time)   // check wheteher process arrived
     {
     if(  p[i].rt!=0 && p[i].rt < min) // detect minimum remaining time process
       {
          min = p[i].rt;
          min_index=i;
       }
     i++;
    }
    if(i==n && min_index ==-1)break; // done with all processes
    else if(i!=n && min_index ==-1)   // CPU idle
      {
     printf("<-IDLE->");
     curr_time=p[i].at;
      }
   else if(i==n && min_index!=-1) // all process arrived
     {
       j=min_index;
       printf("<--P%d-->",p[j].name);
       curr_time = curr_time + p[j].rt;
       p[j].rt = 0;
       p[j].tat = curr_time - p[j].at;
       p[j].wt = p[j].tat - p[j].bt;
       tot_wt=tot_wt+p[j].wt;
       tot_tat=tot_tat+p[j].tat;
     }
   else // execute the process only for 1 unit of time
     {
    j=min_index;
    printf("<--P%d-->",p[j].name);
    curr_time=curr_time+1;
    p[j].rt=p[j].rt-1;
    if(p[j].rt==0)
      {
        p[j].tat = curr_time - p[j].at;
        p[j].wt = p[j].tat - p[j].bt;
               tot_wt=tot_wt+p[j].wt;
       tot_tat=tot_tat+p[j].tat;
      }
     }
     printf("%d",curr_time);
 
 }// end of outer while
      av_wt=(float)tot_wt/n;
      av_tat=(float)tot_tat/n;
      printf("\n average waiting time is %f\n",av_wt);		//printing average
      printf("\n average turnaround time is %f\n",av_tat);
}
void display(sjterm p[10],int n)
{
  int i;
   float av_wt,av_tat;
    int curr_time,tot_wt,tot_tat;
    tot_wt=0;
  tot_tat=0;
  printf("\n\n\n\tPname     at     bt     wt      tat\n");
  for(i=0;i<n;i++)
  {
    printf("\n\tP%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat);

  }


}
void sort(sjterm process[10],int n)
{
  int i,j;
  sjterm t;
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
void read_data(sjterm process[10],int n)
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
    process[i].rt = process[i].bt;
    process[i].wt = 0;
    process[i].tat = 0;
  }
}
int main()
{
  sjterm process[10];
  int n;
  printf("enter no of process\n");
  scanf("%d",&n);
  read_data(process,n);
  sort(process,n);
  printf("\n before processing sorted on arrival time \n");
  display(process,n);
  sjfpm(process,n);
  printf("\n after processing \n");
  display(process,n);
  return 0;
}


