
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
vector<int> vec[2001];
bool visit[2001];
bool flag = false;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		vec[s].push_back(e);
		vec[e].push_back(s);
	}
}

void dfs(int s, int d)	// ���۳�� , ���� 
{
	if (d == 5)
	{
		flag = true;
		return;
	}

	for (int i = 0; i < vec[s].size(); i++)
	{
		// ���࿡ ���� ��尡 �湮������ 1->7->1�� ���
		if (visit[vec[s][i]])
			continue;

		// ��Ʈ��ŷ �ϴ� �κ� -> ���� ��� ���� !! 
		visit[s] = true;
		dfs(vec[s][i], d + 1);		// ���� ��带 dfs�� �ֱ�
		visit[s] = false;	// �ٽ� ���ƿ��� false��
	}
}

void solve()
{
	// 0���� N ���� �ѹ��� ���ƾ���
	for (int i = 0; i < N; i++)
	{
		dfs(i, 1);
		if (flag)
		{
			cout << 1;
			return;
		}
	}
	cout << 0;

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
