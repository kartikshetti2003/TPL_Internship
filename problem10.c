#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 5

typedef struct{
    int is_occ;
    char ent_type;
    int ent_id;
}Cell;

Cell grid[ROWS][COLS];

void initGrid(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            grid[i][j].is_occ=0;
            grid[i][j].ent_type=' ';
            grid[i][j].ent_id=-1;
        }
    }
}

void placeEntity(int x,int y,char type,int id){
    if(x<0||x>=ROWS||y<0||y>=COLS||grid[x][y].is_occ){
        printf("wrong pos\n");
        return;
    }
    grid[x][y].is_occ=1;
    grid[x][y].ent_type=type;
    grid[x][y].ent_id=id;
}

void moveEntity(int x,int y,int newX,int newY){
    if(x<0||x>=ROWS||y<0||y>=COLS||!grid[x][y].is_occ||newX<0||newX>=ROWS||newY<0||newY>=COLS||grid[newX][newY].is_occ){
        printf("wrong move\n");
        return;
    }
    grid[newX][newY]=grid[x][y];
    grid[x][y].is_occ=0;
    grid[x][y].ent_type='-';
    grid[x][y].ent_id=-1;
}

void findClosestEntity(int x,int y,char type){
    int minDist=ROWS*COLS,tx=-1,ty=-1;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(grid[i][j].is_occ&&grid[i][j].ent_type==type){
                int dist=abs(x-i)+abs(y-j);
                if(dist<minDist){
                    minDist=dist;
                    tx=i;
                    ty=j;
                }
            }
        }
    }
    if(tx!=-1) printf("closest %c found (%d,%d)\n",type,tx,ty);
    else printf("not found %c \n",type);
}

void displayGrid(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(grid[i][j].is_occ) printf("[%c%d]",grid[i][j].ent_type,grid[i][j].ent_id);
            else printf("[  ]");
        }
        printf("\n");
    }
}

int main(){
    initGrid();
    int n;
    printf("enter total entities: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int x,y,id;
        char type;
        printf("enter x y type id: ");
        scanf("%d%d %c%d",&x,&y,&type,&id);
        placeEntity(x,y,type,id);
    }

    displayGrid();

    int x,y,newX,newY;
    printf("enter current cood: ");
    scanf("%d%d",&x,&y);
    printf("enter new coord: ");
    scanf("%d%d",&newX,&newY);
    moveEntity(x,y,newX,newY);

    displayGrid();

    char type;
    printf("enter type to find: ");
    scanf(" %c",&type);
    findClosestEntity(newX,newY,type);

    return 0;
}

