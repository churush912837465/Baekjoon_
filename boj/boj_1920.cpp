
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


int N, M, R;
int arr[100001];
int answer[100001];

void binarySearch(int target) //�̺�Ž��
{
	int left = 0;
	int right = N - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == target)
		{
			cout << 1 << '\n';
			return;
		}

		// ���� �۴ٸ�?
		if (target < arr[mid])
		{
			right = mid - 1;
		}
		//���� ũ�ٸ�?
		else if (target > arr[mid])
		{
			left = mid + 1;
		}
	}

	//����˻����� �ȾҴٸ�
	cout << 0 << '\n';
	return;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 1920 �̺�Ž�� ���
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//�̺�Ž���� �ϱ� ���ؼ��� sort�ؾ��Ѵ�!
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		binarySearch(a);
	}



}
