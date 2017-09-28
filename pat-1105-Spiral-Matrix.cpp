#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <cstring>
using namespace std;
bool cmp(int x, int y){
  return x > y;
}
int main(){
  int n;
  scanf("%d",&n);
  int *src = new int[n];
  memset(src,0,sizeof(int)*n);
  for(int i = 0; i < n; ++i){
    scanf("%d",src+i);
  }
  sort(src,src+n,cmp);
  int rows = ceil(sqrt(n)),cols;
  while(n%rows != 0) ++rows;
  cols = n/rows;
  int *res = new int[n];
  //矩阵赋值
  int nextPos = 0, direct = 1;
  int count = 0, cur = 0;
  int r = rows, c = cols;
  while(1){
    if(direct == 1 && cur == c){
      direct = 2;
      cur = 0;
      nextPos = nextPos-1+cols;
      --r;
    }
    else if(direct == 1){
      ++cur;
      res[nextPos] = src[count++];
      ++nextPos;
    }
    if(count == n) break;
    if(direct == 2 && cur == r){
      direct = 3;
      cur = 0;
      nextPos = nextPos-1-cols;
      --c;
    }
    else if(direct == 2){
      ++cur;
      res[nextPos] = src[count++];
      nextPos += cols;
    }
    if(count == n) break;
    if(direct == 3 && cur == c){
      direct = 4;
      cur = 0;
      nextPos = nextPos+1-cols;
      --r;
    }
    else if(direct == 3){
      ++cur;
      res[nextPos] = src[count++];
      --nextPos;
    }
    if(count == n) break;
    if(direct == 4 && cur == r){
      direct = 1;
      cur = 0;
      nextPos = nextPos+1+cols;
      --c;
    }
    else if(direct == 4){
      ++cur;
      res[nextPos] = src[count++];
      nextPos -= cols;
    }
    if(count == n) break;
  }
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      printf("%d",res[i*cols+j]);
      if(j+1 == cols) printf("\n");
      else printf(" ");
    }
  }
  return 0;
}
