#include <iostream>
#include <vector>

using namespace std;

int N;
char temp, root;

class Node
{
public:
    char data;
    Node *left = NULL;
    Node *right = NULL;
};
void preorder(Node *node) //루트-왼-오 순
{
    if (node == NULL)
        return;
    cout << node->data;
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node *node) //왼-오-루트 순
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data;
}

void inorder(Node *node) //왼-루트-오 순
{
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data;
    inorder(node->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<Node> NodeVec(N); //Node를 담는 벡터

    for (int i = 0; i < N; i++)
    {
        NodeVec[i].data = ('A' + i); //각 노드에 알파벳 설정!
    }

    for (int i = 0; i < N; i++)
    {
        cin >> root;

        for (int j = 0; j < 2; j++)
        {
            cin >> temp;

            if (temp == '.')
                continue;
            switch (j)
            {
            case 0: //왼쪽 자식노드 연결
                NodeVec[root - 'A'].left = &NodeVec[temp - 'A'];
                break;

            case 1: //오른쪽 자식노드 연결
                NodeVec[root - 'A'].right = &NodeVec[temp - 'A'];
                break;
            }
        }
    }

    preorder(&NodeVec[0]); //전위 순회
    cout << '\N';
    inorder(&NodeVec[0]); //중위 순회
    cout << '\N';
    postorder(&NodeVec[0]); // 후위 순회

    return 0;
}