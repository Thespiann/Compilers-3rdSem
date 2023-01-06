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

void G();
void M();
void Y();
void Z();


void G() {
  if (input[i] == '(') {
    i++;
    M();
    if (input[i] == ')') {
      i++;
    } else {
      printf("Error: expected ')'\n");
    }
  } else {
    printf("Error: expected '('\n");
  }
}

void M() {
  Y();
  Z();
}

void Y() {
  if (input[i] == 'a') {
    i++;
  } else if (input[i] == 'b') {
    i++;
  } else if (input[i] == '(') {
    G();
  } else {
    printf("Error: expected 'a', 'b', or '('\n");
  }
}

void Z() {
  if (input[i] == '*') {
    i++;
    M();
  } else if (input[i] == '-') {
    i++;
    M();
  } else if (input[i] == '+') {
    i++;
    M();
  } else if (input[i] == '\0') {
    // empty string
  } 
}

int main() {
  printf("Enter an input string: ");
  scanf("%s", input);

  G();

  if (strlen(input) == i) {
    printf("Input is syntactically correct\n");
  } else {
    printf("Error: extra characters at the end of input\n");
  }

  return 0;
}
