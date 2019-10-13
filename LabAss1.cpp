#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main();

/*--- Answer One ---*/
struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int key){
  struct node* temp = new node;
  temp->data = key;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct node* constructUtil(int arr[], int *index, int key, int min, int max, int size){
  if(*index < 0)
    return NULL;
  struct node* root = NULL;
  if((key > min) && (key < max)){
    root = newNode(key);
    *index = *index - 1;
    if(*index >= 0){
      root->right = constructUtil(arr, index, arr[*index], key, max, size);
      root->left = constructUtil(arr, index, arr[*index], min, key, size);
    }
  }
  return root;
}

struct node* construct(int arr[], int size){
  int index = size-1;
  return constructUtil(arr, &index, arr[index], INT_MIN, INT_MAX, size);
}

void inorder(struct node* root){
  if(root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void oneAns(){
  int pos[] = {1, 7, 2, 15, 35, 40, 29, 11};
  int size = sizeof(pos)/sizeof(pos[0]);
  struct node* root = construct(pos, size);
  cout << "Inorder Traversal:" << endl;
  inorder(root);
}

/*--- Answer Two ---*/
void twoAns(){
  
}

/*--- DRIVER PROGRAM UTILS ---*/
void pause(){
  char c = 'a';
  while(c!='c'){
    cout << "Press \'c\' to continue." << endl;
    cin >> c;
  }
}

void bar(){
  cout << endl << endl << "\t\t\t==================================" << endl << endl;
}

/*--- Questions ---*/
void ques(int n){
 
  cout << "ENTER QUESTION NO YOU WANT TO SEE:"<< endl;
  switch(n){
    case 1:
      cout << "WAP to construct a binary search tree (BST) from the post-order traversal and print the inorder traversal of the constructed tree." << endl;
      cout << endl << "\tCheck for the following input:" << endl;
      cout << "\t\t1 7 2 15 35 40 29 11" << endl << endl;
      break;
    case 2:
      cout << "Given a BST, WAP to find the k-th smallest and k-th largest element in the BST" << endl;
      cout << endl << "For the BST constructed in the question 1, find the 3rd smallest and 4th largest element." << endl << endl;
      break;
    case 3:
      cout << "WAP to construct an AVL tree from the given array of integers (Performing all the given rotations)" << endl << endl;
      break;
    case 4:
      cout << "Given an array of integers, WAP to find the sequence in which these integers should be added to an AVL tree such that no rotations are required to balance the tree." << endl << endl;
      break;
  }
  cout << "ANSWER:" << endl;
}

void manage(int n){
  system("cls");
  bar();
  switch (n) {
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
      break;
    case 4:
      ques(4);
      break;
  }
  bar();
  pause();
}

int main(){
  while(1){
    system("cls");
    cout << "Select a question to run:" << endl;
    cout << "\t1] Question 1 - " << endl;
    cout << "\t\t\"Construct BST from post-order traversal and print the inorder traversal\"" << endl;
    cout << "\t2] Question 2 - " << endl;
    cout << "\t\t\"Find k-th smallest and k-th largest number in BST\"" << endl;
    cout << "\t3] Question 3 - " << endl;
    cout << "\t\t\"AVL tree from given array of integers\"" << endl;
    cout << "\t4] Question 4 - " << endl;
    cout << "\t\t\"Find the sequence of integers such that no rotations are required while inserting in an AVL\"" << endl;
    cout << endl;
    cout << "\t0] Exit" << endl;
    cout << endl;
    cout << "Option: " ;
    int n;
    cin >> n;
    switch (n) {
      case 0:
        return 0;
        break;
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
    }
  }
  return 0;
}
