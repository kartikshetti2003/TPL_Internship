#include <stdio.h>
#include <string.h>

#define max 10  

typedef struct {
    char queue[max][50];  
    int front,rear;
}Que;

void init(Que*q){
    q->front=0;
    q->rear=-1;
}

void enqueue(Que*q,char name[]){
    if(q->rear==max-1){
        return;
    }
    q->rear++;
    strcpy(q->queue[q->rear],name);
}

void dequeue(Que*q){
    if(q->front>q->rear){
        return;
    }
    q->front++;
}

void disp(Que*q){
    for(int i=q->front;i<=q->rear;i++){
        printf("%s\n",q->queue[i]);
    }
}

int main(){
    Que q;
    init(&q);

    int n;
    printf("Enter total characters: ");
    scanf("%d",&n);

    char name[50];

    for(int i=0;i<n;i++){
        printf("Enter name: ");
        scanf("%s",name);
        enqueue(&q,name);
    }

    disp(&q);

    return 0;
}

