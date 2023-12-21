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
const int MAX = 3000001;

int arr[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M >> R >> C; // ���ü�, �ʹ� ������, ���� ���ü�, ���� 
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0;
	int end = R - 1;
	unordered_map<int, int> ma;
	int answer = 0;

	for (int i = 0; i < R - 1; i++)
		ma[arr[i]]++;	// ó�� ���� ���ü� -1 ���� �־����

	// ȸ���ʹ��̿��� �ѹ���
	for (int i = 0; i < N; i++)
	{
		end %= N;

		cout << start << " / " << end << endl;

		//start�� end�� ��� ����
		ma[arr[end]]++;		// ������ �ϳ� �þ�� end �κ� ���ڰ� �ϳ��� 
		ma[arr[start]]--;	// ������ �ϳ� �پ��� start�κ� ���� ������

		int s = ma.size();
		// map�ȿ� ������ ���ٸ� ?
		// ������ + 1 ( map�� ����ִ� �ʹ��� ���� + �������� �ʹ�����(1) )
		if (ma.find(C) == ma.end())
			answer = max(answer, s + 1);
		else
			answer = max(answer, s);

		// ������ �ϳ� �پ�� ��, �ش� ���ڰ� map�� ������
		// map���� �����
		if (ma[arr[start]] == 0)
			ma.erase(ma.find(arr[start]));

		start++;
		end++;

	}

	cout << answer;

}
