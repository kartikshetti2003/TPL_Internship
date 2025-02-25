#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node*left;
    struct Node*right;
}Node;

Node*newNode(int val){
    Node*node=(Node*)malloc(sizeof(Node));
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

Node*insert(Node*root,int val){
    if(root==NULL) return newNode(val);
    if(val<root->val) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}

Node*search(Node*root,int val){
    if(root==NULL||root->val==val) return root;
    if(val<root->val) return search(root->left,val);
    return search(root->right,val);
}

void inorder(Node*root){
    if(root){
        inorder(root->left);
        printf("%d\n",root->val);
        inorder(root->right);
    }
}

int main(){
    int n,val,s;
    printf("Enter number: ");
    scanf("%d",&n);

    Node*root=NULL;
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&val);
        root=insert(root,val);
    }

    printf("sorted order:\n");
    inorder(root);

    printf("Enter searching location ");
    scanf("%d",&s);

    if(search(root,s)) printf("found\n");
    else printf("not found\n");

    return 0;
}

