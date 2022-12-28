%{
#include <stdio.h>
#include <string.h>

char str1[30];
char str2[30];
int check_unique(char *s) {
    int i, j;
    for (i = 0; i < strlen(s); i++) {
        for (j = i+1; j < strlen(s); j++) {
            if (s[i] == s[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int checklength(char *s){
    char *token;
    token = strtok(s," ");
    strcpy(str1,token);
    token = strtok(NULL, " ");
    strcpy(str2,token);

    if(strcmp(str1,"point")==0){
        if (check_unique(str2)==1){
            printf("Accepted: point\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        } 
    }  
    
    if(strcmp(str1,"line")==0){
        if (check_unique(str2)==1){
            printf("Accepted: line\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        } 
    }  

    if(strcmp(str1,"triangle")==0){
        if (check_unique(str2)==1){
            printf("Accepted: triangle\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        } 
    }
    if(strcmp(str1,"square")==0){
        if (check_unique(str2)==1){
            printf("Accepted: square\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        }
    }
    if(strcmp(str1,"pentagon")==0){
        if (check_unique(str2)==1){
            printf("Accepted: pentagon\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        }
    }
    if(strcmp(str1,"hexagon")==0){
        if (check_unique(str2)==1){
            printf("Accepted: hexagon\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        }
    }
    if(strcmp(str1,"heptagon")==0){
        if (check_unique(str2)==1){
            printf("Accepted: heptagon\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        }
    }
    if(strcmp(str1,"octagon")==0){
        if (check_unique(str2)==1){
            printf("Accepted: octagon\n");
        }
        else {
            printf("Rejected: repeated symbols\n");
        }
    }
    return 0;
}

%}

%%

^[ \t]*point" "[A-Z] { 
    checklength(yytext);
}
^[ \t]*line" "[A-Z]{2} {
    checklength(yytext);
}
^[ \t]*triangle" "[A-Z]{3} {
    checklength(yytext);
}
^[ \t]*square" "[A-Z]{4} {
    checklength(yytext);
}
^[ \t]*pentagon" "[A-Z]{5} {
    checklength(yytext);
}
^[ \t]*hexagon" "[A-Z]{6} {
    checklength(yytext);
}
^[ \t]*heptagon" "[A-Z]{7} {
    checklength(yytext);
}
^[ \t]*octagon" "[A-Z]{8} {
    checklength(yytext);
}
[\t] {return 0;}
.* {printf("Error.\n");}

%%

int yywrap() {return 0;}

int main(int argc, char *argv[]) {
    printf("\n----\n");
    printf("\nFOR FIRST WORD USE: point,line,triangle,square,pentagon,hexagon,heptagon,octagon.\n");
    printf("\nFOR SECOND WORD USE: Any Character Based On First Word.\n");
    printf("\nPress TAB AND ENTER TO TERMINATE.\n");
    printf("\n----\n");
    yylex();
    return 0;
}



  