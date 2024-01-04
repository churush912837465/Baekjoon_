
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
const int INF = 987654321;
int arr[3];
int dp1[2][3], dp2[2][3];

void input()
{

}

void solve()
{
	// dp�迭�� �� �����ϸ� �޸��ʰ���
	// -> �Է¹޴� ���ÿ� ����ؾ���

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2];

		// �ʱⰪ ä���
		if (i == 1)
		{
			dp1[0][0] = arr[0];
			dp1[0][1] = arr[1];
			dp1[0][2] = arr[2];

			dp2[0][0] = arr[0];
			dp2[0][1] = arr[1];
			dp2[0][2] = arr[2];
			continue;
		}

		// �ִ� 
		dp1[1][0] = max(dp1[0][0], dp1[0][1]) + arr[0];
		dp1[1][1] = max(dp1[0][0], max(dp1[0][1], dp1[0][2])) + arr[1];
		dp1[1][2] = max(dp1[0][1], dp1[0][2]) + arr[2];

		// �ּڰ�
		dp2[1][0] = min(dp2[0][0], dp2[0][1]) + arr[0];
		dp2[1][1] = min(dp2[0][0], min(dp2[0][1], dp2[0][2])) + arr[1];
		dp2[1][2] = min(dp2[0][1], dp2[0][2]) + arr[2];

		// dp1 , dp2 �� 1��° ���� ���� ���� 2��° ���� �� �ֱ�
		for (int i = 0; i < 3; i++)
		{
			dp1[0][i] = dp1[1][i];
			dp2[0][i] = dp2[1][i];
		}
	}

	//�ִ�, �ּڰ� ���ϱ�
	int maxN, minN;
	maxN = max(dp1[0][0], max(dp1[0][1], dp1[0][2]));
	minN = min(dp2[0][0], min(dp2[0][1], dp2[0][2]));

	cout << maxN << " " << minN;
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

}
