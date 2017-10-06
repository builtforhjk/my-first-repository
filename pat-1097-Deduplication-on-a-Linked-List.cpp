
using namespace std;
typedef struct Node{
  int addr;
  int val;
  int next;
  Node():addr(-1),val(0),next(-1){}
  Node(int a, int v, int nd):addr(a),val(v),next(nd){}
}Node;
int main(){
  int root, n;
  scanf("%d %d",&root, &n);
  unordered_map<int,Node>linklist;
  for(int i = 0; i < n; ++i){
    int address, data, nextAddr;
    scanf("%d %d %d",&address, &data, &nextAddr);
    linklist[address] = Node(address, data, nextAddr);
  }
  int pointer = root, remove_pointer = -1;
  int remove_root = -1;
  int hash_map[10001] = {0};
  hash_map[abs(linklist[root].val)] = 1;
  int cur = linklist[root].next;
  while(cur != -1){
    int tmp = linklist[cur].next;
    if(hash_map[abs(linklist[cur].val)] == 0){
      hash_map[abs(linklist[cur].val)] = 1;
      linklist[cur].next = remove_root;
      linklist[pointer].next = cur;
      pointer = cur;
    }
    else{
      if(remove_pointer == -1){
        remove_root = cur;
        remove_pointer = cur;
        linklist[pointer].next = remove_pointer;
        linklist[remove_pointer].next = -1;
      }
      else{
