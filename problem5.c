#include <stdio.h>

typedef struct{
    char name[50];
    char loc[50];
    int amt;
}Record;

void disp(Record rec[],int n){
    for(int i=0;i<n;i++){
        printf("%s %s %d\n",rec[i].name,rec[i].loc,rec[i].amt);
    }
}

int main(){
    int n;
    printf("Enter total records: ");
    scanf("%d",&n);

    Record rec[n];

    for(int i=0;i<n;i++){
        
        printf("enter name: ");
        scanf("%s",rec[i].name);
        printf("enter location: ");
        scanf("%s",rec[i].loc);
        printf("enter amount: ");
        scanf("%d",&rec[i].amt);
   
    }

    disp(rec,n);

    return 0;
}

