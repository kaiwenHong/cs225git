#include "TreeNode.h"

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
  if ((getHeight(subroot->left_) - getHeight(subroot->right_)) > 1) {
    if(leftHeavy(subroot->left_)) return TreeNode::right;
    else return TreeNode::leftRight;
  } else {
    if (rightHeavy(subroot->right_)) return TreeNode::left;
    else return TreeNode::rightLeft;
  }
}
