
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

int N, M, R;
const int MAX = 501;
vector<int> vec[MAX];
int dp[MAX];
int enterance[MAX];
int cost[MAX];

void topologysort()
{
	queue<int> qu;

	// ���� ������ 0 �ΰ� �ֱ�
	for (int i = 1; i <= N; i++)
	{
		if (enterance[i] == 0)
		{
			qu.push(i);
			dp[i] = cost[i];

		}
	}

	// ��������, N��
	for (int i = 1; i <= N; i++)
	{
		int x = qu.front();
		qu.pop();

		for (int i = 0; i < vec[x].size(); i++)
		{
			int next = vec[x][i];
			enterance[next]--;

			dp[next] = max(dp[next], dp[x] + cost[next]);
			if (enterance[next] == 0)
			{
				qu.push(next);
			}

		}

	}

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		while (true)
		{
			int e;
			cin >> e;
			if (e == -1)
				break;

			vec[e].push_back(i);
			enterance[i]++;
		}
	}

	// ��������
	topologysort();

	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << "\n";
	}

}

