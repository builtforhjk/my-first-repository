#include <iostream>
#include <cstdio>
using namespace std;
const string standard[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
  char n[128];
  scanf("%s",n);
  string s = n;
  int sum = 0;
  for(int i = 0; i < s.size(); ++i){
    sum += (s[i]-'0');
  }
  string res[10];
  int count = 0;
  if(sum == 0){
    printf("zero\n");
    return 0;
  }
  while(sum){
    res[count++] = standard[sum%10];
    sum = sum/10;
  }
  for(int i = count-1; i >= 0; --i){
    printf("%s",res[i].c_str());
    printf(i==0?"\n":" ");
  }
  return 0;
}
