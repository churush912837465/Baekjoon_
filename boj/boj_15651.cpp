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
int arr[9];
bool visit[9];
void dfs(int cnt) // num : �� �� ���ٴ� Ŀ���� , cnt : arr�ȿ� ä���� ���� ����
{
	if (cnt == M)
	{
		//M-1���� arr ���
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;

	}

	for (int i = 1; i <= N; i++) // num ���ٴ� Ŀ���� 
	{
		//visit[i] = true;
		arr[cnt] = i;
		dfs(cnt + 1);
		//visit[i] = false;
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
	dfs(0);


}
