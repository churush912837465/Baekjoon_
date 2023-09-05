
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

int N;
int M;
int arr[101][101];
int MAX = 987654321;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ���� 11404

	cin >> N >> M;

	//MAX�� 0 
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = MAX;
			}
		}
	}

	//�� �Է�
	for (int i = 0; i < M; i++)
	{
		int s, e, w;

		cin >> s >> e >> w;
		arr[s][e] = min(arr[s][e], w);
	}

	//�÷��̵� ����
	// K : �߰� ��ġ
	for (int k = 1; k <= N; k++)
	{
		// i : ������ġ
		for (int i = 1; i <= N; i++)
		{
			// j : ������ġ
			for (int j = 1; j <= N; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	//���
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == MAX)
			{
				cout << 0 << " ";
				continue;
			}
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
}
