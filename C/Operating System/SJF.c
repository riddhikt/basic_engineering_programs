#include<stdio.h>
#include<stdlib.h>

struct s
{
int name;
int at;
int bt; 
int wt;  
int tat;
int rt;
};
typedef struct s node;

node p[10];
  int n;
 

void accept()

{
  int i;
  for(i=0; i<n; i++)
  {
    printf("enter details for process P%d \n",i+1);
    p[i].name = i+1;
    printf("enter arrival time ");
    scanf("%d",&p[i].at);
    printf("enter burst time ");
    scanf("%d",&p[i].bt);
    p[i].rt=p[i].bt;
    p[i].wt = 0;
    p[i].tat = 0;
  }
}


void display()
{
  int i;
  printf("\n\n\n\tPname     at     bt     wt      tat\n");
  for(i=0;i<n;i++)
  {
    printf("\n\tP%d\t%d\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].wt,p[i].tat);
  }
}


void sort()
{
  int i,j;
  node t;
  for(i=0;i<n-1;i++)
   {
      for(j=i+1;j<n;j++)
    {
       if(p[i].at > p[j].at)
          {
        t= p[i];
        p[i] = p[j];
        p[j] = t;
          }
    }
   }
}


void  sjfpremt()
{
   int i,time=0,count,smallest,end,total_wt=0, total_tat=0;
    float avg_wt,avg_tat; 
   p[9].rt = 9999; 
                
   for(time = 0; count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(p[i].at <= time && p[i].rt < p[smallest].rt && p[i].rt > 0)
                  {
                        smallest = i;
                  printf("<--P%d-->%d",p[smallest].name,end);   
                  }
               
            }
           
            p[smallest].rt--;
           
            if(p[smallest].rt == 0)
            {
                 
                  count++;
                  end = time + 1;
                  p[smallest].wt= end - p[smallest].at - p[smallest].bt;
                  p[smallest].tat= end - p[smallest].at;
                  total_wt = total_wt+ p[smallest].wt;
                  total_tat = total_tat + p[smallest].tat;
                
            }
        
      }
      display();
      avg_wt = total_wt/ n;
      avg_tat = total_tat / n;
      printf("\n\nAverage Waiting Time:\t%f\n", avg_wt);
      printf("Average Turnaround Time:\t%f\n", avg_tat);
     

}


int main()
{
 
  printf("enter no of processes\n");
  scanf("%d",&n);


  accept();
  sort();
 

  printf(" \nbefore processing sorted on arrival time\n");
  display();
 
 
   sjfpremt();
 
  return 0;
}


