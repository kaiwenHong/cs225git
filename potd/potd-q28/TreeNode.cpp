#include "TreeNode.h"

#include <cstddef>
#include <iostream>
#include <algorithm>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  if (!left_ && !right_) return 0;
  int leftHeight = (!left_ ? 0 : left_->getHeight());
  int rightHeight = (!right_ ? 0 : right_->getHeight());
  return 1 + max(leftHeight, rightHeight);
}
