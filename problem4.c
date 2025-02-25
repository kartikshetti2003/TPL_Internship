#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[50];
    struct node*next;
}node;

node*head=NULL;

void add(char name[]){
    node*newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->name,name);
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
    }
    else{
        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void disp(){
    node*temp=head;
    while(temp!=NULL){
        printf("%s\n",temp->name);
        temp=temp->next;
    }
}

int main(){
    int n;
    printf("Enter total members: ");
    scanf("%d",&n);

    char name[50];

    for(int i=0;i<n;i++){
        printf("Enter name: ");
        scanf("%s",name);
        add(name);
    }

    disp();

    return 0;
}

