
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
const int MAX = 101;
const int INF = 1000000000;
int pro[MAX][MAX]; //�÷��̵� ���� �迭
int weapon[MAX]; // �ش� ������ �ش�Ǵ� ���ⰹ��

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//���� 14938
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
	{
		cin >> weapon[i];
		// ������ 1~N�� ����
	}

	//���� INF ������ ä���־����
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == j)
				pro[i][j] = 1;
			else
				pro[i][j] = INF;
		}
	}

	//�Է�
	for (int i = 1; i <= R; i++)
	{
		int s, e, weight;
		cin >> s >> e >> weight;

		//����� ������ �����ϴϱ� 
		//end -> start����
		pro[s][e] = weight;
		pro[e][s] = weight;
	}


	//�÷��̵� ����
	// p : ���İ��� �߰�����
	for (int p = 1; p <= N; p++)
	{
		//i : ����
		for (int i = 1; i <= N; i++)
		{
			// j : ��
			for (int j = 1; j <= N; j++)
			{

				// i->j���� ���� ���°� vs i->p ���� p->j�� ���°� �ּڰ�
				if (pro[i][j] > pro[i][p] + pro[p][j])
				{
					pro[i][j] = pro[i][p] + pro[p][j];
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = weapon[i];  // �������� ������ �Ĺ�
		for (int j = 1; j <= N; j++)
		{
			// �� ��ΰ� �������� ���� ������
			if (pro[i][j] <= M && i != j)
			{
				cnt += weapon[j];
			}
		}
		answer = max(cnt, answer);
	}

	cout << answer;
}
