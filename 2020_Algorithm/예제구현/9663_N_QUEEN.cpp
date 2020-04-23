//백트래킹(DFS)
//같은 열, 같은 대각선 상에 퀸이 있으면 안 된다!(깊이를 기준으로 탐색하므로 같은 행에 있을 가능성은 없다)
#include <iostream>
using namespace std;

int N;
const int MAX = 15;
int solution [MAX];
int ans = 0;

bool isOK(int depth)
{
    for(int i=0; i<depth; i++)
    {
        if(solution[depth] == solution[i]) //열 확인
            return false;
        
        else if(solution[i]+i == solution[depth]+depth) //대각선 확인 x+y = k
            return false;
        else if(i - solution[i] == depth - solution[depth]) //대각선 확인 x-y = k
            return false;
    }
    return true;
}
int Backtracking(int depth)
{

    if (depth == N)
    {
        ans ++;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        solution[depth] = i; // i는 열! i는 열!
        if(isOK(depth)) //다음 깊이에서의 선택이 가능하다면
            Backtracking(depth+1);
    }
    return 0;
}
int main()
{
    cin  >> N;

    Backtracking(0);

    cout << ans;
}