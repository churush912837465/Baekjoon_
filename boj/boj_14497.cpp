
// �ȵǴ� Ǯ��
/*
int N, M, R;
int mx, my, by, bx;
const int MAX = 301;
char arr[MAX][MAX];


int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0 ,1, 0, -1 };

bool flag = false;

void bfs(int _y, int _x)
{
	bool visit[MAX][MAX];
	memset(visit, false, sizeof(visit));	//visit �ʱ�ȭ

	queue<pair<int, int>> q;
	q.push({ _y, _x });
	visit[_y][_x] = true;

	while (!q.empty())
	{
		int cY = q.front().first;
		int cX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = cY + dy[i];
			int nextX = cX + dx[i];

			// ���� ���� ĭ���� �����ϸ�?
			if (arr[nextY][nextX] == '#')
			{
				flag = true;
				return;
			}

			if (nextY < 1 || nextX < 1 || nextY > N || nextX > M)
				continue;

			if (visit[nextY][nextX] == true)
				continue;

			// �װ� �ƴϸ� 
			// �湮ó��
			visit[nextY][nextX] = true;

			// ���� ��ǥ�� 1�̸� > 0���� �ٲٱ�
			if (arr[nextY][nextX] == '1')
				arr[nextY][nextX] = '0';

			// ���� ��ǥ�� 0�̸� > ť�� �ֱ� (������ ��� ����
			else if (arr[nextY][nextX] == '0')
				q.push({ nextY, nextX });
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// exit(0) : ���α׷��� ����
	// return : �Լ� �ȿ��� ����ϸ�, �� �Լ��� ��� �����ϰ� �Լ��� ȣ���� ������ jump ��
	// typeid(x).name() : �ڷ��� ���

	cin >> N >> M;
	cin >> mx >> my >> by >> bx;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
	}
	int answer = 0;
	while (true)
	{
		answer++;	// �ѹ� �����ϰ�, ����(bfs)������
		bfs(my, mx);
		if (flag)	// �����ϸ� 
			break;
	}
	cout << answer;
}

*/

// ���� �ȵǴ��� �𸣰��� 
// �Ǵ�Ǯ��
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, x_1, y_1, x_2, y_2, y, x, ny, nx, ret;
bool ok = false;
char graph[304][304];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int sy, int sx) {
	bool visited[304][304];
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		y = q.front().first; x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			ny = y + dy[d];
			nx = x + dx[d];
			if (graph[ny][nx] == '#') {
				ok = true;
				return;
			}
			if (ny >= 1 and ny <= N and nx >= 1 and nx <= M and !visited[ny][nx]) {
				visited[ny][nx] = true;
				if (graph[ny][nx] == '1') graph[ny][nx] = '0';
				else if (graph[ny][nx] == '0') q.push({ ny,nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> x_1 >> y_1 >> x_2 >> y_2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> graph[i][j];
	}
	while (1) {
		ret++;
		bfs(x_1, y_1);
		if (ok) break;
	}
	cout << ret;
}

