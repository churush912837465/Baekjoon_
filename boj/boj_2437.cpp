
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
int arr[1001];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

void solve()
{
	// ����
	sort(arr, arr + N);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > sum + 1)
			//sum����  + 1ū�Ŵ� sum�̶� ���� (�����տ��� �ٷ� ����)�Ǿ� �־ �׷���!
			break;
		sum += arr[i];
	}

	cout << sum + 1;
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
