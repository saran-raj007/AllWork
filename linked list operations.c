//This code doesn't run, it have  some errors!!!!! 
#include<stdio.h>
#include<stdlib.h>
int num;
 void InsertionAtBigining();
 void InsertionAtEnding();
 void InsetionAtAnyPosition();
 void DeletionAtBegining();
 void DeletionAtEnding();
 void DeletionAtAnyPosition();

struct Node{
    int data;
    struct Node *link;
};
struct Node *head=NULL,*tail=NULL;
 struct Node* newnode(){
    struct Node* nnode=malloc(sizeof(struct Node));
    return nnode;
 }
  void build(int val){
    struct Node* nnode=newnode();
    nnode->data=val;
    nnode->link=NULL;
    if(head==NULL){
        head=nnode;
        tail=nnode;
    }
    else{
        tail->link=nnode;
        tail=nnode;
    }
  }
  void traversing(){
    struct Node* ptr=head->link;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
  }
  void searching(){
    int element,f=0;
    scanf("%d",&element);
    struct Node* ptr=head->link;
    while(ptr!=NULL){
        if(ptr->data==element){
            printf("%d",ptr->data);
            f=1;
        }
    }
    if(f==1){
        printf("\nElememt is found");
    }
    else{
        printf("\nElement is not found");
    }
  }
  void TypeOfInsretion(){
    int choose;
    printf("INSERTION AT BEGINING-1\nINSRTION AT ENDING-2\nINSERTION AT ANYPOSITION-3\n");
    scanf("SELECT Wwhic operation you want to do: %d",&choose);
    if(choose==1){
        InsertionAtBigining();
    }
    else if(choose==2){
        InsertionAtEnding();
    }
    else if(choose==3){
        InsetionAtAnyPosition();
    }
    else{
        printf("\n!!!INVALID!!!");
    }

  }
  void InsertionAtBigining(){
    int element;
    scanf("Enter which element you want to insert: %d\n",&element);
    struct Node* nnode=newnode();
    nnode->data=element;
    nnode->link=NULL;
    head->link=nnode;
    nnode->link=tail;
    printf("AFTER INSERTION:\n");
    struct Node* ptr=head->link;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    num++;

  }
  void InsertionAtEnding(){
    int element;
    scanf("Enter which elemnet you want to insert: %d\n",&element);
    struct Node* nnode=newnode();
    nnode->data=element;
    nnode->link=NULL;
    struct Node* ptr=head->link;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=nnode;
    nnode=NULL;
    printf("After insertion:\n");
    struct Node* ptr1=head->link;
    while(ptr1!=NULL){
        printf("%d ",ptr1->data);
        ptr=ptr->link;
    }
    num++;
  }
  void InsertAtAnyPosition(){
    int position,element,count=0;
    scanf("Enter which position you wnat to insert:%d\n",&position);
    scanf("Enter which element you want to insert: %d\n",&element);
    struct Node* nnode=newnode();
    nnode->data=element;
    nnode->link=NULL;
    struct Node* ptr=head->link,*ptr1=NULL,*ptr2=head->link;
    while(count!=position){
        count++;
        ptr=ptr->link;
    }
    ptr1=ptr->link;
    ptr->link=nnode;
    nnode->link=ptr1;
    printf("AFTER INSERTION:\n");
    while(ptr2!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    num++;
    
 }
 void TypeOfDeletion(){
    int choose;
    printf("DeletionAtBegining-1\nDeletionAtEnd-2\nDeletionAtAnyPosition-3\n");
    scanf("Enter option: %d\n",&choose);
    if(choose==1){
        DeletionAtBegining();
    }
    else if(choose==2){
        DeletionAtEnding();
    }
    else if(choose==3){
        DeletionAtAnyPosition();
    }
    else{
        printf("!!!INVALID!!!");
    }

 }
 void DeletionAtBigining(){
    struct Node* ptr=head->link,*ptr2=NULL;
    ptr2=ptr->link;
    head->link=ptr2;
    printf("AFTER DELETION:\n");
    while(ptr!=NULL){
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
    num--;
}
void DeletionAtEnding(){
    struct Node* ptr=head->link,*ptr1=NULL;
    while(ptr!=NULL){
        ptr1=ptr;
        ptr=ptr->link;
    }
    ptr1->link=NULL;
    printf("AFTER DELETION:\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    num--;
}
void DeletionAtAnyPosition(){
    int count=0,position;
    scanf("ENTER WHICH POSITION YOU WANT TO DELETE: %d\n",&position);
    struct Node* ptr=head->link,*ptr1=NULL,*ptr2=NULL;
    while(count!=position){
        ptr1=ptr;
        ptr=ptr->link;
    }
    ptr2=ptr->link;
    ptr1=ptr2;
    printf("AFTER DELETION:\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    num--;

}
void merging(){
    struct Node* head1=NULL,*tail1=NULL;
    int size;
    scanf("Enter array size: %d\n",&size);
    for(int i=0;i<size;i++){
        scanf("%d ",&size);
        struct Node* nnode=newnode();
        nnode->data=size;
        nnode->link=NULL;
        if(head==NULL){
            head=nnode;
            tail=nnode;
        }
        else{
            tail->link=nnode;
            tail=nnode;
        }

    }
    tail->link=head1;
    struct Node* ptr=head->link;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    num+=size;
}
int Continue(){
	char con;
	printf("\nDo you want to continue (y/n) : ");
    scanf("\n%c",&con);
    if(con=='n'){
        return 0;
    }else{
		return 1;
	}
}
  int main(){
    int v;
    scanf("%d",num);
    for(int i=0;i<num;i++){
        scanf("ENTER FIRST ARRAY SIZE: %d\n",&v);
        build(v);
    }
        do{
        int choise;
        printf("\n\nTraversing - 1\nInsertion - 2\nDeletion - 3\nSearching - 4\nMerging - 5\n\n");
        printf("\nEnter your choise : ");
        scanf("%d",&choise);
        switch(choise){
            case 1:
                traversing();
                break;
            case 2:
                TypeOfInsretion();
                break;
            case 3:
                TypeOfDeletion();
                break;
            case 4:
                searching();
                break;
            case 5:
                merging();
                break;
            default:
                printf("Invalid Choise !!!\n");
                break;
        }
    }while(Continue());
  }
