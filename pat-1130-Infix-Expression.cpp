#include <iostream>
#include <cstdio>
using namespace std;
typedef struct Node{
  string data;
  int lchild;
  int rchild;
  Node(){}
  Node(string x, int l, int y):data(x),lchild(l),rchild(y){}
}Node;
Node tree[21];
int origin;
string res;
void inOrder(int root){
  if(root == -1) return;
  if(tree[root].rchild != -1 && root != origin) res += "(";
  inOrder(tree[root].lchild);
  res += tree[root].data;
  inOrder(tree[root].rchild);
  if(tree[root].rchild != -1 && root != origin) res += ")";
}
int main(){
  int n;
  scanf("%d",&n);
  int root = 1;
  int notRoot[21] = {0};
  for(int i = 1; i <= n; ++i){
    char tmp[11];
    scanf("%s",tmp);
    tree[i].data = tmp;
    scanf("%d%d",&tree[i].lchild, &tree[i].rchild);
    notRoot[(tree[i].lchild==-1?0:tree[i].lchild)] = 1;
    notRoot[(tree[i].rchild==-1?0:tree[i].rchild)] = 1;
  }
  while(notRoot[root]) ++root;
  origin = root;
  inOrder(root);
  printf("%s\n",res.c_str());
  return 0;
}
