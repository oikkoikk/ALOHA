//이진 검색 트리 구현 없이! 후위 순회 출력!
//분할정복 알고리즘
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int len, num;
vector<int> tree;

void divideConquer(int start, int end){ //분할 정복
    if (start >= end) //종료 조건
         return;
    //subtree의 root보다 큰 값이 나오는 지점을 저장!
    int upperIndex = abs(tree.begin()- upper_bound(tree.begin()+start+1, tree.begin()+end, tree[start]));
    divideConquer(start+1, upperIndex); //후위 순회하도록 왼쪽 자식노드 먼저 재귀호출
    divideConquer(upperIndex, end); //오른쪽 자식노드 재귀 호출!

    cout << tree[start] << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        cin >> num;
        if (cin.eof() == true)
            break;

        tree.push_back(num);
        len++;
    }

    divideConquer(0, len);
}