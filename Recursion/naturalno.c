#include<stdio.h>
int sum(int n);
int main()
{
  int value,n;
  printf("Enter any no.");
  scanf("%d",&n);
   value=sum(n);
   printf("%d",value);

return 0;}

int sum(int n){
  if(n==0){
    return 0;
  }
  else{
    return sum(n-1)+n;
  }
}