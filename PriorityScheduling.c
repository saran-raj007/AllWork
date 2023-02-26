#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
    int n;
    printf("Enter number of process: ");
    scanf("%d",&n);
    int arr_tim[n],b_tim[n],w_tim[n],prio[n],ta_tim[n];
    printf("Enter the arrival time,burst time and priority for each process:\n");
    for(int i=0;i<n;i++){
        printf("P%d: ",i+1);
        scanf("%d %d %d",&arr_tim[i],&b_tim[i],&prio[i]);
    }
    int mp[n];
//     Turn Around time = Exit time – Arrival time
// Waiting time = Turn Around time – Burst time
int a[n],b[n],p[n];
    for(int i=0;i<n;i++){
        if(i==0){
            for(int j=0;j<n;j++){
                if(arr_tim[j]==0){
                    mp[i]=i+1;
                    ta_tim[i]=abs(b_tim[j]-arr_tim[j]);
                    w_tim[i]=0;
                    a[i]=arr_tim[j];
                    b[i]=b_tim[j];
                    p[i]=prio[j];
                    prio[j]=10000;
                }
            }
        }
        else{
            int min=1000000;
            int index;

            for(int j=0;j<n;j++){
                if(min<prio[j]){
                    min=prio[j];
                    index=j;
                    mp[i]=j+1;
                }

            }
            ta_tim[i]=abs(b_tim[index]-arr_tim[index]);
            w_tim[i]=abs(ta_tim[index]-b_tim[index]);
            a[i]=arr_tim[index];
             b[i]=b_tim[index];
             p[i]=prio[index];
            prio[index]=100000;




        }
    }
    for(int i=0;i<n;i++){
        printf("P%d %d %d %d %d %d\n",mp[i],a[i],b[i],p[i],w_tim[i],ta_tim[i]);
    }

}