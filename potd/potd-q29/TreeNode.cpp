#include "TreeNode.h"
#include <iostream>

TreeNode * minValueNode(TreeNode* node) {
  TreeNode * curr = node;
  while (curr->left_) curr=curr->left_;
  return curr;
}

TreeNode * deleteNode(TreeNode* root, int key) {
  if (!root) return root;
  if (key < root->val_) root->left_ = deleteNode (root->left_, key);
  else if (key > root->val_) root->right_ = deleteNode (root->right_, key);
  else {
    if (!root->left_) {
      TreeNode *temp = root->right_;
      delete root;
      return temp;
    } else if (!root->right_) {
      TreeNode *temp = root->left_;
      delete root;
      return temp;
    }
    TreeNode *temp = minValueNode(root->right_);
    root->val_ = temp->val_;
    root->right_ = deleteNode(root->right_, temp->val_);
  }
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
