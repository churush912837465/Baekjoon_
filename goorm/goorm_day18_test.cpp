
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


int N;
int M;
const int MAX = 101;
int ud[MAX][MAX]; //  up , down�迭
int rl[MAX][MAX]; // right, left �迭
int answer[MAX][MAX];

void getUd(int _y, int _x, char co) // 1���� �����ϴ� 2���� �迭
{
	if (co == 'U') // ���� �ö󰡸� y�� ���� �۾���
	{
		while (_y > 0) // _y�� 0���� Ŭ�� 
		{
			ud[_y][_x] += 1; // 1���ϱ�
			_y--;
		}
	}

	else if (co == 'D') //�Ʒ��� �������� y�� Ŀ��
	{
		while (_y <= N) // _y�� 0���� Ŭ��
		{
			ud[_y][_x] += 1; // 1���ϱ�
			_y++;
		}
	}
}

void getRl(int _y, int _x, char co)
{
	if (co == 'L') // �������� ���� x�� �۾���
	{
		while (_x > 0) // 
		{
			rl[_y][_x] += 1; // 1���ϱ�
			_x--;
		}
	}

	else if (co == 'R') // ���������� ���� x�� Ŀ��
	{
		while (_x <= N) // 
		{
			rl[_y][_x] += 1; // 1���ϱ�
			_x++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// ����ç����
	cin >> N >> M;

	memset(ud, 0, sizeof(ud)); // 0���� �ʱ�ȭ
	memset(rl, 0, sizeof(rl));

	for (int i = 0; i < M; i++)
	{
		int y, x;
		char c;
		cin >> y >> x >> c;


		if (c == 'D' || c == 'U')
		{
			//���Ʒ� �迭��
			getUd(y, x, c);
		}
		else if (c == 'R' || c == 'L')
		{
			//�¿� �迭��
			getRl(y, x, c);
		}

	}

	//�迭 ���

	cout << "���ٿ�" << endl;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << ud[i][j] << " ";
		}
		cout << endl;
	}

	cout << "�¿�" << endl;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << rl[i][j] << " ";
		}
		cout << endl;
	}


	//answer�迭 �ۼ�
	int answer = 0;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			if (ud[i][j] != 0 && rl[i][j] != 0) // �Ѵ� ���ڰ� ������
			{
				answer += ud[i][j] * rl[i][j];
			}
		}
	}

	cout << answer;

}
