#include <iostream>
#include <cstdio>
using namespace std;
const string dict[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
  char s1[61],s2[61],s3[61],s4[61];
  scanf("%s %s %s %s",s1,s2,s3,s4);
  int i = 0;
  int count = 0;
  while(count < 2){
    if(!count&&s1[i]>='A'&&s1[i]<='G'&&s1[i]==s2[i]) printf("%s ",dict[s1[i]-'A'].c_str());
    else if(count==1&&((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9'))&&s1[i]==s2[i]){
      if(s1[i]<='9') printf("%02d:", s1[i]-'0');
      else printf("%d:",s1[i]-'A'+10);
    }
    else {
      ++i;
      continue;
    }
    ++i;
    ++count;
  }
  i = 0;
  while(1){
    if(((s3[i]>='A'&&s3[i]<='N')||(s3[i]>='a'&&s3[i]<='z'))&&s3[i]==s4[i]){
      printf("%02d\n",i);
      break;
    }
    ++i;
  }
  return 0;
}
