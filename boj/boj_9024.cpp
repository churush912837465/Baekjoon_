
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
vector<int> vec;

int nearNum()
{
	int start = 0;
	int end = vec.size() - 1;

	long long min = 9000000000000000000;	// �ּҰ� ���ϴϱ� �ִ��
	long long answer = 0;	// �ּҰ��̶� ���� ������
	while (true)
	{
		if (start >= end)	// ��������
			break;

		// �ʱ� min�� (-7 + 12)
		if (abs(R - (vec[start] + vec[end])) < min)
		{
			min = abs(R - vec[start] - vec[end]);
			answer = 0;	// �ּڰ� ���� �� �ʱ�ȭ
		}

		// min�̶� ������? (�ʱ� min ���� -7 + 12�� ����)
		if (abs(R - (vec[start] + vec[end])) == min)
			answer++;

		// start + end ���Ѱ� R���� ũ�� end--
		if (vec[start] + vec[end] > R)
			end--;
		// start + end ���Ѱ� R���� ������ start++
		else
			start++;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vec.clear();	// ���� �ʱ�ȭ
		cin >> M >> R;

		for (int i = 0; i < M; i++)
		{
			int temp;
			cin >> temp;
			vec.push_back(temp);
		}

		// ����
		sort(vec.begin(), vec.end());

		// ������ ���ϱ�
		int ans = nearNum();
		cout << ans << '\n';
	}


}
