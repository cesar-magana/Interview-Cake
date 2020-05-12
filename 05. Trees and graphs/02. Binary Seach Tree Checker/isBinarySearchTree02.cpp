#include <iostream>
#include <memory>
#include <climits>
#include <stack>
// C++11 lest unit testing framework
#include "lest.hpp"

using namespace std;

class BinaryTreeNode
{
public:
    int value_;
    BinaryTreeNode* left_;
    BinaryTreeNode* right_;

    BinaryTreeNode(int value) :
        value_(value),
        left_(nullptr),
        right_(nullptr)
    {
    }

    ~BinaryTreeNode()
    {
        delete left_;
        delete right_;
    }

    BinaryTreeNode* insertLeft(int value)
    {
        this->left_ = new BinaryTreeNode(value);
        return this->left_;
    }

    BinaryTreeNode* insertRight(int value)
    {
        this->right_ = new BinaryTreeNode(value);
        return this->right_;
    }
};

class NodeBounds
{
public:
    const BinaryTreeNode* node_;
    int lowerBound_;
    int upperBound_;

    NodeBounds(const BinaryTreeNode* node = nullptr,
            int lowerBound = numeric_limits<int>::min(),
            int upperBound = numeric_limits<int>::max()) :
        node_(node),
        lowerBound_(lowerBound),
        upperBound_(upperBound)
    {
    }
};

bool isBinarySearchTree(const BinaryTreeNode* root)
{
    // start at the root, with an arbitrarily low lower bound
    // and an arbitrarily high upper bound
    stack<NodeBounds> nodeAndBoundsStack;
    nodeAndBoundsStack.push(NodeBounds(root));

    // depth-first traversal
    while (!nodeAndBoundsStack.empty()) {
        const NodeBounds nodeBounds = nodeAndBoundsStack.top();
        nodeAndBoundsStack.pop();

        // if this node is invalid, we return false right away
        int nodeValue = nodeBounds.node_->value_;
        if (nodeValue <= nodeBounds.lowerBound_ || nodeValue >= nodeBounds.upperBound_) {
            return false;
        }

        if (nodeBounds.node_->left_ != nullptr) {
            // this node must be less than the current node
            nodeAndBoundsStack.push(NodeBounds(nodeBounds.node_->left_,
                nodeBounds.lowerBound_, nodeValue));
        }
        if (nodeBounds.node_->right_ != nullptr) {
            // this node must be greater than the current node
            nodeAndBoundsStack.push(NodeBounds(nodeBounds.node_->right_,
                nodeValue, nodeBounds.upperBound_));
        }
    }

    // if none of the nodes were invalid, return true
    // (at this point we have checked all nodes)
    return true;
}


















// tests

const lest::test tests[] = {
    {CASE("Valid full tree") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertLeft(30)->insertLeft(10);
        root->insertRight(70)->insertRight(80);
        root->left_->insertRight(40);
        root->right_->insertLeft(60);
        EXPECT(isBinarySearchTree(root.get()) == true);
    }},
    {CASE("Both subtrees valid") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertLeft(30)->insertLeft(20);
        root->insertRight(80)->insertRight(90);
        root->left_->insertRight(60);
        root->right_->insertLeft(70);
        EXPECT(isBinarySearchTree(root.get()) == false);
    }},
    {CASE("Descending linked list") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertLeft(40)->insertLeft(30)->insertLeft(20)->insertLeft(10);
        EXPECT(isBinarySearchTree(root.get()) == true);
    }},
    {CASE("Out of order linked list") {
        auto root = make_unique<BinaryTreeNode>(50);
        root->insertRight(70)->insertRight(60)->insertRight(80);
        EXPECT(isBinarySearchTree(root.get()) == false);
    }},
    {CASE("One node tree") {
        auto root = make_unique<BinaryTreeNode>(50);
        EXPECT(isBinarySearchTree(root.get()) == true);
    }}
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}