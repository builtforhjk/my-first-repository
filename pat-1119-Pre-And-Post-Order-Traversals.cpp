#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef struct Node{
  int val;
  Node * lchild;
  Node * rchild;
  Node(){}
}Node;
int pre[32], post[32], in[32];
void inOrderTraversal(Node * root, int &probe){
  if(root == NULL) return;
  inOrderTraversal(root->lchild, probe);
  in[probe++] = root->val;
  inOrderTraversal(root->rchild, probe);
}
void createTree(Node * & root, int leftL, int leftH, int rightL, int rightH){
  if(leftL > leftH) return;
  root = new Node;
  root->val = pre[leftL];
  root->lchild = NULL;
  root->rchild = NULL;
  if(leftL == leftH) return;
  else{
    int k = leftL+1;
    for(; pre[k]!=post[rightH-1]; ++k);
    createTree(root->lchild, leftL+1, k-1, rightL, rightL+k-leftL-2);
    createTree(root->rchild, k, leftH, rightL+k-leftL-1, rightH-1);
  }
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    scanf("%d",pre+i);
  }
  for(int i = 0; i < n; ++i){
    scanf("%d",post+i);
  }
  bool sign = true;
  for(int i = 1; i < n; ++i){
    int pos = 0;
    for(; post[pos]!=pre[i]; ++pos);
    if(post[pos+1] == pre[i-1]){
      sign = false;
      break;
    }
  }
  printf((sign?"Yes\n":"No\n"));
  Node *root = new Node;
  createTree(root, 0, n-1, 0, n-1);
  int probe = 0;
  inOrderTraversal(root,probe);
  for(int i = 0; i < n; ++i){
    printf("%d",in[i]);
    printf((i+1==n?"\n":" "));
  }
  return 0;
}
