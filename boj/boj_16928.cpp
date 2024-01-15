
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
const int MAX = 101;
int load[MAX];
bool visit[MAX];

void input()
{
	cin >> N >> M;

	// �⺻ load�� 0
	memset(load, 0, sizeof(load));
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++)
	{
		// ��ٸ� �Է�
		// ���ۺ��� �������� �� ŭ
		int s, e;
		cin >> s >> e;
		load[s] = e;
	}
	for (int i = 0; i < M; i++)
	{
		// �� �Է�
		// ���ۺ��� �������� ����
		int s, e;
		cin >> s >> e;
		load[s] = e;
	}
}

void solve()
{
	// bfs
	// ���� �ִ� ��忡�� load �� ���� ������ load���� bfs
	// ���� ������ �ֻ����� �� �� �ִ� ������ + 1 ~ ������ + 6 ���� bfs
	// ���� ���� 100�� �����ϸ� return

	// qu���� ������, ��� �����޴���
	queue<pair<int, int>> qu;
	qu.push({ 1 , 0 });	//1���� ����

	while (!qu.empty())
	{
		int now = qu.front().first;
		int cnt = qu.front().second;
		qu.pop();

		//cout << now << " / " << cnt << endl;
		// 100��° ĭ�� ����������
		if (now == 100)
		{
			cout << cnt;
			return;
		}

		visit[now] = true;
		for (int i = 1; i <= 6; i++)
		{
			int nextnode = now + i;

			if (visit[nextnode])	//�湮�� ����? �ǳʶٱ�
				continue;

			if (load[nextnode] == 0)	// �ƹ��͵� ���� ����̸�
			{
				qu.push({ nextnode , cnt + 1 });
			}
			else if (load[nextnode] != 0)	// ���� �� �� �ִ� ����̸�
			{
				qu.push({ load[nextnode], cnt + 1 });
			}
		}
	}

}


void print()
{

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
