#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
int main(){
  int k;
  scanf("%d",&k);
  char input[1005];
  scanf("%s",input);
  string str(input), res;
  map<char, bool> brokenKey;
  bool sureBroken[256] = {false};
  bool visited[256] = {false};
  int cnt = 1;
  char pre = str[0];
  for(auto ch : str.substr(1)){
    if(cnt == k && sureBroken[int(pre)] == false){
      brokenKey[pre] = true;
      cnt = 1;
      pre = ch;
    }
    else if(ch == pre) ++cnt;
    else{
      brokenKey[pre] = false;
      sureBroken[int(pre)] = true;
      cnt = 1;
      pre = ch;
    }
  }
  if(cnt == k && sureBroken[int(pre)] == false) brokenKey[pre] = true;
  else brokenKey[pre] = false;
  bool sign = true;
  for(int i = 0; i < (int)str.size();){
    res += str[i];
    if(brokenKey[str[i]]) {
      if(visited[(int)str[i]] == false){
        printf("%c",str[i]);
        sign = false;
        visited[(int)str[i]] = true;
      }
      i += k;
    }
    else ++i;
  }
  if(sign == false) printf("\n");
  printf("%s\n",res.c_str());
  return 0;
}
