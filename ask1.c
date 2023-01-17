#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/* BNF grammar rules
<Z> ::= (<K>)
<K> ::= <G><M>
<G> ::= ν | <Z>
<M> ::= -<K> | +<K> | ε 
*/

// Initialization of char arrays
char str[500] = "";
char str2[500] = "";
char tmp1[2] ="("; //Has to be of size 2 because strcat expects a NULL terminated string	
char tmp2[2] =")";
char tmp3[2] ="v"; 
char tmp4[2] ="+";
char tmp5[2] ="-";

//initialization of methods
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
    printf("%s",str2);
    produceK();
    strcat(str, tmp2);
}

void produceK(){
    printf("\nK-->GM\t");
    printf("%s",str);
    printf("GM)");
    printf("%s",str2);
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
        printf("%s",str2);
        break;
    case 1:
        printf("\nG-->Z\t");
        printf("%s",str);
        printf("ZM)");
        printf("%s",str2);
        strcat(str2,"M)");
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
        printf("%s",str2);
        produceK();
        break;
    case 1:
        //putchar('+');
        printf("\nM-->+K\t");
        strcat(str, tmp4);
        printf("%s",str);
        printf("K)");
        printf("%s",str2);
        produceK();
        break;
    default:
        printf("\nM-->e\t");
        printf("%s",str);
        if(strlen(str2)==0){
            printf(")");}
        else{
        char *str3= str2;
        str3++;//ignoring used the M
        printf("%s",str3);
        str2[strlen(str2)-2]='\0';
        printf("%s",str2);//printing remaining "M)"s
        
        }
        break;
    }
}
