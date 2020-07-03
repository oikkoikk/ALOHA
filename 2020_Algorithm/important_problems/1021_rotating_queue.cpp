#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main()
{
    int count = 0;
    deque<int> myDeque;
    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        myDeque.push_back(i);
    for (int i = 0; i < M; ++i)
    {
        int num;
        int index;

        cin >> num;
        for (int i = 0; i < myDeque.size(); ++i)
        {
            if (myDeque[i] == num)
            {
                index = i; //위치 찾기
                break;
            }
        }
        if (index < myDeque.size() - index) //전반부에 있을 때
        {
            while (true)
            {
                if (myDeque.front() == num)
                {
                    myDeque.pop_front();
                    break;
                }
                ++count;
                myDeque.push_back(myDeque.front()); //2번 연산
                myDeque.pop_front();
            }
        }
        else //후반부에 있을 때
        {
            while (true)
            {
                if (myDeque.front() == num)
                {
                    myDeque.pop_front();
                    break;
                }
                ++count;
                myDeque.push_front(myDeque.back()); //3번 연산
                myDeque.pop_back();
            }
        }
    }
    cout << count;
}