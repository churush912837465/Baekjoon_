
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
int INF = 1000000000;
int arr[101][101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ���� 1389
	cin >> N >> M;

	//memset(arr, INF, sizeof(arr)); 2�����迭�� ����ϸ� ����ȵ�
	//�ʱ�迭 �Է�
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		arr[a][b] = 1;
		arr[b][a] = 1;

	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else if (i != j && arr[i][j] != 1)
			{
				arr[i][j] = INF;
			}
		}

	}

	// ��� -> ���� �ٷ� ���� ��� (vs) ��� ->�߰���� + �߰���� -> �������� ���� ���
	// �ּҺ���� arr�� ����
	//k  ���İ��� ���
	for (int k = 1; k <= N; k++)
	{
		// i ��߳��
		for (int i = 1; i <= N; i++)
		{
			// j �������
			for (int j = 1; j <= N; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	// arr�迭�� ����� ���� ���� �������
	int val = 1000000000;
	int idx = 0;

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;

		//i���� ����ؼ� ���� ��������(1���� 5����)���� ���� ���ϱ�
		for (int j = 1; j <= N; j++)
		{
			temp += arr[i][j];
		}

		if (temp < val)
		{
			val = temp;
			idx = i;
		}
	}

	cout << idx;
}
