#include <iostream>
#include <cstdio>
using namespace std;
string standard[55] = {"0","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
                      "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
                       "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
                      "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
                      "J1","J2"};
int seq[55];
void repeat(int n){
  string st_co[55];
  int i = 0;
  int sign = 1;
  while(i < n){
    if(sign){
      for(int k = 1; k <= 54; ++k){
        st_co[seq[k]] = standard[k];
      }
      sign = 0;
    }
    else{
      for(int k = 1; k <= 54; ++k){
        standard[seq[k]] = st_co[k];
      }
      sign = 1;
    }
    ++i;
  }
  if(!sign){
    for(int k = 1; k <= 54; ++k){
        standard[k] = st_co[k];
      }
  }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= 54; ++i){
        scanf("%d",seq+i);
    }
    repeat(n);
    for(int i = 1; i <= 54; ++i){
      if(i == 54) printf("%s\n",standard[i].c_str());
      else printf("%s ",standard[i].c_str());
    }
    return 0;
}
