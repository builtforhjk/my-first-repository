#include <iostream>
#include <algorithm>
using namespace std;
bool isPalindrome(string s){
  int size = s.size();
  for(int i=0; i<size/2; ++i){
    if(s[i]!=s[size-i-1]) return false;
  }
  return true;
}
string addStr(string s){
  string res;
  int size = s.size();
  int delta = 0;
  for(int i=0; i<size; ++i){
    int val = (s[i]-'0')+(s[size-i-1]-'0')+delta;
    res.append(1, val%10 + '0');
    delta = val/10;
  }
  if(delta) res.append(1,'1');
  reverse(res.begin(), res.end());
  printf("%s + ", s.c_str());
  for(int i = size; i>0; --i)
    printf("%c", s[i-1]);
  printf(" = %s\n", res.c_str());
  return res;
}
int main(){
  string a;
  cin>>a;
  int sign = 0, i = 0;
  for(; i<10 && !isPalindrome(a); ++i)
    a = addStr(a);
  if(i == 10) printf("Not found in 10 iterations.\n");
  else printf("%s is a palindromic number.\n", a.c_str());
  return 0;
}
