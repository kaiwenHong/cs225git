#include<stdio.h>
#include<stdlib.h>
#include "TreeNode.h"

int max(int a, int b)
{
  return (a >= b)? a: b;
}

/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct TreeNode* node)
{
   /* base case tree is empty */
   if(node == NULL) return 0;

   return 1 + max(height(node->left_), height(node->right_));
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
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

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
