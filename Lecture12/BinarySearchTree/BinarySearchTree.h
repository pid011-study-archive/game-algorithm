#pragma once
#include <memory>

class Node
{
public:
    explicit Node(int data, std::unique_ptr<Node>&& leftNode = nullptr, std::unique_ptr<Node>&& rightNode = nullptr)
        : Data(data), LeftNode(std::move(leftNode)), RightNode(std::move(rightNode)) { }

    int Data;
    std::unique_ptr<Node> LeftNode;
    std::unique_ptr<Node> RightNode;
};

class BinarySearchTree
{
public:
    BinarySearchTree() : _rootNode(nullptr) { }

    const Node* SearchNode(int data) const;
    void PrintNodes() const;
    size_t Height() const;
    const Node* RootNode() const { return _rootNode.get(); }

    const Node* InsertNode(int data);
    bool DeleteNode(int data);

private:
    std::unique_ptr<Node> _rootNode;
};
