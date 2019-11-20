#include <iostream>
#include "TreeNode.h"

using namespace std;

void preot(TreeNode *n) {
    if (n==NULL)
        cout << "x";
    else {
        cout << "(" << n->val_ << " ";
        preot(n->left_);
        cout << " ";
        preot(n->right_);
        cout << ")";
    }
}

int main() {
  TreeNode * n1 = new TreeNode(2);
  TreeNode * n2 = new TreeNode(5);
  TreeNode * n3 = new TreeNode(8);
  TreeNode * n4 = new TreeNode(10);
  TreeNode * n5 = new TreeNode(13);
  n4->left_ = n3;
  n3->parent_ = n4;
  n4->right_ = n5;
  n5->parent_ = n4;
  n3->left_ = n2;
  n2->parent_ = n3;
  n2->left_ = n1;
  n1->parent_ = n2;

  preot(n4);
  cout << endl;

  // Your Code Here (Right or left rotate to balance above tree? )

  preot(n4);
  cout << endl;
  deleteTree(n4);


  n1 = new TreeNode(2);
  n2 = new TreeNode(5);
  n3 = new TreeNode(8);
  n4 = new TreeNode(10);
  n5 = new TreeNode(13);
  n2->right_ = n3;
  n3->parent_ = n2;
  n2->left_ = n1;
  n1->parent_ = n2;
  n3->right_ = n4;
  n4->parent_ = n3;
  n4->right_ = n5;
  n5->parent_ = n4;

  preot(n2);
  cout << endl;
 // Your Code Here (Right or left rotate to balance above tree? )
  rightRotate(n2);

  cout << "n4_parent = " << n4->parent_ << endl;
  cout << "n1 = " << n1 << endl;

  preot(n2);
  cout << endl;
  deleteTree(n2);

  return 0;
}
