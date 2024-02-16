#include <stdio.h>

long long factorial(int n){
  // TODO: Implement iterative solution here
  long long res = 1;
  for(int i = 1;i<=n;i++){
      res = res * i;
  }
  return res;
  
};

long long factorial_rec(int n){
  // TODO: Implement recursive solution here
  if(n==0){
      return 1;
  }
  return n*factorial_rec(n -1);
  return 0;
}

int main(){

  // Both of these should print the same result!
  printf("factorial(10) = %lld\n",factorial(10));
  printf("factorial_rec(10) = %lld\n",factorial_rec(10));


  return 0;
}