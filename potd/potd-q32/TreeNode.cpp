#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "TreeNode.h"

using namespace std;

int max(int a, int b) { return (a >= b)? a: b; }

int height(struct TreeNode* node) {
   if(node == NULL) return 0;
   return 1 + max(height(node->left_), height(node->right_));
}

bool isHeightBalanced(TreeNode* root) {

  int lh; /* for height of left subtree */
  int rh; /* for height of right subtree */

  /* If tree is empty then return true */
  if(root == NULL)
   return 1;

  /* Get the height of left and right sub trees */
  lh = height(root->left_);
  rh = height(root->right_);

  if( abs(lh-rh) <= 1 &&
      isHeightBalanced(root->left_) &&
      isHeightBalanced(root->right_))
    return 1;

  /* If we reach here then tree is not height-balanced */
  return 0;

}

TreeNode* findLastUnbalanced(TreeNode* root) {

  if (root == NULL) return nullptr;
  if (!root->left_ && !root->right_) return nullptr;

  int lh = height(root->left_);
  int rh = height(root->right_);

  if (lh == rh) return nullptr;
  if (isHeightBalanced(root->left_) && isHeightBalanced(root->right_)) return root;

  if (lh > rh) return findLastUnbalanced(root->left_);
  return findLastUnbalanced(root->right_);

}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
