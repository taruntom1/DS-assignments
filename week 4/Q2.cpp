#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <string>

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val, Node *l = nullptr, Node *r = nullptr) : data(val), left(l), right(r) {}
};

class BST
{
private:
    Node *root;

    void treeToMatrixRec(Node *root, int row, int col, int height,
                         std::vector<std::vector<std::string>> &ans)
    {
        if (!root)
        {
            return;
        }

        // Calculate offset for child positions
        int offset = pow(2, height - row - 1);

        // Traverse the left subtree
        if (root->left)
        {
            treeToMatrixRec(root->left, row + 1, col - offset, height, ans);
        }

        // Place the current node's value in the matrix
        ans[row][col] = std::to_string(root->data);

        // Traverse the right subtree
        if (root->right)
        {
            treeToMatrixRec(root->right, row + 1, col + offset, height, ans);
        }
    }

    // Function to convert the binary tree to a 2D matrix
    std::vector<std::vector<std::string>> treeToMatrix(Node *root)
    {

        // Find the height of the tree
        int height = findHeight(root);

        // Rows are height + 1; columns are 2^(height+1) - 1
        int rows = height + 1;
        int cols = pow(2, height + 1) - 1;

        // Initialize 2D matrix with empty strings
        std::vector<std::vector<std::string>> ans(rows, std::vector<std::string>(cols, ""));

        // Populate the matrix using inorder traversal
        treeToMatrixRec(root, 0, (cols - 1) / 2, height, ans);

        return ans;
    }

    void print2DArray(std::vector<std::vector<std::string>> &arr)
    {
        for (auto &row : arr)
        {
            for (auto &cell : row)
            {
                if (cell.empty())
                {
                    std::cout << "  ";
                }
                else
                {
                    std::cout << cell;
                }
            }
            std::cout << std::endl;
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int val)
    {
        Node *new_node = new Node(val);
        if (root == nullptr)
            root = new_node;
        else
        {
            std::queue<Node *> q;
            q.push(root);
            Node *temp;
            while (!q.empty())
            {
                temp = q.front();
                q.pop();

                if (temp->data > val)
                {
                    if (temp->left == nullptr)
                        temp->left = new_node;
                    else
                        q.push(temp->left);
                }
                else
                {
                    if (temp->right == nullptr)
                        temp->right = new_node;
                    else
                        q.push(temp->right);
                }
            }
        }
    }

    void deleteNode(Node *node)
    {

        if (node->right)
        {
            Node *parent;
            Node *min_node = successorLoc(node, &parent);
            node->data = min_node->data;

            delete min_node;
            parent->left = nullptr;
        }

        else if (node->left)
        {
            Node *temp = node->left;
            delete node;
            node = temp;
        }
        else
        {
            delete node;
        }
    }

    std::vector<int> Traversal()
    {
        std::queue<Node *> q;
        std::vector<int> result;
        q.push(root);
        Node *temp;

        while (!q.empty())
        {

            temp = q.front();
            q.pop();
            result.push_back(temp->data);

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
        return result;
    }

    Node *search(int key, Node *node = nullptr)
    {
        if (node == nullptr)
            node = root;

        while (node != nullptr && key != node->data)
        {
            if (key < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return node;
    }

    Node *minLoc(Node *node, Node **parent = nullptr)
    {
        while (node->left->left)
        {
            node = node->left;
        }
        if (parent)
            *parent = node;
        return node->left;
    }

    Node *maxLoc(Node *node, Node **parent = nullptr)
    {
        while (node->right->right)
        {
            node = node->right;
        }
        if (parent)
            *parent = node;
        return node->right;
    }

    int min(Node *node = nullptr)
    {
        if (node == nullptr)
            node = root;

        return minLoc(node)->data;
    }

    int max(Node *node = nullptr)
    {
        if (node == nullptr)
            node = root;

        return maxLoc(node)->data;
    }

    Node *predecessorLoc(Node *node, Node **parent = nullptr)
    {
        Node *curr = node->left;

        return maxLoc(curr, parent);
    }
    Node *successorLoc(Node *node, Node **parent = nullptr)
    {
        Node *curr = node->right;

        return minLoc(curr, parent);
    }

    int predecessor(Node *node)
    {
        if (node == nullptr)
            node = root;
        Node *predecessor = predecessorLoc(node);
        return predecessor->data;
    }
    int successor(Node *node)
    {
        if (node == nullptr)
            node = root;
        Node *successor = successorLoc(node);
        return successor->data;
    }

    int findHeight(Node *root)
    {
        if (!root)
        {
            return -1;
        }

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        return std::max(leftHeight, rightHeight) + 1;
    }

    Node *getRoot()
    {
        return root;
    }

    void printTree()
    {
        std::vector<std::vector<std::string>> result = treeToMatrix(root);

        print2DArray(result);
    }
};

int main()
{
    BST tree;

    // insert elements to ensure height of at least 4
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(25);
    tree.insert(35);
    tree.insert(45);
    tree.insert(55);
    tree.insert(65);
    tree.insert(75);
    tree.insert(85);

    std::cout << "Inserted elements" << std::endl;

    std::cout << "Tree:" << std::endl;
    tree.printTree();
    std::cout << std::endl;

    // Delete an element
    int deleteKey = 30;
    tree.deleteNode(tree.search(deleteKey));
    std::cout << "Deleted " << deleteKey << std::endl;
    std::cout << "Searching for " << deleteKey << " after deletion: "
              << (tree.search(deleteKey) ? "Found" : "Not Found") << std::endl;
    std::cout << "Tree:" << std::endl;
    tree.printTree();
    std::cout << std::endl;

    // Search for an element
    int searchKey = 40;
    std::cout << "Searching for " << searchKey << ": "
              << (tree.search(searchKey) ? "Found" : "Not Found")
              << " Memory location :" << tree.search(searchKey) << std::endl
              << std::endl;

    // Find minimum and maximum
    std::cout << "Minimum value: " << tree.min() << std::endl;
    std::cout << "Maximum value: " << tree.max() << std::endl;
    std::cout << std::endl;

    // Find minimum and maximum under a subtree
    int subtreeKey = 70;
    std::cout << "Minimum value under subtree " << subtreeKey << ": "
              << tree.min(tree.search(subtreeKey)) << std::endl;
    std::cout << "Maximum value under subtree" << subtreeKey << ": "
              << tree.max(tree.search(subtreeKey)) << std::endl;
    std::cout << std::endl;

    // Find predecessor and successor
    int key = 50;
    std::cout << "Predecessor of " << key << ": "
              << tree.predecessor(tree.search(key)) << std::endl;
    std::cout << "Successor of " << key << ": "
              << tree.successor(tree.search(key)) << std::endl;
    key = 70;
    std::cout << "Predecessor of " << key << ": "
              << tree.predecessor(tree.search(key)) << std::endl;
    std::cout << "Successor of " << key << ": "
              << tree.successor(tree.search(key)) << std::endl;

    return 0;
}
