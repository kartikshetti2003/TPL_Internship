#include <stdio.h>
#include <string.h>

typedef struct {
    char nam[50];
    char hou[20];
} Stu;

int binS(Stu arr[], int n, char key[]) {
    int l=0, r=n-1, mid;
    while (l <= r) {
        mid=(l+r)/2;
        int cmp = strcmp(arr[mid].nam, key);
        if (cmp == 0) return mid;
        else if (cmp < 0) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

void sorS(Stu arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(arr[j].nam, arr[j + 1].nam) > 0) {
                Stu temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int n;
    printf("Enter total students: ");
    scanf("%d", &n);

    Stu arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter student name: ");
        scanf("%s", arr[i].nam);
        printf("Enter house name: ");
        scanf("%s", arr[i].hou);
    }

    sorS(arr, n);

    char key[50];
    printf("Enter name to search: ");
    scanf("%s", key);

    int idx = binS(arr, n, key);
    if (idx != -1) 
        printf("House: %s\n", arr[idx].hou);
    else 
        printf("Not found\n");
    return 0;
}
