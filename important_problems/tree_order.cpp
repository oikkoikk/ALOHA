//트리 구현 및 트리 순회 구현!

#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data) : data(data) //생성자!
    {
        this->left = NULL;
        this->right = NULL;
    }
};
void preorder(Node *node) //루트-왼-오 순
{
    if (node == NULL)
        return;
    cout << ' ' << node->data << ' ';
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node) //왼-오-루트 순
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << ' ' << node->data << ' ';
}

void inorder(Node *node) //왼-루트-오 순
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << ' ' << node->data << ' ';
    inorder(node->right);
}

int main()
{
    Node A('A');
    Node B('B');
    Node C('C');
    Node D('D');
    Node E('E');
    Node F('F');
    Node G('G');
    Node H('H');
    Node I('I');
    Node J('J');

    A.left = &B;
    A.right = &C;
    B.left = &D;
    B.right = &E;
    D.left = &G;
    D.right = &H;
    C.right = &F;
    F.left = &I;
    F.right = &J;

    /* 
     
          A
         / \
        B   C
       / \   \
      D   E   F
     / \     / \ 
    G   H   I   J
    
    */
    cout << "전위 순회: ";
    preorder(&A);
    cout << '\n';

    cout << "후위 순회: ";
    postorder(&A);
    cout << '\n';

    cout << "중위 순회: ";
    inorder(&A);
    cout << '\n';

    return 0;
}