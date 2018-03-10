#include <iostream>
#include <cstdio>
using namespace std;
void multiple(string origin, string & dest){
  int delta = 0;
  for(auto itor = origin.rbegin(); itor != origin.rend(); ++itor){
    int val = ((*itor)-'0')*2+delta;
    delta = val/10;
    dest += (val%10)+'0';
  }
  if(delta > 0) dest += '1';
  dest = string(dest.rbegin(), dest.rend());
}
bool judge(string origin, string strCmp){
  if(origin.size() != strCmp.size()) return false;
  int hash[10] = {0};
  for(auto ch : origin){
    ++hash[ch-'0'];
  }
  for(auto ch : strCmp){
    --hash[ch-'0'];
  }
  for(int i = 0; i < 10; ++i){
    if(hash[i]) return false;
  }
  return true;
}
int main(){
  string origin,dest;
  cin>>origin;
  multiple(origin, dest);
  printf(judge(origin, dest)?"Yes\n":"No\n");
  printf("%s\n",dest.c_str());
  return 0;
}
