
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
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;
int answer = 1;

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		// ��ȣ. ó��, ��
		cin >> M >> R >> C;
		vec.push_back({ R, C });	// �� ó��

	}
}

void solve()
{

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		int start = vec[i].first;
		int end = vec[i].second;

		if (pq.empty())
		{
			pq.push(end);
		}
		else
		{
			// ť�� �� ��� ������
			if (pq.top() > start)
				answer++;
			else
				pq.pop();

			pq.push(end);
		}

	}

	cout << answer;
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
