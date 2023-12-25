
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
vector<int> vec;	//LIS�� ��� ����
int arr[40010];

int lowerBound(int n)
{
	int start = 0;
	int end = vec.size() - 1;

	while (true)	// start�� end ���� Ŀ���� ���� 
	{
		int mid = (start + end) / 2;

		if (start >= end)
			break;

		if (vec[mid] > n)
			end = mid;
		else if (mid < n)
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

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		int temp;
		temp = arr[i];

		// vec�� ������� �� �׳� �߰�
		if (vec.size() == 0)
			vec.push_back(temp);
		// ������ �� ���� temp�� �� ũ�� , �׳� �߰�
		else if (vec[vec.size() - 1] < temp)
			vec.push_back(temp);
		// ������ �� ���� temp�� �� ������ , lower bound�� �߰�
		else if (vec[vec.size() - 1] >= temp)
		{
			//int lo = lowerBound(temp); 
			// ���� lowerBound�� ���ϴ°͵� ����!
			int lo = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();	//temp�� lower bound�� ����
			// lower_bound�� ��ȯ���� iterator �̿��� , vec�� ù��° �ּҰ��� �� �����?
			vec[lo] = temp;
		}
	}

	cout << vec.size();

}
