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
	int adj_matrix[Size][Size] = { // ������� ���������
		{ 0, 1, 1, 0, 0, 0, 0 },
		{ 1, 0, 0, 1, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 1, 1 },
		{ 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0, 0 }
	};
	bool nodes[Size]; // ������� �����
	for (int i = 0; i < Size; i++)
		nodes[i] = false; // �� �� ���� �� � ����� �������

	queue<int> q;
	q.push(0); // � ��������� ������� ���������� �����

	while (!q.empty()) { // ���� ������� �����
		int cur = q.front(); // �������� ������ � ������� ������� �����
		q.pop(); // ������� �� 
		nodes[cur] = true; // � ��������, ��� �� ���� ��� ���
		for (int i = 0; i < Size; i++) { // �������� ������ ��� �������
			if (!nodes[i] && adj_matrix[i][cur] == 1) { // ���� �� ��� �� ���� � ���� ������� � �� ��� ���� ���� � ������, ��..
				q.push(i); // ..��������� ��� ������� � �������..
				nodes[i] = true; // ..� ��������, ��� �� �������� ��� �������
			}
		}
		cout << cur << endl; // ����� ������ �����
	}
}
