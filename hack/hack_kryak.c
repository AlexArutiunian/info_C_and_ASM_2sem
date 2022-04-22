#include <stdio.h>
#include <stdlib.h>

int prin(FILE *f, int cur){        // печатает тестовый файл до определенного (cur) символа
    fseek(f, 0, SEEK_SET);
    for(int i = 0; i < cur; i++){
        char c = fgetc(f);
        printf("%c", c);
    }
    return 0;
        
}

int t = 0;

int search(FILE *f, int cur, char hello[]){   // находит положение курсора на котором начинается нужное слово
    fseek(f, cur, SEEK_SET);                  // в нашей задаче достаточно определить положения первых двух букв фразы
    char c = fgetc(f);
    if(c != hello[0]){
        t++;
        search(f, t, hello);
    }
    else if(c = fgetc(f) != hello[1]){
        t++;
        search(f, t, hello);
    }
    else return t;
}


int main(){
    FILE * f;
    f = fopen("str.txt", "r+");
    char hello[11] = "Hello World";
    int cur = search(f, 0, hello);
    //prin(f, cur);
    
    fseek(f, cur, SEEK_SET);
    fprintf(f, "Supere Aude");           // записываем новую фразу в файл в то место, где определили, что расположено заменяемое слово
    
    fclose(f);
    return 0;
}	
