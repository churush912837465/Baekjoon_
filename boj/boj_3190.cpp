
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
//#include<cmath> // math.pow
using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> // sort
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple
#include<unordered_map>

int N, M, R, C;
int arr[101][101];
queue<pair<int, char>> dir;
int answer = 0;


int dirIdx = 1; // ���� 0 ��, 1 ����, 2 �Ʒ� , 3 ��  
int dx[4] = { 0 , 1 , 0 , -1 };
int dy[4] = { -1 , 0 , 1 , 0 };


void input()
{
    cin >> N;    // N X N
    cin >> M;    // ��� ��ġ
    for (int i = 0; i < M; i++)
    {
        int ay, ax;
        cin >> ay >> ax;

        arr[ay][ax] = -1;    // ����� -1
    }
    cin >> R;
    for (int i = 0; i < R; i++)
    {
        int t;
        char d;
        cin >> t >> d;
        dir.push({ t, d });    // �ð�, ����
    }
}

void solve()
{
    // arr �� -1�� ��� , 1�� ��
    deque<pair<int, int>> dq; // ���� ��ǥ�� ��Ƴ���
    dq.push_back({ 1,1 });    // ó������ 1,1�� ����
    arr[1][1] = 1;  // ù���� ĭ�� ��

    // dq
    // (front, ���� ) 0 0 0 0 0 (back, �Ӹ�)

    while (true)
    {
        answer++;   // �� ���ʰ� ��������

        int nextY = dq.back().first + dy[dirIdx];  // dirInx���� '��,�Ʒ�,��,��' �ε���
        int nextX = dq.back().second + dx[dirIdx];

        // ���� ���� ��ǥ�� ������ �Ѿ��?
        if (nextY <= 0 || nextX <= 0 || nextY > N || nextX > N)
            return;

        // ���� ��ǥ�� �����̸� ? -> �Ӹ��� ������ ������ �ȵ�
        if (arr[nextY][nextX] == 1)
            return;

        // 1. ���� ��ǥ�� ����� �ƴϸ�?
        if (arr[nextY][nextX] != -1)
        {
            arr[dq.front().first][dq.front().second] = 0;   // .���� �κ� ��ǥ�� 0����
            dq.pop_front();  // ���� ��ǥ ����
        }

        // 2. ���� ��ǥ�� ����̸�?
        // ���� front�� next ��ǥ �߰�
        // ���� ������ �������� ����

        // �Ʒ� ������ 1�� , 2�� �� �����ϴ� �ڵ���
        arr[nextY][nextX] = 1; // ������ǥ�� �� �Ӹ��� ���� -> 1�� ä�� (�湮ó���� ����)
        dq.push_back({ nextY, nextX });

        // answer �� �����ʰ� dir ������ �ٲ�� �ϴ� �ð��ʶ� ���� ��
        // -> ������ �ٲ����
        if (answer == dir.front().first)
        {
            char ch = dir.front().second;   // ����� ��������
            if (ch == 'D')  // ����ȸ��
                dirIdx = (dirIdx + 1) % 4;
            else    // ����ȸ��
                dirIdx = (dirIdx + 3) % 4;

            dir.pop();
        }

    }
}

void print()
{
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // exit(0) : ���α׷��� ����
    // return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
    // typeid(x).name() : �ڷ��� ���

    input();
    solve();
    print();
}
