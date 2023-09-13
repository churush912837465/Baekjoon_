
#include <sstream> //split() , stringstream
#include <list>
#include <deque>
#include <map>
#include <stack>
#include<cmath> // math.pow
using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm> // sort
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N, M, Q;
const int MAX = 100001;
vector<int> vec[MAX];
int dp[MAX];
bool visit[MAX];

int dfs(int node) // ���� ��带 ���� 
{
	if (visit[node] == true)
	{
		return dp[node]; //���࿡ �湮 ������ dp�� ����Ȱ� return 
	}

	//�湮 �� ������?
	visit[node] = true; // �湮�ϸ� true

	for (int next : vec[node]) //node�� ����Ǿ� �ִ� �� Ž��
	{
		if (visit[next] != true)
		{
			dp[node] = dp[node] + dfs(next); //dp[node]�� �ʱⰪ 1
		}
	}

	//���� dp�� node��°�� ����Ǿ� �ִ°� ���
	return dp[node];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 
	cin >> N >> M >> Q;

	for (int i = 1; i < N; i++)
	{
		int s, e;
		cin >> s >> e;

		vec[s].push_back(e); //���⼺�� x
		vec[e].push_back(s); // -> �׷��� ��������� ����?
	}

	//dp�� 1�� �ʱ�ȭ
	// memset���� dp�� 1�� �ʱ�ȭ �ϸ� ������ ������� �ִ�!
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
	}

	dfs(M); //���� ���� ��带 �������� dp�� ä���
	//�Է�
	for (int i = 0; i < Q; i++)
	{
		int q;
		cin >> q;
		cout << dp[q] << '\n';
	}

}
