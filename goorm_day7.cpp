
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
#include <algorithm>
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N;
int M;
int arr[1001][1001];
int answer = 0;

int dx[] = { 0,1,1,1,0,-1,-1,-1 }; //7���� ��ǥ
int dy[] = { 1,1,0,-1,-1,-1,0,1 };

int check(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		int mx = x + dx[i];
		int my = y + dy[i];

		if (mx < 0 || my < 0 || mx >= N || my >= N) //��ǥ�� ����� ������ 
		{
			continue;
		}

		if (arr[mx][my] == 1) // �ֺ��� ĭ�� ���� (1)�̸�
		{
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ����ç���� 7
	cin >> N >> M;
	//�Է�
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[j][i];
		}
	}
	//2��for���� �����鼭 ����(1)�� �ƴѰ��� �Լ�����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[j][i] != 1)
			{
				int n = check(j, i);
				if (n == M)
				{
					answer++;
				}
			}
		}
	}
	cout << answer;

}






