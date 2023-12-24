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
const int MAX = 100001;
int arr[MAX];
vector<int> vec;

int lowerBound(int num)
{
	int start = 0;
	int end = vec.size() - 1;
	int mid;
	while (true)
	{
		mid = (start + end) / 2;
		if (start >= end)
			break;
		if (vec[mid] > num)
			end = mid;
		else if (vec[mid] < num)
			start = mid + 1;
	}
	return end;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N;
	//LIS�� �������� N ����ŭ ����
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		// ���Ͱ� ��������� �׳� �ִ´�
		if (vec.size() == 0)
			vec.push_back(num);

		// arr�� ���� vec�� ������ ������ ������
		// -> lower bound�� �ڸ��� �־��ش�
		else if (num < vec[vec.size() - 1])
		{
			int lower = lowerBound(num);	// lower_bound() �Լ��� ������ ���� ���� �غ���
			vec[lower] = num;
		}

		// vec�� ������ ������ �� ũ�� 
		// -> �׳� �ڿ� �߰�
		else if (num >= vec[vec.size() - 1])
			vec.push_back(num);
	}

	cout << N - vec.size();
}
