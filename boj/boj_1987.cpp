
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
char arr[21][21];
bool alpha[27];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int answer = 0; // �ִ� cnt�� ���ؾ���

void dfs(int y, int x, int _cnt)
{
	//ó�� 0,0,0�� �Ѿ������ ���ǹ��� �ɸ��°� ���� �ϱ����ؼ�
	if (_cnt != 0)
	{
		// �湮 �� �ε����� �Ѿ���� cnt ��
		if (alpha[arr[y][x] - 'A'])
		{
			//cout << "( " << y << "," << x << " : " << _cnt << ")" << endl;
			//max �� ���ϱ�
			if (_cnt > answer)
			{
				answer = _cnt;
			}

			//return�� ���⼭ �ؾ���
			return;
		}

	}

	for (int i = 0; i < 4; i++)
	{
		int my = y + dy[i];
		int mx = x + dx[i];

		//my , mx�� �迭�� �Ѿ���� �˻��ؾ���
		if (my < 0 || mx < 0 || mx >= M || my >= N)
			continue;

		// �������� �� �� ������
		// (F) -> D�� ����, {my,mx}�� F�϶� F -> D -> F

		if (!alpha[arr[y][x] - 'A'])
		{
			alpha[arr[y][x] - 'A'] = true; // D�� �湮ó��
			dfs(my, mx, _cnt + 1); //���� F�� �ѱ�
			alpha[arr[y][x] - 'A'] = false; // D�� ��Ʈ��ŷ , �ٽ� D���� ����� �� �פ���
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : �Լ����� ����ϰ� �ٷγ�����
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str[j];
		}
	}

	dfs(0, 0, 0);
	cout << answer;
}

