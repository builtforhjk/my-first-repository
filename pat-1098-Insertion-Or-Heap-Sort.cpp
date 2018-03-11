#include <iostream>
#include <cstdio>
using namespace std;
int *heap, *needle;
void adjustHeap(int pos){
  int j = pos*2;
  while(j <= heap[0]){
    if(j < heap[0] && heap[j] < heap[j+1]) ++j;
    if(heap[j] > heap[pos]){
      int tmp = heap[pos];
      heap[pos] = heap[j];
      heap[j] = tmp;
      pos = j;
    }
    else break;
    j *= 2;
  }
}
void buildMinHeap(){
  for(int pos = heap[0]/2; pos > 0; --pos)
    adjustHeap(pos);
}
bool heapSort(){
  buildMinHeap();
  int k = heap[0];
  bool terminate = false;
  for(int i = heap[0]; i > 1;--i){
    int tmp = heap[1];
    heap[1] = heap[heap[0]];
    heap[heap[0]] = tmp;
    --heap[0];
    adjustHeap(1);
    if(terminate){
      printf("Heap Sort\n");
      for(int j = 1; j <= k; ++j){
        printf("%d",heap[j]);
        if(j == k) printf("\n");
        else printf(" ");
      }
      break;
    }
    bool sign = true;
    for(int j = 1; j <= k; ++j){
      if(needle[j] != heap[j]){
        sign = false;
        break;
      }
    }
    if(sign) terminate = true;
  }
  heap[0] = k;
  return terminate;
}
void insertSort(){
  int pivot = 2;
  for(;pivot <= needle[0] && needle[pivot]>=needle[pivot-1]; ++pivot);
  for(int i = 1; i < pivot; ++i){
    if(needle[i] > needle[pivot]){
      int tmp = needle[pivot];
      for(int j = pivot-1; j >= i; --j)
        needle[j+1] = needle[j];
      needle[i] = tmp;
      break;
    }
  }
  printf("Insertion Sort\n");
  for(int i = 1; i <= needle[0]; ++i){
    printf("%d",needle[i]);
    if(i == needle[0]) printf("\n");
    else printf(" ");
  }
}
int main(){
  int n;
  scanf("%d",&n);
  heap = new int[n+1];
  needle = new int[n+1];
  heap[0] = n;
  needle[0] = n;
  for(int i = 1; i <= n; ++i)
    scanf("%d",heap+i);
  for(int i = 1; i <= n; ++i)
    scanf("%d",needle+i);
  if(!heapSort()) insertSort();
  return 0;
}
