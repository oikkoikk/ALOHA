//DFS 백트래킹 문제
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20;

int N;
int power[MAX][MAX];
bool visited[MAX];
vector<int> startTeam;
vector<int> linkTeam;
long long result = 987654321;

void DFS(int now, int count)
{

    if (count == N / 2) //인원 채우면
    {
        startTeam.clear();
        linkTeam.clear();

        long long startTeamSum = 0;
        long long linkTeamSum = 0;

        for (int i = 0; i < N; i++)
        {
            if (visited[i])
            {
                startTeam.push_back(i); //DFS로 선택한 선수는 스타트 팀에!
            }
            else
            {
                linkTeam.push_back(i);
            }
        }
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                int startI = startTeam[i], startJ = startTeam[j];
                int linkI = linkTeam[i], linkJ = linkTeam[j];

                startTeamSum += power[startI][startJ] + power[startJ][startI]; //값 저장
                linkTeamSum += power[linkI][linkJ] + power[linkJ][linkI];
            }
        }
        result = min(result, abs(startTeamSum - linkTeamSum));
        return;
    }

    for (int i = now + 1; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            DFS(i, count + 1);

            visited[i] = false; //백트래킹
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> power[i][j];
        }
    }

    DFS(-1, 0); //0번 선수부터 찾을 수 있도록 -1 넘기자!

    cout << result;
}