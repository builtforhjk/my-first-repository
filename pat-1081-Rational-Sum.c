#include <stdio.h>
long long gcd(long long x, long long y){
  if(y == 0) return x;
  if(x == 0) return y;
  if(x > y) return gcd(x%y,y);
  else if(x < y) return gcd(x,y%x);
  else return x;
}
long long lcm(long x, long y){
  return x*y/gcd(x,y);
}
int main(){
  int n;
  scanf("%d", &n);
  int i;
  long long numerator[100];
  long long denominator[100];
  for(i = 0; i < n; ++i)
    scanf("%lld/%lld",numerator+i, denominator+i);
  long long n_sum = numerator[0], d_sum = denominator[0];
  for(i = 1; i < n; ++i){
    long long d_tmp = lcm(denominator[i], d_sum);
    long long n_tmp = d_tmp/d_sum*n_sum + d_tmp/denominator[i]*numerator[i];
    d_sum = d_tmp;
    n_sum = n_tmp;
  }
  long long integer = n_sum/d_sum;
  n_sum -= integer*d_sum;
  if(n_sum == 0) {
    printf("%lld\n",integer);
    return 0;
  }
  long long factor = gcd(n_sum, d_sum);
  n_sum /= factor;
  d_sum /= factor;
  if(integer != 0) printf("%lld ", integer);
  if(n_sum != 0) printf("%lld/%lld\n",n_sum,d_sum);
  return 0;
}
