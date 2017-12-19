#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string.h>
using namespace std;
typedef struct Node{
  string id;
  int Gp;
  int Gm;
  int Gf;
  int G;
  bool sign;
  Node(){
    Gp = 0;
    Gm = 0;
    Gf = 0;
    G = 0;
    sign = false;
  }
}Info;
bool cmp(Info student_1, Info student_2){
  if(student_1.G == student_2.G) return strcmp(student_1.id.c_str(), student_2.id.c_str()) < 0;
  return student_1.G > student_2.G;
}
int val(int a, int b){
  double x = a, y = b;
  double res = x*0.4+y*0.6;
  res = round(res);
  return (int)res;
}
int main(){
  unordered_map<string, Node> buffer;
  int p,m,n;
  scanf("%d%d%d",&p, &m, &n);
  for(int i = 0; i < p; ++i){
    string id;
    int grade;
    cin>>id>>grade;
    buffer[id].id = id;
    buffer[id].Gp = grade;
  }
  for(int i = 0; i < m; ++i){
    string id;
    int grade;
    cin>>id>>grade;
    buffer[id].id = id;
    buffer[id].Gm = grade;
    buffer[id].sign = true;
  }
  for(int i = 0; i < n; ++i){
    string id;
    int grade;
    cin>>id>>grade;
    buffer[id].id = id;
    buffer[id].Gf = grade;
  }
  vector <Info> student;
  for(auto item : buffer){
    item.second.G = (item.second.Gm > item.second.Gf?(val(item.second.Gm, item.second.Gf)):(item.second.Gf));
    student.push_back(item.second);
  }
  sort(student.begin(), student.end(), cmp);
  for(auto item : student){
    if(item.Gp >= 200 && item.G >= 60) cout<<item.id<<" "<<item.Gp<<" "<<(item.sign?item.Gm:-1)<<" "<<item.Gf<<" "<<item.G<<endl;
  }
  return 0;
}
