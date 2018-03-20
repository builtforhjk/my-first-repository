#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int d,n;
  scanf("%d%d",&d,&n);
  string str;
  str += char('0'+d);
  while(n != 1){
    char pre = str[0];
    int cnt = 0;
    string res;
    for(auto ch : str){
      if(ch == pre) ++cnt;
      else{
        res += pre;
        res += char('0'+cnt);
        pre = ch;
        cnt = 1;
      }
    }
    res += pre;
    res += char('0'+cnt);
    --n;
    str = res;
  }
  printf("%s\n",str.c_str());
  return 0;
}
