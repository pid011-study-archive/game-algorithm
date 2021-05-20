#include <iostream>
#include "BinarySearchTree.h"

const Node* searchNode(const std::unique_ptr<Node>& node, int data)
{
    if (node == nullptr) return nullptr;
    if (data < node->Data) return searchNode(node->LeftNode, data);
    if (data > node->Data) return searchNode(node->RightNode, data);

    return node.get(); // found
}

const Node* BinarySearchTree::SearchNode(int data) const
{
    return searchNode(_rootNode, data);
}

void printNodes(const std::unique_ptr<Node>& node)
{
    if (node == nullptr) return;

    // search by pre-order
    std::cout << node->Data << ' ';
    printNodes(node->LeftNode);
    printNodes(node->RightNode);
}

void BinarySearchTree::PrintNodes() const
{
    printNodes(_rootNode);
    std::cout << std::endl;
}

size_t calcHeight(const std::unique_ptr<Node>& node)
{
    if (node == nullptr) return -1;

    return 1 + std::max(calcHeight(node->LeftNode), calcHeight(node->RightNode));
}

size_t BinarySearchTree::Height() const
{
    return calcHeight(_rootNode);
}

const Node* insertNode(std::unique_ptr<Node>& node, int data)
{
    if (node == nullptr)
    {
        node = std::make_unique<Node>(data);
        return node.get();
    }

    return insertNode(data < node->Data ? node->LeftNode : node->RightNode, data);
    // data == node->Data -> node->RightNode
}

const Node* BinarySearchTree::InsertNode(int data)
{
    return insertNode(_rootNode, data);
}

std::unique_ptr<Node> getLeafNodeByInOrderPredecessor(std::unique_ptr<Node>& node, int data)
{
    if (node->RightNode == nullptr)
    {
        return std::move(node);
    }

    return getLeafNodeByInOrderPredecessor(node->RightNode, data);
}

bool deleteNode(std::unique_ptr<Node>& node, int data)
{
    if (node == nullptr)
    {
        return false;
    }

    if (node->Data == data)
    {
        if (node->LeftNode == nullptr && node->RightNode == nullptr)
        {
            node.reset();
        }
        else if (node->LeftNode == nullptr)
        {
            std::unique_ptr<Node> tempNode = std::move(node->RightNode);
            node.reset();

            node = std::move(tempNode);
        }
        else if (node->RightNode == nullptr)
        {
            std::unique_ptr<Node> tempNode = std::move(node->LeftNode);
            node.reset();

            node = std::move(tempNode);
        }
        else
        {
            // In-order predecessor
            std::unique_ptr<Node> leafNode = getLeafNodeByInOrderPredecessor(node->LeftNode, node->Data);

            leafNode->LeftNode = std::move(node->LeftNode);
            leafNode->RightNode = std::move(node->RightNode);

            node.reset();
            node = std::move(leafNode);
        }

        return true;
    }

    return deleteNode(node->Data > data ? node->LeftNode : node->RightNode, data);
}

bool BinarySearchTree::DeleteNode(int data)
{
    return deleteNode(_rootNode, data);
}
