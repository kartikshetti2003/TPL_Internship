#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[50];
    struct node*left;
    struct node*right;
}node;

node*newnode(char name[]){
    node* temp = (node*)malloc(sizeof(struct node));
    if (!temp) {
        printf("failed\n");
        exit(1);
    }
    strcpy(temp->name,name);
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void in(node*root){
    if(root){
        in(root->left);
        printf("%s\n",root->name);
        in(root->right);
    }
}

void pre(node*root){
    if(root){
        printf("%s\n",root->name);
        pre(root->left);
        pre(root->right);
    }
}

void post(node*root){
    if(root){
        post(root->left);
        post(root->right);
        printf("%s\n",root->name);
    }
}

void freeTree(node*root){
    if(root){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    int n;
    printf("enter total members ");
    scanf("%d",&n);

    node*root=NULL;
    node*nodes[n];
    char name[50],parent[50],pos[10];

    for(int i=0;i<n;i++){
        printf("enter name ");
        scanf("%s",name);
        nodes[i]=newnode(name);

        if(i==0) root=nodes[i];
        else{
            printf("enter name & pos ");
            scanf("%s %s",parent,pos);

            int found=0;
            for(int j=0;j<i;j++){
                if(strcmp(nodes[j]->name,parent)==0){
                    if(strcmp(pos,"left")==0) nodes[j]->left=nodes[i];
                    else nodes[j]->right=nodes[i];
                    found=1;
                    break;
                }
            }
            if(!found){
                printf("wrong parent %s \n",parent);
                free(nodes[i]); 
                i--; 
            }
        }
    }

    printf("inorder:\n");
    in(root);

    printf("preorder:\n");
    pre(root);

    printf("postorder:\n");
    post(root);

    freeTree(root);
    return 0;
}

