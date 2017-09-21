#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct Node{
	int data;
	struct Node * leftChildNode;
	struct Node * rightChildNode;
}Node;

Node * createNode(int data){
	Node * pNode = new Node;
	pNode->data = data;
	pNode->leftChildNode = NULL;
	pNode->rightChildNode = NULL;
	return pNode;
}

int getCommandInfo(string command){
	if(command.compare("Pop") == 0){
		return 0;
	}
	else{
		int spacePos = command.find_first_of(" ");
		return stoi(command.substr(spacePos+1));
	}
}
void insert(Node * & currentNode, vector <string> command, int  & index){
	if(index >= command.size()){
		return;
	}
	int data = getCommandInfo(command[index]);
	if(!data){
		return;
	}
	if(currentNode == NULL){
		currentNode = createNode(data);
	}
	++index;
	insert(currentNode->leftChildNode, command, index);
	++index;
	insert(currentNode->rightChildNode, command, index);
}
void postorderTraversal(Node * & currentNode, vector <int> & data){
	if(currentNode == NULL){
		return;
	}
	postorderTraversal(currentNode->leftChildNode, data);
	postorderTraversal(currentNode->rightChildNode,data);
	data.push_back(currentNode->data);
}
int main(){
	int number = 0;
	cin>>number;
	int i = 0;
	bool banned = true;
	vector <string> command;
	while(i < (2 * number)){
		string input;
		getline(cin,input);
		if(banned){
			banned = false;
			continue;
		}
		++i;
		command.push_back(input);
	}
	Node * root = NULL;
	int start = 0;
	insert(root, command, start);
	vector <int> postorder;
	postorderTraversal(root, postorder);
	string result;
	for(i = 0; i < postorder.size(); ++i){
		cout<<postorder[i];
		if(i != postorder.size() - 1){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}
	return 0;
}