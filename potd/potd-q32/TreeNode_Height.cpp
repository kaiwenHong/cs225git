#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "TreeNode.h"

using namespace std;

int max(int a, int b)
{
  return (a >= b)? a: b;
}

int height(struct TreeNode* node)
{
   if(node == NULL) return 0;
   return 1 + max(height(node->left_), height(node->right_));
}

TreeNode* findLastUnbalanced(TreeNode* root) {
  return findLastUnbalanced(root, root);
}

TreeNode* findLastUnbalanced(TreeNode* root, TreeNode* parent) {
  int lh; /* for height of left subtree */
  int rh; /* for height of right subtree */

  /* If tree is empty then return true */
  if(root == NULL)
   return nullptr;

  if (!root->left_ && !root->right_) return nullptr;

  /* Get the height of left and right sub trees */
  lh = height(root->left_);
  rh = height(root->right_);

  if(abs(lh-rh) <= 1) {
    return parent;
  } else if (lh-rh == 0) return nullptr;

  if (lh > rh) return findLastUnbalanced(root->left_, root);
  else return findLastUnbalanced(root->right_, root);

}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
