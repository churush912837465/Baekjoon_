
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
const int MAX = 10002;
int money[MAX];
int parent[MAX];
bool visit[MAX];


int getParent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getParent(parent[x]);
}
void unionParent(int x, int y)
{
	x = getParent(x);
	y = getParent(y);

	//���� �������� union
	if (money[x] >= money[y])
		parent[x] = y;
	else
		parent[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 16562
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
	{
		cin >> money[i];
	}

	//parent�� �ڱ��ڽ����� ä������ �Ѵ�
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	//�Է�, ��ġ��
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b); //��ġ��
	}

	/*
	//N�� �� ��ŭ (�л��� �� ��ŭ)
	int arr[MAX]; // �ּҰ��� ���ִ�
	for (int i = 1; i <= N; i++)
	{
		arr[i] = moneyMAX;
	}

	// �θ�� �� �ڽ��� ������ �ִ� ���� ���ؼ� �� �������� arr�� ����
	for (int i = 1; i <= N; i++)
	{
		arr[parent[i]] = min(arr[parent[i]], money[i] );
	}

	// moneyMAX �� �ƴϸ� ? -> �ּҰ��� ������ ���� �װŸ� answer�� ����
	for (int i = 1; i <= N; i++)
	{
		if (arr[i] != moneyMAX)
		{
			answer += arr[i];
		}
	}
	*/
	long long answer = 0;
	for (int i = 0; i <= N; i++)
	{
		int cur = getParent(i);
		if (!visit[cur])
		{
			answer += money[cur];
			visit[cur] = true;
		}
	}


	//������ �ִ� �� ���ϸ�
	if (answer <= R)
		cout << answer;
	else // �� ������ ������
		cout << "Oh no";
}
