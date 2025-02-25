#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char sub[50];
    struct node*next;
}node;

node*top=NULL;

void push(char sub[]){
    node*newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->sub,sub);
    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top==NULL)
    return;
    node*temp=top;
    top=top->next;
    free(temp);
}

void disp(){
    node*temp=top;
    while(temp!=NULL){
        printf("%s\n",temp->sub);
        temp=temp->next;
    }
}

int main(){
    int n;
    printf("Enter total number ");
    scanf("%d",&n);

    char sub[50];

    for(int i=0;i<n;i++){
        printf("Enter sub: ");
        scanf("%s",sub);
        push(sub);
    }
    disp();
    return 0;
}

