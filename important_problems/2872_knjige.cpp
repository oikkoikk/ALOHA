//크로아티아 문제 (knjige : 서적)
//LDS 응용!
#include <iostream>
#include <vector>

using namespace std;

vector<int> books;
vector<int> sortedBooks;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;

        cin >> num;
        books.push_back(num);
    }

    //뒤에서부터 LDS 체크!
    int now = N; //N번 움직이면 무조건 정렬된다!

    for (int i = N - 1; i >= 0; i--)
    {
        if (books[i] == now) //내림차순으로 가면서 제자리에 맞게 있으면 '움직여야 할 횟수' 1 감소
            now--;
    }

    cout << now;
}