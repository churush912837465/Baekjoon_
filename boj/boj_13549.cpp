
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

const int MAX = 100001;
int visit[MAX];	// �ð��ʰ� �ȳ��� �湮ó��

int bfs_01(int start)
{
	// �ɸ��� �ð�, ���� �Ÿ�
	// ���� ���� �ð��� ��� �ϴ� �Ŵϱ� 
	// ���� �ð����� ���� -> �켱����ť�� �˾Ƽ� ���� ����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	visit[start] = 1;

	// next ����� ����ġ�� 0�̸� front, 1�̸� back
	while (!pq.empty())
	{
		int time = pq.top().first;	// �ɸ��� �ð�
		int now = pq.top().second;	// ���� ��ġ
		pq.pop();

		//�湮ó��
		visit[now] = 1;

		// ��ǥ �������� ���� ��
		if (now == M)
			return time;

		//0���϶�
		if (now * 2 < MAX && !visit[now * 2])
			pq.push({ time , now * 2 });

		// +1���� ��
		if (now + 1 < MAX && !visit[now + 1])
			pq.push({ time + 1 , now + 1 });

		// 1�� �� �� 
		if (now - 1 >= 0 && !visit[now - 1])
			pq.push({ time + 1 , now - 1 });
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M;
	cout << bfs_01(N);

}

