#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val, Node* l = nullptr, Node* r = nullptr) : data(val), left(l), right(r) {}
};

class BinaryTree
{
    Node* root;

public:
    BinaryTree(int data)
    {
        root = new Node(data);
    }

    void insert(int val)
    {
        std::queue<Node*> q;
        q.push(root);
        Node* temp;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->left != nullptr)
                q.push(temp->left);
            else
            {
                temp->left = new Node(val);
                break;
            }

            if (temp->right != nullptr)
                q.push(temp->right);
            else
            {
                temp->right = new Node(val);
                break;
            }
        }
    }

    std::vector<int> BFS_Traversal()
    {
        std::queue<Node*> q;
        std::vector<int> result;
        q.push(root);
        Node* current;

        while (!q.empty())
        {

            current = q.front();
            q.pop();
            result.push_back(current->data);

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
        return result;
    }

    std::vector<int> DFS_preorder()
    {
        std::stack<Node*> s;
        std::vector<int> result;
        s.push(root);
        Node* current;

        while (!s.empty())
        {
            current = s.top();
            s.pop();
            result.push_back(current->data);

            if (current->right != nullptr)
                s.push(current->right);

            if (current->left != nullptr)
                s.push(current->left);
        }
        return result;
    }

    std::vector<int> DFS_inorder()
    {
        std::stack<Node*> s;
        std::vector<int> result;
        Node* current = root;

        while (!s.empty() || current)
        {
            while (current)
            {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            result.push_back(current->data);
            current = current->right;
        }
        return result;
    }

    std::vector<int> DFS_postorder()
    {
        std::stack<Node*> s1, s2;
        std::vector<int> result;
        Node* current;
        s1.push(root);

        while (!s1.empty())
        {
            current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }
        while (!s2.empty())
        {
            result.push_back(s2.top()->data);
            s2.pop();
        }
        return result;
    }
};

int main()
{
    BinaryTree tree(5);
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

    std::cout << "BFS Traversal: ";
    std::vector<int> bfs_traversal = tree.BFS_Traversal();

    for (int val : bfs_traversal)
        std::cout << val << " ";

    std::cout << "\nDFS Preorder Traversal: ";
    std::vector<int> dfs_traversal = tree.DFS_preorder();

    for (int val : dfs_traversal)
        std::cout << val << " ";

    std::cout << "\nDFS Inorder Traversal: ";
    dfs_traversal = tree.DFS_inorder();
    for (int val : dfs_traversal)
        std::cout << val << " ";
    std::cout << "\nDFS Postorder Traversal: ";
    dfs_traversal = tree.DFS_postorder();
    for (int val : dfs_traversal)
        std::cout << val << " ";

    return 0;
}
