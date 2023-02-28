/*ROUND ROBIN without Arrival time
author: Saranraj
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,q;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter the quantum time: ");
    scanf("%d",&q);
    int b_tim[n];
    int car[n];
    printf("Enter the burst time for each process: \n");
    for(int i=0;i<n;i++){
        printf("P%d: ",i+1);
        scanf("%d",&b_tim[i]);
        car[i]=b_tim[i];
    }
    int t_tim[n];
    int w_tim[n];
    int p=0;
    while(1){
        for(int i=0;i<n;i++){
            if(b_tim[i]>=q){
                b_tim[i]-=q;
                p+=q;
                if(b_tim[i]==0){
                    t_tim[i]=p;
                }
            }
            else if(b_tim[i]!=0&&b_tim[i]<q){
                p+=b_tim[i];
                b_tim[i]=0;
                t_tim[i]=p;


            }
        }
        int s=0;
        for(int i=0;i<n;i++){
            s+=b_tim[i];
        }
        if(s==0){
            break;
        }
    }
    for(int i=0;i<n;i++){
            w_tim[i]=abs(t_tim[i]-car[i]);
    }
    for(int i=0;i<n;i++){
        printf("P%d %d %d %d\n",i+1,car[i],w_tim[i],t_tim[i]);
    }




}