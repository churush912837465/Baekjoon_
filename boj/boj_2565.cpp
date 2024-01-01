
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
int dp[101];
vector<pair<int, int>> vec;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int st, en;
		cin >> st >> en;
		vec.push_back({ st, en });
	}
}

void solve()
{
	// vec�� ù���� pair�� ����
	sort(vec.begin(), vec.end());

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vec[i].second > vec[j].second)
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		answer = max(dp[i], answer);	// '�����ϴ� �κм���'�߿��� ���� ū��
	}

	cout << N - answer;
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

}
