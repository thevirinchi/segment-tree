#include <std/bitc++.h>
using namespace std;

int constructUtil(int arr[], int ss, int se, int *st, int si){
  (ss == se) ? goto ONE: goto MANY;
  ONE:
    st[si] = arr[ss];
    return arr[ss];
  MANY:
    int mid = getMid(ss, se);
    st[si] = constructUtil(arr, ss, mid, st, si*2+1) + constructUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int* construct(int arr[], int n){
  int h = (int)(ceil(log2(n)));
  int maxSize = 2*(int)pow(2,h)-1;
  int* st = new int[maxSize];
  constructUtil(arr, 0, n-1, st, 0);
  return st;
}

int main(){
  return 0;
}
