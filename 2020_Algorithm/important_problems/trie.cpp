//문자열을 빠르게 탐색할 수 있는 TRIE!
#include <iostream>
#include <cstring>

using namespace std;

class TRIE

{
public:
    bool finish;    //문자열이 끝나는 지점에 finish = true!
    TRIE *Node[26]; //26가지 알파벳에 대한 트라이

    TRIE() : finish(false)
    {
        memset(Node, 0, sizeof(Node));
    }
    ~TRIE()
    {
        for (int i = 0; i < 26; i++)
            if (Node[i])
                delete Node[i];
    }
    void insert(const char *key)
    {
        if (*key == NULL)  //NULL이면
            finish = true; //문자열이 끝나는 지점일 경우 표시
        else
        {
            int curr = *key - 'A';  //현재 문자를 정수로 변환
            if (Node[curr] == NULL) //현재 연결된 노드가 없으면, 새로 만들어 준다!
            {
                Node[curr] = new TRIE();
            }
            Node[curr]->insert(key + 1); //연결된 것이 있다면, 다음 문자 확인
        }
    }
    TRIE *find(const char *key)
    {
        if (*key == NULL)
        {
            if (finish == true)
                return this; //문자열이 끝나는 위치를 반환
            else
                return NULL;
        }

        int curr = *key - 'A';
        if (Node[curr] == NULL)
            return NULL;                  //찾는 값이 존재하지 않음
        return Node[curr]->find(key + 1); //다음 문자를 탐색
    }
};