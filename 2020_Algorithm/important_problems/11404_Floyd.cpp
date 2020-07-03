//플로이드-와샬 알고리즘
//모든 정점 (i에서 j까지)의 최단거리를 다 구할 수 있음
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;
const int MAX_NUMBER = 101;
long long Node[MAX_NUMBER][MAX_NUMBER]; //노드 연결 확인 + 최단거리 저장
int N,M,a,b,c;

void FloydWarshall()
{
    for(int k= 1; k <= N; k++) //k번 노드를 거칠 때
    {
        for(int i=1; i<=N; i++) //i에서
        {
            for(int j=1; j<=N; j++) //j까지
            {
                Node[i][j] = min(Node[i][j], (Node[i][k] + Node[k][j]));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=1; i<= N; i++)
    {
        for(int j=1; j<= N; j++)
        {
            if( i == j)
                Node[i][j] = 0; //자기 자신으로 가는 거리 = 0
            else
                Node[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++)
    {
        cin >> a >> b >> c;
        Node[a][b] = min(Node[a][b], (long long)c);
    }

    FloydWarshall();

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(Node[i][j] == INF)
            {
                Node[i][j] = 0;
            }
            cout << Node[i][j] << ' ';
        }
        cout << '\n';
    }
}