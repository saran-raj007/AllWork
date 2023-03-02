/*PRIORITY SCHEDULING without Arrival time
author: Saranraj
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int n;
int main(){
     printf("Enter number of process: ");
    scanf("%d",&n);
    int b_tim[n],w_tim[n],prio[n];
    printf("Enter the burst time and priority for each process:\n");
    for(int i=0;i<n;i++){
        printf("P%d: ",i+1);
        scanf("%d %d",&b_tim[i],&prio[i]);
    }
    printf("_________________________________________\n");
    int fp[n];
    int p[n];
    int b[n];
    int index;
    for(int i=0;i<n;i++){
        int min=10000;
        for(int j=0;j<n;j++){
            if(min>prio[j]){
                min=prio[j];
                index=j;
                
            }
        }
        fp[i]=prio[index];
        prio[index]=999999;
        if(i==0){
            p[i]=index+1;
            w_tim[i]=0;
            ta_tim[i]=w_tim[i]+b_tim[index];
            b[i]=b_tim[index];
        }
        else{
            p[i]=index+1;
            ta_tim[i]=ta_tim[i-1]+b_tim[index];
            w_tim[i]=abs(ta_tim[i]-b_tim[index]);
            b[i]=b_tim[index];
            
        }

    }
    printf("Processid  bursttime   Priority Watingtime Turnaroundtime\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t\t%d\t\t\t\t %d\t\t%d\t\t\t\t%d\n",p[i],b[i],fp[i],w_tim[i],ta_tim[i]);
    }
}