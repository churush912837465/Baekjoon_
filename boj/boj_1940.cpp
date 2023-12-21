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

int N, M, R;
vector<int> vec;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());

	int answer = 0;
	int start = 0;
	int end = N - 1;
	while (true)
	{
		//cout << start << " / " << end << endl;
		if (start >= end)
			break;

		if (vec[start] + vec[end] == M)
		{
			start += 1; end -= 1; answer++;
		}
		else if (vec[start] + vec[end] < M)
			start += 1;
		else if (vec[start] + vec[end] > M)
			end -= 1;

	}
	cout << answer;
}

