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
    printf("\nZ-->(K)\t");
    strcat(str, tmp1);
    printf("%s",str);
    printf("K)");
    produceK();
    strcat(str, tmp2);
}

void produceK(){
    printf("\nK-->GM\t");
    printf("%s",str);
    printf("GM)");
    produceG();
    produceM();
}

void produceG(){
    switch (rand()%2)
    {
    case 0:
        printf("\nG-->v\t");
        strcat(str, tmp3);
        printf("%s",str);
        printf("M)");
        break;
    case 1:
        printf("\nG-->Z\t");
        printf("%s",str);
        printf("ZM)");
        produceZ();
        break;
    }
}

void produceM(){
    switch (rand()%5) //More Chances to Choose Empty and Finish.
    {
    case 0:
        //putchar('-');
        printf("\nM-->-K\t");
        strcat(str, tmp5);
        printf("%s",str);
        printf("K)");
        produceK();
        break;
    case 1:
        //putchar('+');
        printf("\nM-->+K\t");
        strcat(str, tmp4);
        printf("%s",str);
        printf("K)");
        produceK();
        break;
    default:
        printf("\nM-->e\t");
        break;
    }
}

