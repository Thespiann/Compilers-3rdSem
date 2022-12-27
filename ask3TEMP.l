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

    if(strcmp(str1,"point")==0 && check_unique(str2)==1 && strlen(str2)==1){
        printf("Accepted: point\n");
    }
    else {
        printf("Rejected: repeated symbols\n");
    }
    
    if(strcmp(str1,"line")==0){
        if (check_unique(str2)) {
            printf("Accepted: line\n");
        }else {
            printf("Rejected: repeated symbols\n");
        }
    }

    if(strcmp(str1,"triangle")==0){
        
    }
    if(strcmp(str1,"square")==0){
        
    }
    if(strcmp(str1,"pentagon")==0){
        
    }
    if(strcmp(str1,"hexagon")==0){
        
    }
    if(strcmp(str1,"heptagon")==0){
        
    }
    if(strcmp(str1,"octagon")==0){
        
    }
    
}

%}

%%
point" "[A-Z] { 
    checklength(yytext);
    
    
}
line" "[A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: line\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
    checklength(yytext);
}
triangle" "[A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: triangle\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
    checklength(yytext);
}
square" "[A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: square\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
    checklength(yytext);
}
pentagon" "[A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: pentagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
    checklength(yytext);
}
hexagon" "[A-Z][A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: hexagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
    checklength(yytext);
}
heptagon" "[A-Z][A-Z][A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: heptagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
    checklength(yytext);
}
octagon" "[A-Z][A-Z][A-Z][A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: octagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
    checklength(yytext);
}
. {printf("Wrong Input Given: %s",yytext); return 1; }
   
%%

int yywrap() {return 0;}

int main(int argc, char *argv[]) {
    yylex();
    return 0;
}



  