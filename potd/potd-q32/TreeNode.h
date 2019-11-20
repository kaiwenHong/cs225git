#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>
#pragma once

// Definition for a binary tree node.

struct TreeNode {
    int val_;
    int balance_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
      balance_ = 0;
    }
};


TreeNode* findLastUnbalanced(TreeNode* root);

void deleteTree(TreeNode* root);

#endif
