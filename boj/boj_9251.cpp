
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


const int MAX = 1001;
int dp[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ���� lcs
	// longest common subseqeunce : ���� x �ִ� ���� ����
	// �ڵ�� �Ȱ����� �� �ȵ��ư� ?��?

	string a, b;
	cin >> a >> b;

	int a_size = a.length();
	int b_size = b.length();

	for (int i = 1; i <= a_size; i++)
	{
		for (int j = 1; j <= b_size; j++)
		{
			if (b[i - 1] == a[j - 1]) //bù��°�� a�� i��°�� �ٸ���
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			else //������
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				// ���� ���ʿ� �ִ°� �߿� ������
			}

		}
	}

	cout << dp[a_size][b_size];


}
