
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
#include <algorithm>
#include <string.h> //memset
#include <string> //stoi()
#include<tuple> // turple

int N;
int M;
int arr[8];
bool visited[8];

void dfs(int depth)
{
	if (depth == M)  // depth�� ++ �Ǵٰ� ������ ���̰� �Ǹ� -> arr�迭(���� ���)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	//�װ� �ƴϸ�
	for (int i = 1; i <= N; i++) // ������ �̷�� ���� �ִ°� 1 ~ N�� ��
	{
		if (!visited[i])
		{
			visited[i] = true; //�湮ó��
			arr[depth] = i; // ���� arr�迭�� �� �ֱ�
			dfs(depth + 1);
			visited[i] = false; // �ٽ� �ǵ��ƿ��� (��Ʈ��ŷ)

		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ���� 15619 -> dfs�� ��� (���� / ��Ʈ��ŷ ���)

	cin >> N >> M;
	dfs(0);

}





