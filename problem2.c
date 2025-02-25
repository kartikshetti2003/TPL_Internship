#include <stdio.h>
#include <string.h>

#define max 10  

typedef struct {
    char dest[max][50];  
    int top;
}Stk;

void init(Stk*s){
    s->top=-1;
}

void push(Stk*s,char d[]){
    if(s->top==max-1){
        return;
    }
    s->top++;
    strcpy(s->dest[s->top],d);
}

void disp(Stk*s){
    for(int i=s->top;i>=0;i--){
        printf("%s\n",s->dest[i]);
    }
}

int main(){
    Stk s;
    init(&s);

    int n;
    printf("Enter total destinations: ");
    scanf("%d",&n);

    char d[50];

    for(int i=0;i<n;i++){
        printf("Enter destination: ");
        scanf("%s",d);
        push(&s,d);
    }

    disp(&s);

    return 0;
}

