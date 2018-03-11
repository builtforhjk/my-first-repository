#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
typedef struct Node{
	int val;
	Node * lchild;
	Node * rchild;
	Node(int x):val(x),lchild(NULL),rchild(NULL){}
}Node;
Node * tree = NULL;
bool levelTraversal(){
	bool sign = false;
	bool res = true;
	queue<Node> Qq;
	Qq.push(*tree);
	while(1){
		Node tmp = Qq.front();
		Qq.pop();
		printf("%d",tmp.val);
		if(!tmp.lchild) sign = true;
		else{
			Qq.push(*(tmp.lchild));
			if(sign) res = false;
		}
		if(!tmp.rchild) sign = true;
		else{
			Qq.push(*(tmp.rchild));
			if(sign) res = false;
		}
		if(Qq.empty()){
			printf("\n");
			break;
		}
		else printf(" ");
	}
	return res;
}
int depth(Node * root){
	if(!root) return 0;
	else return max(depth(root->lchild), depth(root->rchild))+1;
}
Node * LL_Rotate(Node * cur){
	Node * tmp = cur->lchild;
	cur->lchild = tmp->rchild;
	tmp->rchild = cur;
	return tmp;
}
Node * RR_Rotate(Node * cur){
	Node * tmp = cur->rchild;
	cur->rchild = tmp->lchild;
	tmp->lchild = cur;
	return tmp;
}
Node * RL_Rotate(Node * cur){
	cur->rchild = LL_Rotate(cur->rchild);
	return RR_Rotate(cur);
}
Node * LR_Rotate(Node * cur){
	cur->lchild = RR_Rotate(cur->lchild);
	return LL_Rotate(cur);
}
void insert(Node ** root, int data){
	if(!(*root)) (*root) = new Node(data);
	else{
		if(data < (*root)->val){
			insert(&(*root)->lchild,data);
			if(depth((*root)->lchild) - depth((*root)->rchild) > 1){
				if(depth((*root)->lchild->lchild) > depth((*root)->lchild->rchild)){
					(*root) = LL_Rotate(*root);
				}
				else (*root) = LR_Rotate(*root);
			}
		}
		else if(data > (*root)->val){
			insert(&(*root)->rchild, data);
			if(depth((*root)->rchild) - depth((*root)->lchild) > 1){
				if(depth((*root)->rchild->lchild) > depth((*root)->rchild->rchild)){
					(*root) = RL_Rotate(*root);
				}
				else (*root) = RR_Rotate(*root);
			}
		}
		else return;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int seq[21];
	for(int i = 0; i < n; ++i){
		scanf("%d",seq+i);
		insert(&tree, seq[i]); 
	}
	printf(levelTraversal()?"YES\n":"NO\n");
	return 0;
}
