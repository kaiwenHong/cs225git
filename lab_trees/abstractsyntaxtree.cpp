#include "abstractsyntaxtree.h"
#include <string>

using namespace std;
/**
 * Calculates the value from an AST (Abstract Syntax Tree). To parse numbers from strings, please use std::stod
 * @return A double representing the calculated value from the expression transformed into an AST
 */
double AbstractSyntaxTree::eval() const {
    //double result = std::stod(curr->elem)
    double result = 0;
    return eval(root, result);
}

double AbstractSyntaxTree::eval(typename BinaryTree<std::string>::Node* subRoot, double& sum) const {
  if (subRoot == NULL) return 0;
  if (subRoot->left != NULL && subRoot->right != NULL && subRoot->elem == "+") return eval(subRoot->left, sum) + eval(subRoot->right, sum);
  if (subRoot->left != NULL && subRoot->right != NULL && subRoot->elem == "-") return eval(subRoot->left, sum) - eval(subRoot->right, sum);
  if (subRoot->left != NULL && subRoot->right != NULL && subRoot->elem == "*") return eval(subRoot->left, sum) * eval(subRoot->right, sum);
  if (subRoot->left != NULL && subRoot->right != NULL && subRoot->elem == "/") return eval(subRoot->left, sum) / eval(subRoot->right, sum);
  return stod(subRoot->elem);
}
