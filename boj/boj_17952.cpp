
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
stack<pair<int, int>> st;

void input()
{
	cin >> N;
}

void solve()
{
	int answer = 0;
	stack<pair<int, int>> st;

	for (int i = 0; i < N; i++)
	{
		int is;
		cin >> is;

		if (is == 1)	// 1�϶� �Է�, 0�̸� �н�
		{
			int a, b;
			cin >> a >> b;
			st.push({ a, b });	//����, �ҿ�ð�
		}
		if (!st.empty())
		{
			st.top().second--; // ó���� �Էµ� �ҿ�ð� --
			if (st.top().second == 0)	// �ҿ�ð��� 0�̸�
			{
				answer += st.top().first; // �������ϱ�
				st.pop();
			}
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
