
#include<stdio.h>
#include<stdlib.h>

int n;
int ispresent(int arr[],int m){
    int f=0;
    for(int i=0;i<n;i++){
        if(arr[i]==n){
            f=1;
        }
    }
    return f;

    }
void Array_traversing(int arr[]){
       for(int i=0;i<n;i++){
            printf("ArrElement:%d",arr[i]);
            printf("\n");
       }

}
void Array_searching(int arr[]){
    int u,f=0;
    //printf("8");
    printf("Enter your key element: ");
    scanf("%d",&u);
    for(int i=0;i<n;i++){
        if(arr[i]==u){
            printf("your key element: %d\n""Index number of key element: %d",arr[i],i) ;
            f=1;
            break;
            //f=1;
        }

    }
    if(f==0){
        printf("key element not found");
    }

}
void Array_Deletion(int arr[]){
    int ch;
    printf("Delete by Position - 1\nDelete by Element -2\n");
    scanf("%d",&ch);
    if(ch==1){
        int pos;
        printf("\nEnter the position : ");
        scanf("%d",&pos);
        for(int i=pos-1;i<n;i++){
            arr[i]=arr[i+1];
        }
    }
    else if(ch==2){
        int element,f=0;
        printf("\nWhich element you wnant to delete : ");
        scanf("%d",&element);
        if(ispresent(arr,element)){
            for(int i=0;i<n;i++){
                if(arr[i]==element){
                f=1;
                }
                if(f==1){
                    arr[i]=arr[i+1];
                }
            }

        }
    }
    else{
        printf("\n**Invalid**");
        return;
    }
    printf("\n");
    n--;
    printf("After deletion: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
}
void Array_merging(int arr[]){
    printf("Enter How many element you want to merge in to the array: ");
    int g;
    scanf("%d",&g);
    int arr2[g];
    int o=n+g;
    printf("Enter which array element you need to add: ");
    for(int i=0;i<g;i++){
        scanf("%d",&arr2[i]);
    }
    for(int i=0,j=n;j<o;i++,j++){
            arr[j]=arr2[i];

    }
    printf("After mearging your array is: ");
    for(int i=0;i<o;i++){
        printf("%d ",arr[i]);
    }
    n=n+g;


}
void Array_insertion(int arr[]){
    printf("insertion beging-1\ninsertion end-2\nInsertion any position-3\n\n\n");
    int r;
    printf("Select your option: ");
    scanf("%d",&r);
    if(r==1){
       int Element;
       printf("Which element you need to insert begnig in a array: ");
       scanf("%d",&Element);
       for(int i=0;i<n+1;i++){
            int t=arr[i];
            arr[i]=Element;
            Element=t;
        }
    }
    else if(r==2){
        int Element;
        printf("Which Element you need to insert end of the array: ");
        scanf("%d",&Element);
        for(int i=0;i<n+1;i++){
            if(i==n){
               arr[i]=Element;
            }
        }
    }
    else if(r==3){
        int Position,Element,t;
        printf("Enter the postion : ");
        scanf("%d",&Position);
        printf("\nEnter the element : ");
        scanf("%d",&Element);
        for(int i=Position-1;i<n+1;i++){
            int t=arr[i];
            arr[i]=Element;
            Element=t;
        }
    }
    printf("After insert: ");
    for(int i=0;i<n+1;i++){
        printf("%d ",arr[i]);
    }
    n++;
}
void Array_sorting(int arr[]){
    int t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    printf("After sorting array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int Continue(){
    char k;
    printf("\n\nDo you want to continue(y/n) : ");
    scanf("\n%c",&k);
 
    if(k=='n'){
        return 0;
        
    }
    else{
        return 1;
    }
}

int main()
{  
   printf("Enter your array size:\n");
   int c;
   scanf("%d",&n);
   int arr[n*2];
   printf("Enter your array element:\n");
   for(int i=0;i<n;i++){
   scanf("%d",&arr[i]);
   }
    do{
        printf("\n");
        printf("Operation list:\n\n");
        printf("Array insertion-1\nArray Deletion-2\nArray searching-3\nArray Traversing-4\nArray merging-5\nArrar sorting-6\n\n\n");
        printf("Ener your choise: ");
        scanf("%d",&c);
        switch(c){
            case 1:
               Array_insertion(arr);
               break;
            case 2:
               Array_Deletion(arr);
               break;
            case 3:
               Array_searching(arr);
               break;
            case 4:
               Array_traversing(arr);
               break;
            case 5:
               Array_merging(arr);
               break;
            case 6:
               Array_sorting(arr);
               break;
            default:
               printf("Invalid Operation");
               break;
        }

    }
    while(Continue());
    printf("!*!*!*!*!*THANK YOU*!*!*!*!*");
       return 0;


}

