//segment tree!
//O(logN)
#include <iostream>
#include <vector>

#define child1 idx * 2
#define child2 idx * 2 + 1

using namespace std;
using ll = long long;

int N, K, M, num, a, b, c;

class segtree
{
public:
    vector<ll> tree;
    int size; //leaf 노드의 개수

    segtree(int N)
    {
        for (size = 1; size <= N; size *= 2)
            ;
        tree.resize(2 * size);
    }

    void update(int pos, ll x)
    {
        int idx = size + pos - 1; //공식

        tree[idx] = x;
        while (idx /= 2)
        {
            //부모 노드 값 update
            tree[idx] = tree[child1] + tree[child2];
        }
    }

    ll getSum(int pos, int left, int right, int start, int end)
    {
        //left right는 찾는 범위, start end는 해당 pos 에서의 구간합 범위
        //범위에 벗어나면 0 반환
        if (right < start || left > end)
            return 0;
        //범위에 맞으면 값 반환
        if (start >= left && end <= right)
            return tree[pos];

        int mid = (start + end) / 2;

        return getSum(pos * 2, left, right, start, mid) + getSum(pos * 2 + 1, left, right, mid + 1, end);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    segtree Segment(N);

    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        Segment.update(i, num);
    }
    for (int j = 0; j < M + K; j++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            Segment.update(b, c);
        }
        else if (a == 2)
        {
            cout << Segment.getSum(1, b, c, 1, Segment.size) << '\n';
        }
    }
}