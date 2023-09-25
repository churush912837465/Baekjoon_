
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

int N, M, R;
int s;

const int MAX = 20001;
const int INF = 100000001;
vector<pair<int, int>> vec[MAX];
int d[100001]; // �ִ� �Ÿ� ���̺�

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// �Ÿ� , ��� �ε��� (���� ������ �ϱ� ���ؼ� vector<�ڷ���> , greater<�ڷ���> �־���)
	pq.push({ 0 , start }); // ��� - ��� �Ÿ���  0
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = pq.top().first; //���� ��� ������ ���
		int now = pq.top().second; //���� ���
		pq.pop();

		//�̹� �ִ� ��� �̸�? (���� �Ǿ� �ִ� ��� < ���� ��� -> �ּ� ��ΰ� ���Ǿ�����)
		if (d[now] < dist)
			continue;

		for (int i = 0; i < vec[now].size(); i++) // ���� �����  ��� Ž��
		{
			int next = vec[now][i].first;
			// ���� �Ÿ� + ���� �Ǿ� �ִ� ����� �Ÿ�
			int cost = dist + vec[now][i].second; // ���ļ� ���� ����� ��� 
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

	//���� 1753

	cin >> N >> M >> s; // ��� ����, ���� ����, ���� ���
	for (int i = 0; i < M; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;

		vec[s].push_back({ e, w }); // ���� ��� -> ����� ,  ����ġ
	}

	// �ִ� �Ÿ� ���̺��� INF ������ �ʱ�ȭ 
	// �ּҰ��� ���ؾ� �ϱ� ����)
	fill(d, d + 100001, INF);

	// ���ͽ�Ʈ�� �˰��� ����
	dijkstra(s);

	for (int i = 1; i <= N; i++)
	{
		if (d[i] == INF)
			cout << "INF" << '\n';
		else
			cout << d[i] << '\n';

	}

}
