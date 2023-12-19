#include <stdio.h>
#define s 50

int main()
{
 int n,i,bt[s],wt[s],tat[s],temp,at[s],st[s];
 float twt,ttat;
 printf("Enter the no of procesess:");
 scanf("%d",&n);
 printf("Enter the arival time and burst time:\n");
 for(i=0;i<n;i++)
 {
   printf("Arrival time:");
   scanf("%d",&at[i]);
   printf("Burst time:");
   scanf("%d",&bt[i]);
 }
 for(i=0;i<n;i++)
 {
   if(bt[i+1]<bt[i])
   {
     temp=bt[i];
     bt[i]=bt[i+1];
     bt[i+1] = temp;
   }
  }
 wt[0]=0;
 st[0]=0;
 tat[0]=bt[0];
 ttat += tat[0];
 for(i=1;i<n;i++)
 {
  st[i] = st[i-1]+bt[i-1];
  wt[i]=st[i]-at[i];
  tat[i] = wt[i]+bt[i];
  twt+=wt[i];
  ttat+=tat[i];
 }
 printf("The Average waiting time = %f",twt/n);
 printf("\nThe Average Turn around time = %f",ttat/n);
return 0;
} 