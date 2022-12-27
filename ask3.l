%{
#include <stdio.h>
#include <string.h>

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
%}

%%
point" "[A-Z] { 
    if (check_unique(yytext)) {
        printf("Accepted: point\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
line" "[A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: line\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
triangle" "[A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: triangle\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
square" "[A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: square\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
pentagon" "[A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: pentagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
hexagon" "[A-Z][A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: hexagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
heptagon" "[A-Z][A-Z][A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: heptagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
octagon" "[A-Z][A-Z][A-Z][A-Z][A-Z][A-Z][A-Z][A-Z] {
    if (check_unique(yytext)) {
        printf("Accepted: octagon\n");
    } else {
        printf("Rejected: repeated symbols\n");
    }
}
[A-Z] { printf("Rejected: incorrect definition\n"); return 1; }

%%
int yywrap() {return 0;}

int main(int argc, char *argv[]) {
    yylex();
    return 0;
}



  