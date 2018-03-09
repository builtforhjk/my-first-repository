#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef struct Matrix{
  int data[1287][129];
  bool visited[1287][129];
  Matrix(){
    for(int i = 0; i < 1087; ++i){
      for(int j = 0; j < 129; ++j){
        data[i][j] = 0;
        visited[i][j] = false;
      }
    }
  }
}Matrix;
typedef struct Tuple{
  int x;
  int y;
  int z;
  Tuple(int a, int b, int c):x(a),y(b),z(c){}
  Tuple(){}
}Tuple;
vector<Matrix> brain;
void BFS(int m, int n, int l, int t){
  queue<Tuple> Qq;
  int sum = 0, count = 0;
  for(int i = 0; i < l; ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < n; ++k){
        if(!(brain[i].visited[j][k])&&brain[i].data[j][k]){
          Qq.push(Tuple(i,j,k));
          brain[i].visited[j][k] = true;
          while(!Qq.empty()){
            Tuple tmp = Qq.front();
            Qq.pop();
            ++count;
            if(tmp.x > 0 && brain[tmp.x-1].data[tmp.y][tmp.z] && !(brain[tmp.x-1].visited[tmp.y][tmp.z])) {
              Qq.push(Tuple(tmp.x-1, tmp.y, tmp.z));
              brain[tmp.x-1].visited[tmp.y][tmp.z] = true;
            }
            if(tmp.x < l-1 && brain[tmp.x+1].data[tmp.y][tmp.z] && !(brain[tmp.x+1].visited[tmp.y][tmp.z])) {
              Qq.push(Tuple(tmp.x+1, tmp.y, tmp.z));
              brain[tmp.x+1].visited[tmp.y][tmp.z] = true;
            }
            if(tmp.y > 0 && brain[tmp.x].data[tmp.y-1][tmp.z] && !(brain[tmp.x].visited[tmp.y-1][tmp.z])) {
              Qq.push(Tuple(tmp.x, tmp.y-1, tmp.z));
              brain[tmp.x].visited[tmp.y-1][tmp.z] = true;
            }
            if(tmp.y < m-1 && brain[tmp.x].data[tmp.y+1][tmp.z] && !(brain[tmp.x].visited[tmp.y+1][tmp.z])) {
              Qq.push(Tuple(tmp.x, tmp.y+1, tmp.z));
              brain[tmp.x].visited[tmp.y+1][tmp.z] = true;
            }
            if(tmp.z > 0 && brain[tmp.x].data[tmp.y][tmp.z-1] && !(brain[tmp.x].visited[tmp.y][tmp.z-1])) {
              Qq.push(Tuple(tmp.x, tmp.y, tmp.z-1));
              brain[tmp.x].visited[tmp.y][tmp.z-1] = true;
            }
            if(tmp.z < n-1 && brain[tmp.x].data[tmp.y][tmp.z+1] && !(brain[tmp.x].visited[tmp.y][tmp.z+1])) {
              Qq.push(Tuple(tmp.x, tmp.y, tmp.z+1));
              brain[tmp.x].visited[tmp.y][tmp.z+1] = true;
            }
          }
          if(count >= t) sum += count;
          count = 0;
        }
      }
    }
  }
  printf("%d\n",sum);
}
int main(){
  int m,n,l,t;
  scanf("%d%d%d%d",&m,&n,&l,&t);
  for(int i = 0; i < l; ++i){
    Matrix slice;
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < n; ++k)
        scanf("%d",&slice.data[j][k]);
    }
    brain.push_back(slice);
  }
  BFS(m,n,l,t);
  return 0;
}
