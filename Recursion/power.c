#include<stdio.h>
int exponent(int m, int n);
int main()
{
  int m,n, expo;
  scanf("%d",&m); 
  scanf("%d",&n);
  
  expo=exponent(m,n); 
  printf("%d",expo);

return 0;}

int exponent(int m, int n){
  
  
    if(m==0){
      return 0;
    }
    else if(n==1){
      return m;
    }

    else if(n==0 || m==1){
      return 1;
    }
    else{
      
      return m*exponent(m,n-1);
    }
}

  
