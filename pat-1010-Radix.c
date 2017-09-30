#include <stdio.h>
#include <math.h>
#include <string.h>
long long convert(char * str, int strSize, long long R){
  long long res = 0;
  int i = 0;
  while(i < strSize){
    int val = (str[strSize-i-1]<='9'?(str[strSize-i-1]-'0'):(str[strSize-i-1]-'a'+10));
    if(val >= R) return -1;
    res += pow(R,i)*val;
    ++i;
  }
  return res;
}
int main(){
  char digit[2][11];
  scanf("%s %s",digit[0],digit[1]);
  int len[2];
  len[0] = (int)strlen(digit[0]);
  len[1] = (int)strlen(digit[1]);
  int tag;
  long long R;
  scanf("%d %lld",&tag, &R);
  long long number[2];
  number[tag-1] = convert(digit[tag-1],len[tag-1],R);
  int val = digit[2-tag][0]<='9'?(digit[2-tag][0]-'0'):(digit[2-tag][0]-'a'+10);
  if(len[2-tag] == 1) {
    if(val == number[tag-1]) printf("%d\n",val+1);
    else printf("Impossible\n");
    return 0;
  }
  long long res;
  res = (long long)pow(number[tag-1]/val, 1.0/(double)(len[2-tag]-1));
  while(1){
    long long needle = convert(digit[2-tag], len[2-tag], res);
    if(needle == number[tag-1] && res >= 2) {
      printf("%lld\n",res);
      break;
    }
    else if(res <= 2 || needle < number[tag-1]){
      printf("Impossible\n");
      break;
    }
    else --res;
  }
  return 0;
}
