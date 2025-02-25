#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

typedef struct{
    char name[50];
    int pri;
}Node;

Node queue[size];
int front=-1;
int rear=-1;

int is_empty(){
    return front==-1;
}

int is_full(){
    return (rear+1)%size==front;
}

void enqueue(char *name,int pri){
    if(is_full()){
        printf("full\n");
        return;
    }
    if(is_full()){
        printf("full\n");
        return;
    }
    if(is_empty()){
        front=rear=0;
    } else {
        rear=(rear+1)%size;
    }
    strcpy(queue[rear].name,name);
    queue[rear].pri=pri;
}

void dequeue(){
    if(is_empty()){
        printf("empty!\n");
        return;
    }
    printf("%s %d\n",queue[front].name,queue[front].pri);
    if(front==rear){
        front=rear=-1;
    } else {
        front=(front+1)%size;
    }
}

int main(){
    int n,pri;
    char name[50];
    printf("Enter total elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter name and priority: \n");
        scanf("%s%d",name,&pri);
        enqueue(name,pri);
    }
    while(!is_empty()){
        dequeue();
    }
    return 0;
}

