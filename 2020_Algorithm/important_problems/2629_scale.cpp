#include <iostream>

using namespace std;
const int MAX = 30;

int N, M;
int weight[MAX];
int bead[7];
bool visited[MAX + 1][MAX * 500 + 1];

void onScale(int cnt, int result)
{
    if (cnt > N)
        return;
    if (visited[cnt][result] == true)//이미 잴 수 있는 무게로 판명되면 패스!
        return;

    visited[cnt][result] = true;
    //3가지 선택지
    onScale(cnt + 1, result + weight[cnt]); //또 다른 추를 올려서 잰다!
    onScale(cnt + 1, result); //자기 자신만으로 만들 수 있는 무게 기록
    onScale(cnt + 1, abs(result - weight[cnt])); //저울 반대편에 다른 추를 올려서 잰다!
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> bead[i];
    }

    onScale(0, 0);

    for (int i = 0; i < M; i++)
    {
        if (visited[N][bead[i]] == true) //구슬의 무게를 쟀다면 Y!
            cout << "Y ";
        else
            cout << "N ";
    }
    cout << '\n';
    return 0;
}