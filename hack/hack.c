#include <stdio.h>
#include <stdlib.h>

int print_file(FILE * f){   // input text of file in terminal
    fseek(f, 0, SEEK_SET);    
    char c = fgetc(f);
    int t = 0;
    printf("%c", c);       // короче в этом тексте надо найти хеллоу ворлд и заменить на сапере 
                            // ауде
    while(!feof(f)){                      
        c = fgetc(f);
        printf("%c", c);
        t++; 
    }
    return t;
}


int main(){
    FILE * f;
    f = fopen("str.txt", "r+b");
    print_file(f);
     
    fclose(f);
    return 0;
}	
