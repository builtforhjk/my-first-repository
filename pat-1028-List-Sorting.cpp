#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
typedef struct Node{
  int id;
  char name[9];
  int grade;
}Student;
int type;
bool cmp(Student s1, Student s2){
  if(type == 1) return s1.id < s2.id;
  else if(type == 2) {
    if(strcmp(s1.name, s2.name) == 0) return s1.id < s2.id;
    else return strcmp(s1.name, s2.name) < 0;
  }
  else if(type == 3) {
    if(s1.grade == s2.grade) return s1.id < s2.id;
    else return s1.grade < s2.grade;
  }
}
int main(){
  int n;
  scanf("%d %d",&n,&type);
  Student *st = new Student[n+1];
  for(int i = 0; i < n; ++i){
    scanf("%d", &(st[i].id));
    scanf("%s", st[i].name);
    scanf("%d", &(st[i].grade));
  }
  sort(st,st+n, cmp);
  for(int i = 0; i < n; ++i)
    printf("%06d %s %d\n", st[i].id, st[i].name, st[i].grade);
  return 0;
}
