#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
struct Edge {
	int begin;
	int end;
};

const int Size = 7;

int main() {
	int adj_matrix[Size][Size] = { // матрица смежности
		{ 0, 1, 1, 0, 0, 0, 0 },
		{ 1, 0, 0, 1, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 1, 1 },
		{ 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0 }
	};
	bool nodes[Size]; // вершины графа
	for (int i = 0; i < Size; i++)
		nodes[i] = false; // мы не были ни в одной вершине

	queue<int> q;
	q.push(0); // с указанной вершины начинается обход

	while (!q.empty()) { // пока очередь полна
		int cur = q.front(); // выбираем первую в очереди вершину графа
		q.pop(); // убираем ее 
		nodes[cur] = true; // и отмечаем, что мы были уже там
		for (int i = 0; i < Size; i++) { // проходим заново все вершины
			if (!nodes[i] && adj_matrix[i][cur] == 1) { // если мы еще не были в этой вершине и от нее есть путь к другой, то..
				q.push(i); // ..добавляем эту вершину в очередь..
				nodes[i] = true; // ..и отмечаем, что мы посетили эту вершину
			}
		}
		cout << cur << endl; // вывод обхода графа
	}
}
