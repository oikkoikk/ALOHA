//DFS를 통한 사이클 탐지
//시간초과를 막아주는 부적
#include <cstdio>
#include <vector>

using namespace std;

int T, N;
vector<int> Team;
vector<bool> visited;  //방문한 적 있는 노드인지(사이클 탐지)
vector<bool> finished; //DFS 시작해서 제대로 끝났는지
int count;             //팀 없는 사람 카운트 (계속 줄어드는 방식으로)

void DFS(int start)
{
    if (finished[start]) //이미 탐색 끝난 애면 패스
    {
        return;
    }

    if (visited[start]) //사이클이 있으면
    {
        for (int i = Team[start]; i != start; i = Team[i]) //사이클과 관련된 애들 팀으로 묶는다
        {
            count--;
        }
        count--;

        return;
    }

    visited[start] = true;

    if (!finished[start])
    {
        DFS(Team[start]);
    }

    finished[start] = true;
    return;
}
int main()
{

    scanf("%d", &T);

    while (T--)
    {

        scanf("%d", &N);
        count = N;

        Team.clear(); //초기화 작업
        visited.clear();
        finished.clear();

        Team.resize(N + 1); //초기화 작업 222
        visited.resize(N + 1);
        finished.resize(N + 1);

        int num;
        for (int i = 1; i <= N; i++)
        {
            scanf("%d", &num);
            if (num == i) //자기 혼자 하려는 사람은 따로 저장
            {
                visited[num] = true;
                finished[num] = true; //사이클 감지 방지
                count--;
                continue;
            }
            Team[i] = num; //i가 num을 선택
        }

        for (int i = 1; i <= N; i++)
        {
            if (finished[i] == false)
                DFS(i);
        }
        printf("%d\n", count);
    }
}