#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void error(){
  cout << endl << "Error encountered. restarting program..." << endl;
  Sleep(1500);
}

int getMin(int a, int b){
  return (a<b)?a:b;
}

int getMid(int a, int b){
  return (a+(b-a)/2);
}

/*    QUESTION ONE    */
int minQuerryUtil(int* st, int ss, int se, int qs, int qe, int ind){
  if(qs <= ss && qe >= se)
    return st[ind];
  else if(qs > se || qe < ss)
    return INT_MAX;
  int mid = getMid(ss, se);
  return getMin(minQuerryUtil(st, ss, mid, qs, qe, ind*2+1), minQuerryUtil(st, mid+1, se, qs, qe, ind*2+2));
}

int minQuerry(int* st, int n, int qs, int qe){
  if(qs < 0 || qe > n-1 || qs > qe){
    error();
    return INT_MAX;
  }
  minQuerryUtil(st, 0, n-1, qs, qe, 0);
}

int constructUtil(int arr[], int ss, int se, int* st, int si){
  if(ss == se){
    st[si] = arr[ss];
    return arr[ss];
  }
  int mid = getMid(ss, se);
  st[si] = getMin(constructUtil(arr, ss, mid, st, si*2+1), constructUtil(arr, mid+1, se, st, si*2+2));
  return st[si];
}

int* construct(int arr[], int n){
  int h = (int)ceil(log2(n));
  int maxSize = 2*(int)pow(2,h)-1;
  int *st = new int[maxSize];
  constructUtil(arr, 0, n-1, st, 0);
  return st;
}

void oneAns(){
  cout << "Enter the size of the array:";
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cout << "\t" << i+1 << "] ";
    cin >> arr[i];
  }
  int *st = construct(arr, n);
  int lower, upper;
  cout << "Enter the lower end: ";
  cin >> lower;
  cout << "Enter the upper end: ";
  cin >> upper;
  cout << "Minimum = " << minQuerry(st, n, lower, upper);
}

/*    QUESTION TWO    */

int constructUtilSum(int arr[], int ss, int se, int* st, int si){
  if(ss == se){
    st[si] = arr[ss];
    return arr[ss];
  }
  int mid = getMid(ss, se);
  st[si] = constructUtil(arr, ss, mid, st, si*2+1) + constructUtil(arr, mid+1, se, st, si*2+2);
  return st[si];
}

int* constructSum(int arr[], int n){
  int h = (int)ceil(log2(n));
  int maxSize = 2*(int)pow(2,h)-1;
  int *st = new int[maxSize];
  constructUtilSum(arr, 0, n-1, st, 0);
  return st;
}

void twoAns(){
  cout << "Enter the size of the arrays: ";
  int n;
  cin >> n;
  int arr1[n];
  int arr2[n];
  cout << "Fill the first array: " << endl;
  for(int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++){
    cout << " " << i+1 << "] ";
    cin >> arr1[i];
  }
  cout << "Fill the second array: " << endl;
  for(int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++){
    cout << " " << i+1 << "] ";
    cin >> arr2[i];
  }
  cout << "Enter the selection range for first array: " << endl;
  cout << "Lower: " ;
  int lo;
  cin >> lo;
  cout << "Upper: " ;
  int up;
  cin >> up;
  if(lo<0 || lo>n || lo > up || up < 0)
    error();
  int ind = 0;
  int arr[n];
  for(int i = 0; i < n; i++)
    if(i == lo)
      while(i <= up)
        arr[ind++] = arr1[i++];
  cout << "Enter the selection range for second array: " << endl;
  cout << "Lower: " ;
  cin >> lo;
  cout << "Upper: " ;
  cin >> up;
  if(lo<0 || lo>n || lo>up || up<0)
    error();
  for(int i = 0; i < n; i++)
    if(i == lo)
      while(i <= up)
        arr[ind++] = arr2[i++];
  cout << "New formed array: [";
  for(int i = 0; i<n-1; i++)
    cout << arr[i] << ", ";
  cout << arr[n-1] << "]" << endl;
  int *st = constructSum(arr, n);
  int count = 0;
  cout << "Finding number of disinct elements..." << endl;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < i; j++)
      if(arr[i] == arr[j])
        ++count;
  cout << "Number of distinct elements = " << n - count;
}

/*  QUESTION THREE  */

void update1(int tree[], int si, int ss, int se, int lo, int up, int offset){
  if(lo<0 || lo>n || lo>up || up<0){
    error();
    return;
  }
  if(ss == se){
    a
  }

}

void thrAns(){
  cout << "Enter the size of the array:";
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i<n; i++){
    cout << "\t" << i+1 << "] ";
    cin >> arr[i];
  }
  int *st = construct(arr, n);
  cout << "PART ONE:" << endl;
  int lo, up;
  cout << "Enter the lower end: ";
  cin >> lo;
  cout << "Enter the upper end: ";
  cin >> up;
  cout << "Updating the values..." << endl;
  update1(lo, up);
}

/*    PROGRAM UTILS   */
void ques(int n){
  switch(n){
    case 1:
      cout << "QUESTION 1" << endl;
      break;
    case 2:
      cout << "QUESTION 2" << endl;
      break;
    case 3:
      cout << "QUESTION 3" << endl;
      break;
  }
}

void pause(){
  char c = 'a';
  while(c!='c'){
    cout << endl << "Enter 'c' to continue..." << endl;
    cin >> c;
  }
}

void manage(int n){
  system("cls");
  switch(n){
    case 1:
      ques(1);
      oneAns();
      break;
    case 2:
      ques(2);
      twoAns();
      break;
    case 3:
      ques(3);
      thrAns();
      break;
  }
  pause();
}

int main(){
  while(1){
    system("cls");
    cout << "\t\tLab Assignment 2" << endl << endl;
    cout << "[ _ ] Select a question:" << endl;
    cout << "     [ - ] Question 1" << endl;
    cout << "     [ - ] Question 2" << endl;
    cout << "     [ - ] Question 3" << endl;
    cout << "     [ - ] Question 4" << endl;
    int n;
    cout << "[ _ ] Option: ";
    cin >> n;
    switch(n){
      case 0:
        return 0;
      case 1:
        manage(1);
        break;
      case 2:
        manage(2);
        break;
      case 3:
        manage(3);
        break;
      case 4:
        manage(4);
        break;
      default:
        error();
        break;
    }
  }
}
