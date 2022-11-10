//INFIX TO POSTFIX BY SARAN!!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char infix[10000],postfix[100000],stack[10000];
int top=-1;
int top1=-1;
int instack(char g){
        switch(g){
            case '+':
            return 2;
            break;
            case '-' :
            return 2;
            break;
            case '*':
            return 4;
            break;
            case '/':
            return 4;
            break;
            case '^':
            return 5;
            break;
            case '(':
            return 0;
            break;
            case ')':
            return 0;
            break;
        }
    
}
int income(char p){
        switch(p){
            case '+':
            return 1;
            break;
            case '-' :
            return 1;
            break;
            case '*':
            return 3;
            break;
            case '/':
            return 3;
            break;
            case '^':
            return 6;
            break;
            case '(':
            return 9;
            break;
            case ')':
            return 0;
            break;
        }
    
}
void pop2(){
    while(top>=0 && stack[top]!='('){
        postfix[++top1]=stack[top--];
    }
}
void push(char d){
    
        stack[++top]=d;

}
void pop1(){
    
    while(stack[top]!='('){
        postfix[++top1]=stack[top--];
    }
    stack[top]='\0';
    top--;
    
    
}
void pop(char e){
    postfix[++top1]=stack[top--];
    stack[++top]=e;
}
void Convertpostfix(char a){
    if((a>=65 && a<=90)||(a>=97 && a<=122)){
        postfix[++top1]=a;
        
    }
    else if(a=='('){
        push(a);
    }
    else if(a==')'){
        pop1();
    }
    else if(top<0){
        stack[++top]=a;
    }
    else if(top<0){
        push(a);
    }
    else if(instack(stack[top])<income(a)){
        //printf("%c",stcak[top]);
        push(a);

    }
    else{
        pop(a);
        
    }
}


int main(){
    printf("ENTER YOUR INFIX EXPRESSION: ");
    scanf("%s",infix);
    for(int i=0;i<strlen(infix);i++){
        Convertpostfix(infix[i]);
    }
    if(top>=0){
        pop2();
    }
    printf("POSTFIX EXPRESSION: ");
    printf("%s",postfix);
    
}