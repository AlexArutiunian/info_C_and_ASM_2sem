#include <stdio.h>
#include <stdlib.h>

int count(char *s2){
    int i = 0;
    switch(s2[0]){
        case 'a': i = 0;
        break;
        case 'b': i = 1;
        break;
        case 'c': i = 2;
        break;
        case 'd': i = 3;
        break;
    }
    return i;
}

void mov(int *p, char *s2, int x){
    int i = count(s2);
    p[i] = x;
    for(int k = 0; k < 4; k++) printf("%d ", p[k]);
    return;
}

void add(int *p, char *s2, int x){
    int i = count(s2);
    p[i] = p[i] + x;
    for(int k = 0; k < 4; k++) printf("%d ", p[k]);
    return;
}

void sub(int *p, char *s2, int x){
    int i = count(s2);
    p[i] = p[i] - x;
    for(int k = 0; k < 4; k++) printf("%d ", p[k]);
    return;
}

int main()
{
    int p[4] = {0, 0, 0, 0};
    char s1[4], s2[4], s3[4];
    int x;
   
    while(1){
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%s", s3);
        if((s3[0] == 'a') || (s3[0] == 'b') || (s3[0] == 'c') || (s3[0] == 'd')){
           x = p[count(s3)]; 
        }
        else x = s3[0] - 48;
       
       
        switch(s1[0]){
            case 'm': mov(p, s2, x);
            break;
            case 'a': add(p, s2, x);
            break;
            case 's': sub(p, s2, x);
            break;
            case 'r': return 0;
            break;
        }
    }
    return 0;
}
