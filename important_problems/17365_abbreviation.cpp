//문자열을 빠르게 탐색할 수 있는 TRIE!
#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

const long long MOD = (long long)(1e9 + 7); //나눠줄 숫자 MOD
int N, wordLen;
char word[200'002];
char temp[302];
long long DP[200'002];

class TRIE
{
public:
    long long cnt;
    TRIE *Node[26]; //26가지 알파벳에 대한 트라이

    TRIE()
    {
        memset(Node, 0, sizeof(Node));
        cnt = 0;
    }
    ~TRIE()
    {
        for (int i = 0; i < 26; i++)
            if (Node[i])
                delete Node[i];
    }
    void insert(const char *key)
    {
        if (*key == 0) //문자열의 끝이면,
        {
            return;
        }
        int curr = *key - 'a';
        if (Node[curr] == NULL) //아직 발견 못한 가지라면,
        {
            Node[curr] = new TRIE(); //새로 만들어준다!
        }
        Node[curr]->cnt += 1;        //해당 문자가 TRIE안에 몇 개 있는지 cnt에 저장!
        Node[curr]->insert(key + 1); //다음 문자로 넘어간다!

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<TRIE *> possibleWord;
    cin >> N;
    TRIE *root = new TRIE();

    for (int i = 0; i < N; i++)
    {
        cin >> temp + 1;
        root->insert(temp + 1);
    }
    cin >> word + 1;
    wordLen = strlen(word + 1);
    DP[0] = 1; //기본 설정!

    for (int i = 1; i <= wordLen; i++)
    {
        int curr = word[i] - 'a';
        possibleWord.push_back(root); //중복되는 부분에서 시간을 줄이기 위해 deque 사용!
        for (int j = 0; j < possibleWord.size(); j++)
        {
            if (possibleWord[j]) //계속 글자를 연결할 수 있는 상황이라면
            {
                possibleWord[j] = possibleWord[j]->Node[curr]; //새로운 글자까지 연결!(안된다면, NULL로!)
            }
        }
        if (possibleWord.size() > 300) //300글자 내에서만 비교하면 된다!
        {
            possibleWord.pop_front();
        }

        TRIE *here = NULL;
        int start = max(i - 300, 0);
        for (int j = start; j < i; j++) //사전의 단어들이 최대 300글자이므로
        {
            here = possibleWord[j - start]; //첫 번째 글자부터, 직전 글자까지
            if (here == NULL)               //불가능한 글자의 조합이라면, 패스!
                continue;
            DP[i] = (DP[i] + DP[j] * here->cnt) % MOD;
        }
    }
    delete root;
    cout << DP[wordLen];

    return 0;
}