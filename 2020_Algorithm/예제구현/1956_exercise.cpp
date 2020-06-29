//플로이디ㅡ-와샬 문제!
// 왔다-갔다 더해주는 것이 중요
#include <iostream>

const int INF = 987654321; //INF 설정
using namespace std;

int Node[401][401];
int dist[401][401]; //dist[x][y] : x->y->x 사이클의 거리 합
int V, E, a, b, c;
int minDist = INF; //최소 사이클의 합 저장

void FloydWarshall()
{
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (Node[i][k] + Node[k][j] < Node[i][j])
                    Node[i][j] = Node[i][k] + Node[k][j];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            Node[i][j] = INF;
        }
    }
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;

        Node[a][b] = c;
    }

    FloydWarshall();

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            dist[i][j] = Node[i][j] + Node[j][i]; //왔다갔다 사이클 저장!

            if (dist[i][j] < minDist)
            {
                minDist = dist[i][j];
            }
        }
    }

    if (minDist == INF) //사이클 없으면, -1 출력
        cout << -1;
    else
    {
        cout << minDist;
    }

    return 0;
}