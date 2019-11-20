#include "TreeNode.h"
#include <algorithm>


void rightRotate(TreeNode* root) {

  TreeNode *newRoot = root->left_;
  TreeNode *newLeft = newRoot->right_;

  newLeft->parent_ = root;
  newRoot->right_ = root;
  root->left_ = newLeft;

  root = newRoot;
  root->right_->parent_ = root;
  root->parent_ = nullptr;

}

void leftRotate(TreeNode* root) {

  TreeNode *newRoot = root->right_;
  TreeNode *newRight = newRoot->left_;

  newRight->parent_ = root;
  newRoot->left_ = root;
  root->right_ = newRight;

  root = newRoot;
  root->left_->parent_ = root;
  root->parent_ = nullptr;

}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
