#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];
    char house[20];
}Student;

int binarySearch(Student arr[],int n,char key[]){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        int cmp=strcmp(arr[mid].name,key);
        if(cmp==0) return mid;
        else if(cmp<0) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main(){
    int n;
    printf("enter total students: ");
    scanf("%d",&n);

    Student arr[n];
    for(int i=0;i<n;i++){
        printf("enter student name: ");
        scanf("%s",arr[i].name);
        printf("enter house name: ");
        scanf("%s",arr[i].house);
    }

    char key[50];
    printf("enter name to search: ");
    scanf("%s",key);

    int idx=binarySearch(arr,n,key);
    if(idx!=-1) printf("house: %s\n",arr[idx].house);
    else printf("not found\n");

    return 0;
}

