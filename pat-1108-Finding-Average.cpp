#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
using namespace std;
double isLegal(string s){
  int count = 0;
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == '-') continue;
    else if(s[i] == '.'){
      ++count;
      if(count == 2 || s.size() > (i+3)) return 8888;
    }
    else if(s[i] > '9' || s[i] < '0') return 8888;
  }
  double res;
  sscanf(s.c_str(),"%lf",&res);
  return res;
}
int main(){
  int n;
  scanf("%d",&n);
  double sum = 0.0;
  int count = 0;
  for(int i = 0; i < n; ++i){
    string s;
    cin>>s;
    double val = isLegal(s);
    if(fabs(val) > 1000) printf("ERROR: %s is not a legal number\n",s.c_str());
    else {
      sum += val;
      ++count;
    }
  }
  if(count == 1){
    printf("The average of 1 number is %.2lf\n",sum);
    return 0;
  }
  printf("The average of %d numbers is ",count);
  if(count == 0) printf("Undefined\n");
  else printf("%.2lf\n",sum/count);
  return 0;
}
