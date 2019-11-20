#include "TreeNode.h"
#include <iostream>
using namespace std;

int main() {
/*
 * Example 1: Deleting a leaf node
 * key = 14
 *     9
 *    / \
 *   5   12
 *  /\   / \
 * 2  7 10 14
 *
 * After deleteNode(14): 
 *      9
 *     / \
 *    5   12
 *   /\  /
 *  2  7 10 
 *
 * Example 2: Deleting a node which has only 
 * one child. 
 *       9
 *      / \
 *     5   12
 *    / \  /
 *   2   7 10  
 *
 * After deleteNode(12): 
 *       9
 *      / \
 *     5   10
 *    / \  
 *   2   7  
 *
 * Example 3: Deleting a node with 2 children
 * After deleteNode(5): 
 * Method 1 (IOS)
 *       9
 *      / \
 *     7   10
 *    /    
 *   2     
 * 
 * Method 2 (IOP)
 *       9
 *      / \
 *     2   10
 *      \  
 *       7 
 */

  TreeNode * root = new TreeNode(9);
  root->left_ = new TreeNode(5);
  root->right_ = new TreeNode(12);
  root->left_->left_ = new TreeNode(2);
  root->left_->right_ = new TreeNode(7);
  root->right_->left_ = new TreeNode(10);
  root->right_->right_ = new TreeNode(14);

  cout << "Before deleting a leaf: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 14);
  cout << "After deleting a leaf: " << endl;
  inorderPrint(root);
  cout << endl;

  cout << "Before deleting a node with 1 child: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 12);
  cout << "After deleting a node with 1 child: " << endl;
  inorderPrint(root);
  cout << endl;

  cout << "Before deleting a node with 2 child: " << endl;
  inorderPrint(root);
  cout << endl;
  root = deleteNode(root, 5);
  cout << "After deleting a node with 2 child: " << endl;
  inorderPrint(root);
  cout << endl;

  deleteTree(root);
  return 0;

}
