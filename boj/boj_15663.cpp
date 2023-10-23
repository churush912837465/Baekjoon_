
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

int N, M;

int arr[10];
bool visit[10];
int input[10];

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	//�ߺ��Ǵ� ������ ��������?
	int last = 0;

	for (int i = 1; i <= N; i++)
	{
		if (input[i] != last && !visit[i]) // �ߺ��Ǹ� �ȵǰ� , �湮�� �� ���� ��                            
		{
			visit[i] = true;
			arr[cnt] = input[i];
			last = arr[cnt];
			dfs(cnt + 1);
			visit[i] = false;

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	// ����  

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];
	}
	sort(input, input + N + 1);

	dfs(0);
}
