#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int *child;
	int size;
}Node;
void Node_init(Node*t){
	t->child = (int *)malloc(sizeof(int)*110);
	t->size = 0;
}
Node tree[102];
int leaf[102]={0};
void countLeaves(int root, int level, int *sum){
	if(tree[root].size == 0){
		++leaf[level];
		if(level > *(sum)) (*sum) = level;
		return;
	}
	int i;
	for(i = 0; i < tree[root].size; ++i)
		countLeaves(tree[root].child[i], level+1,sum);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i;
	for(i = 1; i <= n; ++i)
		Node_init(&tree[i]);
	for(i = 0; i < m; ++i){
		int father;
		scanf("%d",&father);
		scanf("%d",&tree[father].size);
		int j;
		for(j = 0; j < tree[father].size; ++j)
			scanf("%d",tree[father].child+j);
	}
	int level = 0;
	countLeaves(01, 1, &level);
	for(i = 1; i <= level; ++i){
		printf("%d", leaf[i]);
		printf((i == level)?"\n":" ");
	}
	return 0;
}
