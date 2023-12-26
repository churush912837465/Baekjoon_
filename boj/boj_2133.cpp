
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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	int dp[31];
	cin >> N;

	if (N % 2 != 0)
	{
		cout << 0;
		exit(0);
	}

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 4; i <= N; i += 2)	// 2�� Ŀ�� 
	{
		// i�� 6�϶� 
		// dp[6] = dp[4] * dp[2]
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 2; j -= 2)
		{
			// dp[6] = dp[4] * 2 
			dp[i] += dp[j] * 2;
		}
		dp[i] += 2;	// Ư����� 2
	}
	cout << dp[N];

}
