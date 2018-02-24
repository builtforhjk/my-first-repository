#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
string lowerCase(string str){
  string tmp = str;
  for(auto &ch : tmp){
    if(ch>='A' && ch<='Z') ch = ch + ('a'-'A');
  }
  return tmp;
}
bool judge(char ch){
  return (ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9');
}
int main(){
  ios::sync_with_stdio(false);
  map<string, int>stat;
  string speech;
  getline(cin,speech);
  int start = 0, end = -1;
  bool terminated = false;
  while(1){
    for(start = end+1;; ++start){
      if(start >= speech.length()){
        terminated = true;
        break;
      }
      else if(judge(speech[start])) break;
    }
    if(terminated) break;
    end = start;
    for(; judge(speech[end]); ++end);
    ++stat[lowerCase(speech.substr(start, end-start))];
  }
  int pivot = 0;
  for(auto &item : stat){
    if(item.second > pivot) pivot = item.second;
  }
  for(auto item : stat){
    if(item.second == pivot) {
      cout<<item.first<<" "<<item.second<<endl;
      break;
    }
  }
  return 0;
}
