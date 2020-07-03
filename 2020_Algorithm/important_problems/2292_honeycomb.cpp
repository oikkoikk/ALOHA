#include <iostream>

using namespace std;

int main()
{
    long long now;

    cin >> now;

    int stage = 1; //최소 이동 거리
    long long range = 1;
    long long temp = 1;

    while (1)
    {
        if (range >= now)
        {
            break;
        }
        temp = 6 * (stage);
        range += temp;

        stage++;
    }
    /* 
    1 = 1칸
    2~7 = 2칸
    8~19 = 3칸
    20~37 = 4칸
    ...
    이런 식으로 증가하는 것을 이용!
    */

    cout << stage;

    return 0;
}