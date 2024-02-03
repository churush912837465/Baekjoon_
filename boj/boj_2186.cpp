
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

int N, M, K, R, C;
const int MAX = 101;
char arr[MAX][MAX];
int dp[MAX][MAX][80];	// y, x, ��ǥ ���ĺ��� n��°�ܾ��϶� = ����
string temp;
int ans = 0;

void input()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}
	cin >> temp;
	memset(dp, -1, sizeof(dp));

}

int dy[4] = { 1, 0 , -1 , 0 };
int dx[4] = { 0, 1 , 0 , -1 };

int dfs(int y, int x, int idx)
{
	// return  ����
	// idx�� temp���̺��� �Ѿ��?
	// -> temp ���ڿ��� ���� �� �����ϱ� 
	if (idx >= temp.length())
		return 1;

	// �湮������(dp�� ���� ä���� ������)
	if (dp[y][x][idx] != -1)
		return dp[y][x][idx];

	dp[y][x][idx] = 0;	// �湮ó���� �ʱⰪ ä���
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			// k ���� ���� �� ���� �̵����� (��������)
			int ny = y + dy[i] * j;
			int nx = x + dx[i] * j;

			if (nx < 0 || ny < 0 || ny >= N || nx >= M)
				continue;
			if (arr[ny][nx] != temp[idx])	// �迭�� next�� ���� ���ڿ��� �ƴϸ�
				continue;

			dp[y][x][idx] = dp[y][x][idx] + dfs(ny, nx, idx + 1);
		}
	}
	return dp[y][x][idx];
}

void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == temp[0])
				ans = ans + dfs(i, j, 1);
		}
	}

	cout << ans;
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
