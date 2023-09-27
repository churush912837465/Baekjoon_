
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

int N, M, S;
const int MAX = 10001;
const int INF = 100000000;
int d[MAX];
vector<pair<int, int>> vec[MAX];
int cnt;
int answer;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // ����� �Ÿ� , ��忡
	pq.push({ 0 , start });
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[now].size(); i++)
		{
			int next = vec[now][i].first; // ���� ��忡 ����� �������
			int cost = dist + vec[now][i].second; // ���� ������ ���� ���

			if (cost < d[next])
			{
				d[next] = cost;
				pq.push({ cost, next });
			}

		}

	}

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����

	//���� 10282

	cin >> N;
	for (int i = 0; i < N; i++)
	{

		//d�迭�� INF�� ä���
		fill(d, d + MAX, INF);
		cnt = 0;
		answer = 0;

		int n, dd, c; // ��� ����, ���� ����, ������ ���
		int a, b, s; // ����, ������� , ����ġ
		cin >> n >> dd >> c;

		for (int j = 0; j < dd; j++)
		{
			cin >> a >> b >> s;

			vec[b].push_back({ a , s });
		}

		//���ͽ�Ʈ�� ����
		dijkstra(c);

		// �ּڰ� �迭�� ����� �� �߿� ����ū�� -> ���� �ָ� �ִ� ��ǻ�� (������ ��ǻ��)
		for (int i = 1; i <= n; i++)
		{
			if (d[i] == INF)
				continue;

			cnt++;
			if (d[i] > answer)
			{
				answer = d[i];
			}
		}

		cout << cnt << " " << answer << '\n';

		// ���� �ʱ�ȭ
		for (int i = 0; i < MAX; i++) {
			vec[i].clear();
		}

	}



}
