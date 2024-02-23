#include<stdio.h>

void push(int n);
void pop();
int main()
{
  int size,top=-1;
  printf("enter the size of the static stack: ");
  scanf("%d",&size);
  int stack[size],choice;
  int n;
  menu:
  printf("\n Choose the operation you want to perform : \n");
  printf("1)Push 2)Pop 3)Traverse 4)Exit\n");
  scanf("%d",&choice);

  switch(choice){
    case 1: ;
    if(top>size){
      printf("Stack overflow");
      goto menu;
    }
    
    printf("Enter the element to push: ");
    scanf("%d",&n);
      top++;
      stack[top]=n;
      goto menu;
      break;

    case 2: if(top==-1){
      printf("Stack underflow");
      goto menu;
      break;
    }
    else{
      top--;
      goto menu;
      break;
    }

    case 3: if(top==-1){
      printf("No elements present in stack!");
      goto menu;
      break;
    }
    else{
        for(int i=0;i<=top;i++){
          printf("%d ",stack[i]);
    }
    goto menu;
    break;
    }
    
    

    case 4: printf("Good Byee!!");
    break;

    default: printf("Invalid choice!");
    goto menu;
  }


  

return 0;}