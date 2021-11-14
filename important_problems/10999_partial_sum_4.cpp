//segment tree + lazy propagation
//변경 사항을 수정하는 시간 단축!
#include <iostream>
#include <vector>

#define child1 idx * 2
#define child2 idx * 2 + 1

using namespace std;
using ll = long long;

int N, M, K, num, a, b, c, d;

class segtree
{
public:
    vector<ll> tree; // 저장
    int size;        //leaf 노드의 개수
    vector<ll> lazy;

    segtree(int N)
    {
        for (size = 1; size <= N; size *= 2)
            ;
        tree.resize(2 * size, 0);
        lazy.resize(2 * size, 0);
    }

    void update(int pos, ll x)
    {
        int idx = size + pos - 1;

        tree[idx] = x;
        while (idx /= 2)
        {
            //부모 노드 값 update
            tree[idx] = tree[child1] + tree[child2];
        }
    }
    void update_range(int pos, int left, int right, int start, int end, ll diff)
    {
        //left right는 찾는 범위, start end는 해당 pos 에서의 구간합 범위
        //lazy값이 저장되어 있는지 확인
        if (lazy[pos] != 0)
        {
            //저장되어 있다면,
            //tree[pos]에 lazy값 반영
            tree[pos] += (end - start + 1) * lazy[pos];
            if (start != end)
            {
                //tree[pos]에 자식 노드가 있다면, 자식 노드의 lazy 배열에 lazy값 반영
                lazy[pos * 2] += lazy[pos];
                lazy[pos * 2 + 1] += lazy[pos];
            }
            //0으로 초기화
            lazy[pos] = 0;
        }
        //범위에 벗어나면 0 반환
        if (right < start || end < left)
            return;
        //범위에 맞으면,
        if (left <= start && end <= right)
        {
            //tree[pos]에 변화량 diff 반영
            tree[pos] += (end - start + 1) * diff;
            if (start != end)
            {
                //tree[pos]에 자식 노드가 있다면,
                //자식 노드의 lazy 배열에 diff값 반영
                lazy[pos * 2] += diff;
                lazy[pos * 2 + 1] += diff;
            }
            return;
        }

        int mid = (start + end) / 2;
        update_range(pos * 2, left, right, start, mid, diff);
        update_range(pos * 2 + 1, left, right, mid + 1, end, diff);

        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }

    ll getSum(int pos, int left, int right, int start, int end)
    {
        if (lazy[pos] != 0)
        {
            //저장되어 있다면,
            //tree[pos]에 lazy값 반영
            tree[pos] += (end - start + 1) * lazy[pos];
            if (start != end)
            {
                //tree[pos]에 자식 노드가 있다면, 자식 노드의 lazy 배열에 lazy값 반영
                lazy[pos * 2] += lazy[pos];
                lazy[pos * 2 + 1] += lazy[pos];
            }
            //0으로 초기화
            lazy[pos] = 0;
        }
        //left right는 찾는 범위, start end는 해당 pos 에서의 구간합 범위
        //범위에 벗어나면 0 반환
        if (right < start || end < left)
            return 0;
        //범위에 맞으면 값 반환
        if (left <= start && end <= right)
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
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            cin >> d;
            Segment.update_range(1, b, c, 1, Segment.size,d);
        }
        else
        {
            cout << Segment.getSum(1, b, c, 1, Segment.size) << '\n';
        }
    }
}