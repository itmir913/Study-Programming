// Created on iPad Pro.

#include <stdio.h>

long long int sum_from_1_to_n(long long int n){
   return (n*(n+1))/2;
}

int main() {
   setbuf(stdout, NULL);

   long long int x;
   scanf("%lld", &x);

   long long int n=1;
   while (sum_from_1_to_n(n) < x){
      n++;
   }

   long long int min = sum_from_1_to_n(n-1) + 1;
   long long int max = sum_from_1_to_n(n);

   if (n % 2 == 0){
       long long int diff = max - x;
       printf("%lld/%lld", n-diff, 1+diff);
   } else {
       long long int diff = x - min;
       printf("%lld/%lld\n", n-diff, 1+diff);
   }
   return 0;
}