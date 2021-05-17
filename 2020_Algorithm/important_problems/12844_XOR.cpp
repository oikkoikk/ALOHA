//같으면 0, 다르면 1! XOR연산 (결합, 교환 가능)
//segment tree + lazy propagation!
#include <iostream>
#include <vector>

#define child1 idx * 2
#define child2 idx * 2 + 1

using namespace std;
using ll = long long;

int N, M, num, flag, i, j, k;

class Segtree
{
public:
    vector<ll> tree; // 저장
    int size;        //leaf 노드의 개수
    vector<ll> lazy;

    Segtree(int N)
    {
        for (size = 1; size <= N; size *= 2)
            ;
        tree.resize(2 * size, 0);
        lazy.resize(2 * size, 0);
    }

    void update(int pos, int num)
    {
        int idx = size + pos - 1;

        tree[idx] = num;
        while (idx /= 2)
        {
            //부모 노드 값 update
            tree[idx] = tree[child1] ^ tree[child2];
        }
    }
    void lazy_update(int idx, int left, int right, int start, int end)
    {
        if (lazy[idx] != 0)
        {
            //내려가다가 lazy가 있는 노드를 만난다면,
            //tree[idx]에 lazy값 반영
            tree[idx] ^= lazy[idx]*((end-start+1)%2);

            if (start != end)
            {
                //tree[idx]에 자식 노드가 있다면, 자식 노드의 lazy 배열에 lazy값 반영
                lazy[child1] ^= lazy[idx];
                lazy[child2] ^= lazy[idx];
            }
            //0으로 초기화
            lazy[idx] = 0;
        }
    }
    void update_range(int idx, int left, int right, int start, int end)
    {
        lazy_update(idx, left, right, start, end);
        //left right는 찾는 범위, start end는 해당 idx 에서의 구간합 범위
        //범위에 벗어나면 패스!
        if (right < start || end < left)
            return;
        //범위에 맞으면,
        if (left <= start && end <= right)
        {
            tree[idx] ^= k*((end-start+1)%2);
            if (start != end)
            {
                //tree[idx]에 자식 노드가 있다면,
                lazy[child1] ^= k;
                lazy[child2] ^= k;
            }
            return;
        }

        int mid = (start + end) / 2;
        update_range(child1, left, right, start, mid);
        update_range(child2, left, right, mid + 1, end);

        tree[idx] = tree[child1] ^ tree[child2];
    }

    ll getSum(int idx, int left, int right, int start, int end)
    {
        //left right는 찾는 범위, start end는 해당 idx 에서의 구간합 범위
        lazy_update(idx, left, right, start, end);
        //범위에 벗어나면 0 반환
        if (right < start || end < left)
            return 0;
        //범위에 맞으면 값 반환
        if (left <= start && end <= right)
            return tree[idx];

        int mid = (start + end) / 2;

        return getSum(child1, left, right, start, mid) ^ getSum(child2, left, right, mid + 1, end);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    Segtree Segment(N);
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        Segment.update(i, num);
    }
    cin >> M;

    for (int time = 0; time < M; time++)
    {
        cin >> flag >> i >> j;

        if (flag == 1)
        {
            cin >> k;
            Segment.update_range(1, i + 1, j + 1, 1, Segment.size);
        }
        else
        {
            cout << Segment.getSum(1, i + 1, j + 1, 1, Segment.size) << '\n';
        }
    }
}