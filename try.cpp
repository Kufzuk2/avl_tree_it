#include <iostream>
#include <queue>

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


void printTree(Node* root) 
{
    if (root == nullptr) 
        return;


    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        int size = q.size();

        for (int i = 0; i < size; i++) 
        {
            Node* current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if (current->left != nullptr) 
            {
                q.push(current->left);
            }

            
            if (current->right != nullptr) 
            {
                q.push(current->right);
            }
        }

    std::cout << std::endl;
    }
}


int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Tree structure:" << std::endl;
    printTree(root);

    return 0;
}


