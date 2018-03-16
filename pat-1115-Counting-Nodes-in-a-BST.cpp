#include <iostream>
#include <cstdio>
using namespace std;
typedef struct BINode{
  int val;
  BINode * lchild;
  BINode * rchild;
  BINode(){}
  BINode(int x):val(x),lchild(NULL),rchild(NULL){}
}BINode;
int depth(BINode * root){
  if(!root) return 0;
  return max(depth(root->lchild), depth(root->rchild))+1;
}
void levelTraversal(BINode * root, int &n1, int &n2, int height){
  BINode queue[1024];
  int front = 0, back = 0, level = 0, last = 0, cnt = 0;
  if(!root) return;
  queue[back++] = *root;
  while(front != back){
    if(level != 0 &&(level == height-1 || level == height)) ++cnt;
    if(front == last){
      if(level == height-1) n2 = cnt;
      cnt = 0;
      ++level;
      last = back;
    }
    BINode tmp = queue[front++];
    if(tmp.lchild) queue[back++] = *(tmp.lchild);
    if(tmp.rchild) queue[back++] = *(tmp.rchild);
  }
  n1 = cnt+1;
}
void insert(BINode *& tree, int data){
  if(!tree) tree = new BINode(data);
  else if(tree->val >= data) insert(tree->lchild, data);
  else insert(tree->rchild, data);
}
int main(){
  int n;
  scanf("%d",&n);
  BINode * tree = NULL;
  for(int i = 0; i < n; ++i){
    int data;
    scanf("%d",&data);
    insert(tree, data);
  }
  int n1,n2;
  levelTraversal(tree, n1, n2, depth(tree));
  printf("%d + %d = %d\n",n1, n2, n1+n2);
  return 0;
}
