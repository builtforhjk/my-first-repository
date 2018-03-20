#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Node{
  int val;
  Node * lchild;
  Node * rchild;
  Node(){}
  Node(int x):val(x),lchild(NULL),rchild(NULL){}
}Node;
int * inOrder, * preOrder;
void create(Node * &root, int left_in, int right_in, int left_pre, int right_pre){
  if(left_in > right_in) return;
  int pos = left_in;
  for(; inOrder[pos] != preOrder[left_pre]; ++pos);
  root = new Node(preOrder[left_pre]);
  create(root->lchild, left_in, pos-1, left_pre+1, left_pre+pos-left_in);
  create(root->rchild, pos+1, right_in, left_pre+pos-left_in+1, right_pre);
}
bool getPath(Node * root, int data, vector<int>& path){
  if(!root) return false;
  if(root->val == data) {
    path.push_back(root->val);
    return true;
  }
  path.push_back(root->val);
  if(!getPath(root->lchild, data, path)){
    if(!getPath(root->rchild, data, path)){
      path.pop_back();
      return false;
    }
    else return true;
  }
  else return true;
}
int main(){
  int n,m;
  scanf("%d%d",&m,&n);
  inOrder = new int[n+1];
  preOrder = new int[n+1];
  for(int i = 0; i < n; ++i){
    scanf("%d", preOrder+i);
    inOrder[i] = preOrder[i];
  }
  sort(inOrder, inOrder+n);
  Node * tree = NULL;
  create(tree, 0, n-1, 0, n-1);
  for(int i = 0; i < m; ++i){
    int h,t;
    scanf("%d%d",&h,&t);
    bool sign_h = false, sign_t = false;
    for(int i = 0; i < n; ++i){
      if(inOrder[i] > h) break;
      else if(inOrder[i] == h){
        sign_h = true;
        break;
      }
    }
    for(int i = 0; i < n; ++i){
      if(inOrder[i] > t) break;
      else if(inOrder[i] == t){
        sign_t = true;
        break;
      }
    }
    if(!sign_h && ! sign_t){
      printf("ERROR: %d and %d are not found.\n", h,t);
      continue;
    }
    else if(!sign_h){
      printf("ERROR: %d is not found.\n",h);
      continue;
    }
    else if(!sign_t){
      printf("ERROR: %d is not found.\n",t);
      continue;
    }
    vector<int> h_path, t_path;
    getPath(tree, h, h_path);
    getPath(tree, t, t_path);
    int ancestor;
    int cur = 0;
    while(1){
      if(cur == (int)h_path.size()){
        printf("%d is an ancestor of %d.\n", h,t);
        break;
      }
      else if(cur == (int)t_path.size()){
        printf("%d is an ancestor of %d.\n", t,h);
        break;
      }
      else if(h_path[cur] != t_path[cur]){
        printf("LCA of %d and %d is %d.\n", h,t,h_path[cur-1]);
        break;
      }
      else ++cur;
    }
  }
  return 0;
}
