
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

int N, M;
const int MAX = 501;
char arr[MAX][MAX];
bool visit[MAX][MAX];
bool dp[MAX][MAX];

bool dfs(int y, int x)
{
	char co = arr[y][x]; // command

	if (visit[y][x]) //�湮������
	{
		return dp[y][x];
		// dp���� �湮�Ҽ������� true,�湮���ϸ� false
	}

	visit[y][x] = true; //�湮������ true
	int ny = y;
	int nx = x;

	if (co == 'U')
	{
		ny -= 1;
	}
	else if (co == 'D')
	{
		ny += 1;
	}
	else if (co == 'R')
	{
		nx += 1;
	}
	else if (co == 'L')
	{
		nx -= 1;
	}

	//������ �Ѿ�� true����
	if (nx < 0 || ny < 0 || ny >= N || nx >= M)
	{
		dp[y][x] = true; // �湮ó��
		return true;
	}

	return dp[y][x] = dfs(ny, nx);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 17090
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//�湮 �������� dfs�ϱ�
			if (!visit[i][j])
			{
				dfs(i, j);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dp[i][j] == true)
			{
				answer++;
			}
		}
	}
	cout << answer;
}
