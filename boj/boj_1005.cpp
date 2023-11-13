
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
int A;
const int MAX = 1001;
int buildTIme[MAX]; // �ɸ��� �ð�
vector<int> vec[MAX]; // Ʈ��
int enterance[MAX]; // ��������
int dp[MAX];

void topologySort()
{
	queue<int> qu;
	// ���� ������ ���鼭 ���������� 0�ΰ� qu�� ����
	for (int i = 1; i <= M; i++)
	{
		if (enterance[i] == 0)
		{
			qu.push(i);
			dp[i] = buildTIme[i]; //dp�� �� �̸� �־�α�
		}
	}

	// ��� ���� ,N ��ŭ ����������
	for (int i = 1; i <= M; i++)
	{
		// ��ȯ �Ǵ� ���� ���� ��
		int x = qu.front();
		qu.pop();

		for (int i = 0; i < vec[x].size(); i++)
		{
			int next = vec[x][i]; //vector�� ���� �Ǿ��ִ� ����
			dp[next] = max(dp[next], dp[x] + buildTIme[next]); // �� �տ� ���� �Ǿ� �ִ°� +  �� �ð�
			if (--enterance[next] == 0)
				qu.push(next);
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
	while (N--)
	{
		cin >> M >> R; // ��尹��, �׽�Ʈ���̽� ����

		// �� �ʱ�ȭ
		memset(buildTIme, 0, sizeof(buildTIme));
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i <= M; i++)
			fill(vec[i].begin(), vec[i].end(), 0);


		// �ɸ��� �ð� �Է�
		for (int i = 1; i <= M; i++)
		{
			cin >> buildTIme[i]; // �ɸ��� �ð� 
		}
		// Ʈ�� ����
		for (int i = 0; i < R; i++)
		{
			int s, e;
			cin >> s >> e;
			vec[s].push_back(e);
			++enterance[e]; // �������� + 1
		}
		cin >> A; // �� ����� �� �ǹ� ��ȣ

		// ��������
		topologySort();

		cout << dp[A] << '\n';
	}

}

