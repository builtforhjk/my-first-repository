#include <iostream>
#include <cstdio>
using namespace std;
const string base[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
const string high[13] = {"NIL","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
  int getPos(string s, int type){
    if(type){
      for(int i = 0; i < 13; ++i){
      	if(base[i] == s) return i;
      }
    }
    else{
      for(int i = 1; i < 13; ++i){
        if(high[i] == s) return i;
      }
    }
    return -1; 
  }
int main(){
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  cin.get();
  for(int i = 0; i < n; ++i){
    string s; 
    getline(cin,s);
    if(s[0] >= '0' && s[0] <= '9'){
      int val = stoi(s);
      if(val < 13) printf("%s\n",base[val].c_str());
      else{
        printf("%s",high[val/13].c_str());
        if(val%13 != 0) printf(" %s",base[val%13].c_str());
        printf("\n");
      }
    }
    else{
      auto iter = s.find(' ');
      if(s.find(' ') == string::npos){
        int pos = getPos(s, 0);
        if(pos == -1) printf("%d\n",getPos(s, 1));
        else printf("%d\n",pos*13);
      }
      else printf("%d\n",getPos(s.substr(0,3),0)*13+getPos(s.substr(iter+1),1));
    }
  }
  return 0;
}
