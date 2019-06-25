/*2206�� �� �μ��� �̵��ϱ�*/
#include <iostream>
using namespace std;
int N, M;
char Map[1001][1001];
int drc[] = { -1,0,1,0,0,1,0,-1 };//�� �� �� �� Ž��

typedef struct pnt { int r, c;}pnt;
typedef struct V { int visit; bool dstchk; }V;
V visit[1000][1000];
pnt temp;

typedef struct node {
	pnt value;
	struct node* next;
}node;

typedef struct queue {
	node *front, *rear;
	int len;
	queue() {
		front = rear = NULL;
		len = 0;
	}
}queue;

void print_visit() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cout << " {" << visit[r][c].visit << ',' << visit[r][c].dstchk << "} ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void Q_push(queue *Q, pnt value) {
	node *new_node = new node;
	new_node->value = value;
	new_node->next = NULL;
	if (Q->front == NULL) { // ť�� ����� ��
		Q->front = new_node;
		Q->rear = new_node;
	}
	else {
		Q->rear->next = new_node;
		Q->rear = new_node;
	}
	Q->len++;
}

void Q_pop(queue *Q) {
	node *temp = Q->front;
	Q->front = Q->front->next;
	delete temp;
	Q->len--;
}

void BFS(int r, int c) {
	queue *Q = new queue;
	temp = { r,c };
	Q_push(Q, temp);
	visit[r][c] = { 1,false };
	while (Q->len > 0) {
		//print_visit();
		int cur_r = Q->front->value.r;
		int cur_c = Q->front->value.c;
		Q_pop(Q);
		for (int d = 0; d < 4; d++) {
			int nr = cur_r + drc[d];
			int nc = cur_c + drc[d + 4];
			if (!(nr < 0 || nc < 0 || nr >= N || nc >= M)) {
				if (visit[cur_r][cur_c].dstchk == true) {//�� ��ġ���� ���� �μ��� �����ߴ�.
					if (visit[nr][nc].visit == 0) {//���� �� ���� �湮���� ���� ��
						if (Map[nr][nc] == '0') {//���� �� ���� ���̴�.
							visit[nr][nc].visit = visit[cur_r][cur_c].visit + 1;
							visit[nr][nc].dstchk = visit[cur_r][cur_c].dstchk;
							temp = { nr,nc };
							Q_push(Q, temp);
						}
						//���⼱ �̹� ���� �μ��� �Ա� ������ ���� �� ���� ���̸� �� �� ����.
						else continue;
					}
				}
				else {//�� ��ġ���� ���� �μ��� �ʰ� �����ߴ�.
					if (!(visit[nr][nc].visit!=0 && visit[nr][nc].dstchk==false)) {
						if (Map[nr][nc] == '0') {//���� �� ���� ���̴�.
							visit[nr][nc].visit = visit[cur_r][cur_c].visit + 1;
							visit[nr][nc].dstchk = visit[cur_r][cur_c].dstchk;
							temp = { nr,nc };
							Q_push(Q, temp);
						}
						else {//���� �� ���� ���̴�.
							visit[nr][nc].visit = visit[cur_r][cur_c].visit + 1;
							visit[nr][nc].dstchk = true;//�� �μ��� �湮
							temp = { nr,nc };
							Q_push(Q, temp);
						}
					}
				}
				if (nr == N - 1 && nc == M - 1) return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int r = 0; r < N; r++) cin >> Map[r];
	BFS(0, 0);
	if (visit[N - 1][M - 1].visit == 0) cout << -1;
	else cout << visit[N - 1][M - 1].visit;
}
