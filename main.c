#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,j,check;
  char val;
  Stack s;
  s.top = NULL;
  s.size = 0;
 
  for(i=1;i<argc;i++){
    check = 1;
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
      if(argv[i][j]=='{' || argv[i][j]=='[' || argv[i][j]=='('){
        push(&s, argv[i][j]);
      }
      else if(argv[i][j]=='}' || argv[i][j]==']' || argv[i][j]==')'){
        if(s.size == 0){
          check = 0;
          break;
        }
        else{
          if(argv[i][j]=='}'){
            val = pop(&s);
            if(val!='{'){
              check = 0;
              break;
            }
          }
          else if(argv[i][j]==']'){
            val = pop(&s);
            if(val!='['){
              check = 0;
              break;
            }
          }
          else if(argv[i][j]==')'){
            val = pop(&s);
            if(val!='('){
              check = 0;
              break;
            }
          }
        }
      }

     }
    if(check && s.size == 0) printf("The parentheses match for %s\n",argv[i]);
    else{
      printf("The parentheses do not match for %s\n",argv[i]);
      pop_all(&s);
    }
  }
   return 0;
}
