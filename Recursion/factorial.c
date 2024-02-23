#include<stdio.h>
int factorial(int n);
int main()
{
  int n, fact; 
  printf("Enter any number: ");
  scanf("%d",&n);
  fact=factorial(n);
  printf("%d",fact);

return 0;}

int factorial(int n){
  if(n==0){
    return 1;
  }
  else{
    return factorial(n-1)*n;
  }
}