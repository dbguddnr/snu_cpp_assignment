# include <iostream>
# include <queue>
# include <vector>
using namespace std;

//stack: ���Լ����� �ڷᱸ��
//�׷����� https://upload.wikimedia.org/wikipedia/commons/thumb/7/7f/Depth-First-Search.gif/330px-Depth-First-Search.gif �� �̹��� Ȱ��. 
// ��ó: https://ko.wikipedia.org/wiki/%EA%B9%8A%EC%9D%B4_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89
//����: https://doing-nothing.tistory.com/48




vector<vector<int>> adjacent = {
	{0,1,0,0,1,0,0,0,1,0},
	{1,0,1,0,0,0,0,0,0,0},
	{0,1,0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{1,0,0,0,0,1,0,1,0,0},
	{0,0,0,0,1,0,1,0,0,0},
	{0,0,0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0},
	{1,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,1,0},
};

vector<bool> visited(10, false);
queue<int> q;

void bfs(int start) {
	int current = start;
	q.push(current);
	visited[current] = true;
	while (q.size() != 0) {
		current = q.front();
		q.pop();
		cout << current << "\n";
		
		for (int i = 0; i < 10; i++) {
			if (adjacent[current][i] != 0 && !visited[i]) {
				
				q.push(i);
				visited[i] = true;
			}
		}
	}
}




int main() {


	visited = vector<bool>(adjacent.size(), false);
	for (int i = 0; i < adjacent.size(); i++) {
		if (!visited[i]) bfs(i);
	}

	return 0;

}