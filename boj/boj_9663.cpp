
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
int _count = 0;
int board[15]; // i��°���� ���° ���� ���� �� �ִ��� 
//(���� ���� �� �ִ� ���� ��ȣ)  

bool promising(int cnt)  // ���� ���� ���ϼ� �ִ� �� 
{
	for (int i = 0; i < cnt; i++)
	{
		//���� ���̸� �ȵ� || �밢���̿��� �ȵ�
		// �� ĭ�� ���� ���� == ���� ���̰� ������ �밢���� ����
		if (board[i] == board[cnt] || cnt - i == abs(board[cnt] - board[i]))
		{
			return false;
		}
	}
	return true;
}

void nqueen(int cnt) //cnt : ���� ���° ����, 0~ N ���� 
{
	// ���� cnt�� ������ ����� ����
	if (cnt == N)
	{
		// 0���� N���� ���� ������ �ִ�!
		_count++;
		return;
	}

	//i : ���° ������ , 0 ~ N ����
	for (int i = 0; i < N; i++)
	{
		board[cnt] = i; //cnt �࿡ i��° ���� ����
		if (promising(cnt)) //cnt �࿡ ������ ������, 
		{
			nqueen(cnt + 1); //���������� �Ѿ
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
	cin >> N;
	nqueen(0);
	cout << _count;
}
