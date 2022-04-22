#include <stdio.h>
#include <stdlib.h>

int print_file(FILE * f, char end){   // input text of file in terminal
    fseek(f, 0, SEEK_SET);    
    char c = fgetc(f);
    int t = 0;
    printf("%c", c);
    while(c != end){                      // YEAH, BITH. Искорёжил текст немного
        c = fgetc(f);
        printf("%c", c);
        t++; 
    }
    return t;
}


int main(){
    FILE * f;
    f = fopen("str.txt", "r+b");

    int t = 0;
    char W = 'W';
    t = print_file(f, W);
    
    printf("\n temp place t = %d\n", t);
    fseek(f, t, SEEK_SET);  
    int t_W1 = t;
    fprintf(f, "w");
     
    fseek(f, 0, SEEK_SET);
    t = print_file(f, W);
    fseek(f, t, SEEK_SET);
    fprintf(f, "M"); 
    
    fseek(f, t_W1, SEEK_SET);
    fprintf(f, "W");   
    fclose(f);
    return 0;
}	
