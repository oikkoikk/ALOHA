//segment tree!
#include <iostream>
#include <vector>

#define child1 idx * 2
#define child2 idx * 2 + 1

using namespace std;
using ll = long long;

int N, M, num, a, b;

class min_segtree
{
public:
    vector<ll> min_tree; //최솟값 저장
    int size;            //leaf 노드의 개수

    min_segtree(int N)
    {
        for (size = 1; size <= N; size *= 2)
            ;
        min_tree.resize(2 * size,1987654321);
    }

    void update(int pos, ll x)
    {
        int idx = size + pos - 1;

        min_tree[idx] = x;
        while (idx /= 2)
        {
            //부모 노드 값 update
            min_tree[idx] = min(min_tree[child1], min_tree[child2]);
        }
    }

    ll getMinimum(int pos, int left, int right, int start, int end)
    {
        //left right는 찾는 범위, start end는 해당 pos 에서의 구간합 범위
        //범위에 벗어나면 0 반환
        if (right < start || left > end)
            return 1987654321;
        //범위에 맞으면 값 반환
        if (start >= left && end <= right)
            return min_tree[pos];

        int mid = (start + end) / 2;

        return min(getMinimum(pos * 2, left, right, start, mid), getMinimum(pos * 2 + 1, left, right, mid + 1, end));
    }
};
class max_segtree
{
public:
    vector<ll> max_tree; //최댓값 저장
    int size;            //leaf 노드의 개수

    max_segtree(int N)
    {
        for (size = 1; size <= N; size *= 2)
            ;
        max_tree.resize(2 * size);
    }

    void update(int pos, ll x)
    {
        int idx = size + pos - 1;

        max_tree[idx] = x;
        while (idx /= 2)
        {
            //부모 노드 값 update
            max_tree[idx] = max(max_tree[child1], max_tree[child2]);
        }
    }

    ll getMaximum(int pos, int left, int right, int start, int end)
    {
        //left right는 찾는 범위, start end는 해당 pos 에서의 구간합 범위
        //범위에 벗어나면 0 반환
        if (right < start || left > end)
            return 0;
        //범위에 맞으면 값 반환
        if (start >= left && end <= right)
            return max_tree[pos];

        int mid = (start + end) / 2;

        return max(getMaximum(pos * 2, left, right, start, mid), getMaximum(pos * 2 + 1, left, right, mid + 1, end));
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    min_segtree MinSegment(N);
    max_segtree MaxSegment(N);

    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        MinSegment.update(i, num);
        MaxSegment.update(i, num);
    }
    for (int j = 0; j < M; j++)
    {
        cin >> a >> b;
        cout << MinSegment.getMinimum(1, a, b, 1, MinSegment.size) << ' ' << MaxSegment.getMaximum(1, a, b, 1, MaxSegment.size) << '\n';
    }
}