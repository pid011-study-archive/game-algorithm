#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    using namespace std;

    // BinarySearchTree를 unique_ptr과 std::move()를 통해 구현해봤습니다.
    BinarySearchTree binarySearchTree;
    binarySearchTree.InsertNode(4);
    binarySearchTree.InsertNode(5);
    binarySearchTree.InsertNode(3);
    binarySearchTree.InsertNode(3);
    binarySearchTree.InsertNode(6);
    binarySearchTree.InsertNode(5);
    binarySearchTree.InsertNode(8);
    binarySearchTree.InsertNode(2);
    binarySearchTree.InsertNode(4);
    binarySearchTree.InsertNode(3);
    binarySearchTree.InsertNode(10);

    binarySearchTree.PrintNodes();
    // 4 3 2 3 3 5 4 6 5 8 10

    cout << binarySearchTree.DeleteNode(100) << endl;
    // 0

    cout << binarySearchTree.DeleteNode(5) << endl;
    // 1

    binarySearchTree.PrintNodes();
    // 4 3 2 3 3 4 6 5 8 10

    cout << binarySearchTree.DeleteNode(4) << endl;
    // 1

    binarySearchTree.PrintNodes();
    // 3 3 2 3 4 6 5 8 10

    const Node* node = binarySearchTree.SearchNode(8);

    int leftValue = node->LeftNode != nullptr ? node->LeftNode->Data : -1;
    int rightValue = node->RightNode != nullptr ? node->RightNode->Data : -1;

    cout << leftValue << ' ' << rightValue << endl;
    // -1 10
}
