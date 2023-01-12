/*
G→ (M)
M→ ΥΖ
Υ→ a | b | G
Ζ→ *M | -M | +M| ε
*/

#include <stdio.h>
#include <string.h>

char input[100];
int i = 0;

int G();
int M();
int Y();
int Z();


int G() {   
    printf("\n              G\n       |      |      |              \n");
    printf("\n       (      M      )\n              |\n");
    if (input[i] == '(') {
        i++;
        M();
        if (input[i] == ')') {
            i++;
        } else {
            printf("\nError: expected ')'\n");
            return 1;
        }
    } else {
        printf("\nError: expected '('\n");
        return 1;
    }
    return 0;
}

int M() {
    if (Y()==0){
        if (Z()==0){
            return 0;
        }else {
            return 1;
        }
    }else {
        return 1;
    }
    return 0;
}

int Y() {
    printf("              Y\n              |\n");
    if (input[i] == 'a') {
        printf("              a\n              |\n");
        i++;
    } else if (input[i] == 'b') {
        printf("              b\n              |\n");
        i++;
    } else if (input[i] == '(') {
        G();
    } else {
        printf("\nError: expected 'a', 'b', or '('\n");
        return 1;
    }
    return 0;
}

int Z() {
    printf("              Z\n              |\n");
    if (input[i] == '*') {
        printf("              *\n              |\n");
        printf("              M\n              |\n");
        i++;
        M();
    } else if (input[i] == '-') {
        printf("              -\n              |\n");
        printf("              M\n              |\n");
        i++;
        M();
    } else if (input[i] == '+') {
        printf("              +\n              |\n");
        printf("              M\n              |\n");
        i++;
        M();
    }else{
        printf("              ε\n              |\n");
    }
    return 0;
}

int main() {

     printf("\nEnter an input string: ");
    scanf("%s", input);


    if(G()!=1){
        if (strlen(input) == i) {
            printf("\nInput is syntactically correct\n");
        } else {
            printf("\nError: extra characters\n");
        }
    }

    

    return 0;
}
