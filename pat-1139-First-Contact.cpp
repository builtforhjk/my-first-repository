#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;
typedef struct Node{
  bool gender;
  int id;
  Node(){}
  Node(bool g, int x):gender(g),id(x){}
}Person;
struct PersonCmp{
  bool operator()(const Person& P1, const Person& P2) const{
    if(P1.gender == P2.gender) return P1.id < P2.id;
    else return P1.gender;
  }
};
map<int, set<Person, PersonCmp> >graph;
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; ++i){
    string h,t;
    cin>>h>>t;
    graph[abs(stoi(h))].insert(Person((t[0]!='-'), abs(stoi(t))));
    graph[abs(stoi(t))].insert(Person((h[0]!='-'), abs(stoi(h))));
  }
  int k;
  scanf("%d",&k);
  for(int i = 0; i < k; ++i){
    vector <pair<int,int> >res;
    string sender, receiver;
    cin>>sender>>receiver;
    for(auto friend_1 : graph[abs(stoi(sender))]){
      if(friend_1.gender == (sender[0]!='-')){
        for(auto friend_2 : graph[friend_1.id]){
          if(friend_2.gender == (receiver[0]!='-') 
            && graph[friend_2.id].find(Person((receiver[0]!='-'), abs(stoi(receiver))))!=graph[friend_2.id].end()
            && friend_1.id != abs(stoi(receiver)) && friend_2.id != abs(stoi(sender)))
            res.push_back(pair<int,int>(friend_1.id, friend_2.id));
        }
      }
    }
    printf("%d\n",(int)res.size());
    for(auto v : res){
      printf("%04d %04d\n",v.first, v.second);
    }
  }
  return 0;
}
