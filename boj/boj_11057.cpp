
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
const int MAX = 1001;
int dp[MAX][10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 11057

	cin >> N;

	//dp[N][M] : ���̰� N�� M���� ������
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
		//���̰� 1�� i�� ������ �� 
	}

	for (int i = 0; i <= N; i++)
	{
		dp[i][0] = 1;
		// ���̰� i�� 0���� �����¼�
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	int answer = 0;
	for (int i = 0; i <= 9; i++)
	{
		answer += dp[N][i];
	}
	cout << answer % 10007;
}
