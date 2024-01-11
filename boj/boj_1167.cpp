
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
vector<pair<int, int  >> vec[100001];
int dis;
int u;	// ������ �� �� 0 �� ���� �� ��� u
bool visit[100001];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int s, e, d;
		cin >> s;

		while (true)
		{
			cin >> e;
			if (e == -1)
				break;
			cin >> d;

			vec[s].push_back({ e , d });	// ����� ���, ����ġ
		}
	}
}

void dfs(int s, int w)	// ������, ����ġ 
{

	if (visit[s])	// �����, ������尡 �湮������ 
		return;

	visit[s] = true;

	// �Ź� ����� �� ���� dis �ʱ�ȭ -> ����
	// ���� ����϶��� ����ص� ���� ������? -> ����
	if (vec[s].size() == 1)
	{
		if (dis <= w)
		{
			u = s;
			dis = w;	// �� ū w�� ������
		}
	}

	for (int i = 0; i < vec[s].size(); i++)
	{
		int next = vec[s][i].first;
		int nextDis = vec[s][i].second;

		dfs(next, w + nextDis);
	}


}


void solve()
{
	// 1. ������ �� ��A�� ��Ƽ� ���� �ָ��ִ� ���B�� ã��
	// 2. ��ȯ�� ���B�� �������� ���� �ָ��ִ� ���C�� ã��
	// 3. B�� C�� �Ÿ��� Ʈ���� ����

	dfs(1, 0);	// ������ ���� ( ���⼭�� 1�� ���� ), ����ġ�� ó������ 0
	//1�� ����� ���� �ָ� �ִ� ��� u�� ����
	//cout << "u : " << u << endl;

	dis = 0;	//�Ÿ��� ��Ƴ���
	memset(visit, false, sizeof(visit));	// visit �ʱ�ȭ

	dfs(u, 0);
	cout << dis;
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
