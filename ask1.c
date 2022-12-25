#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
<Z> ::= (<K>)
<K> ::= <G><M>
<G> ::= ν | <Z>
<M> ::= -<K> | +<K> | ε 
*/

char str[500] = "";
char tmp1[2] ="("; //Has to be of size 2 because strcat expects a NULL terminated string	
char tmp2[2] =")";
char tmp3[2] ="v"; 
char tmp4[2] ="+";
char tmp5[2] ="-";

void produceZ();
void produceK();
void produceG();
void produceM();

int main(){
    time_t t;
    srand((unsigned) time(&t));
    printf("\nZ");
    produceZ();
    printf("\n-------- \n\n%s\n\n",str);  //Print the Completed String.
    return 0;
}


void produceZ(){
    //putchar('(');
    printf("\nZ-->(K)");
    strcat(str, tmp1);
    produceK();
    //putchar(')');
    strcat(str, tmp2);
}

void produceK(){
    printf("\nK-->GM");
    produceG();
    produceM();
}

void produceG(){
    switch (rand()%2)
    {
    case 0:
        //putchar('v');
        printf("\nG-->v");
        strcat(str, tmp3);
        break;
    case 1:
        printf("\nG-->Z");
        produceZ();
        break;
    }
}

void produceM(){
    switch (rand()%5) //More Chances to Choose Empty and Finish.
    {
    case 0:
        //putchar('-');
        printf("\nM-->-K");
        strcat(str, tmp5);
        produceK();
        break;
    case 1:
        //putchar('+');
        printf("\nM-->+K");
        strcat(str, tmp4);
        produceK();
        break;
    default:
        printf("\nM-->e");
        break;
    }
}

