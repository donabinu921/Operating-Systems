#include<stdio.h>
int main(){
    int i,init,np,dir,temp,size,totalDisk,req[50];
    printf("Enter the number of process : ");
    scanf("%d",&np);
    printf("Enter the request sequence : ");
    for(i=0;i<np;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter disk size : ");
    scanf("%d",&size);
    size-=1;
    printf("Enter the initial disk position : ");
    scanf("%d",&init);
    printf("Enter direction of head (0 for left to right any other number for right to left) : ");
    scanf("%d",&dir);
    for(i=0;i<np;i++){
        for(int j=0;j<np-i-1;j++){
            if(req[j]>req[j+1]){
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    if(!dir){
        totalDisk=(size-init)+(size-req[0]);
    }
    else{
        totalDisk=(init+req[np-1]);
    }
    printf("The total disk movement : %d\n",totalDisk);
    return 0;
}