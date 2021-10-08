# include <iostream>
# include <stack>
# include <vector>
using namespace std;

//stack: 후입선출의 자료구조
//그래프는 https://upload.wikimedia.org/wikipedia/commons/thumb/7/7f/Depth-First-Search.gif/330px-Depth-First-Search.gif 의 이미지 활용. 
// 출처: https://ko.wikipedia.org/wiki/%EA%B9%8A%EC%9D%B4_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89
//참고: https://doing-nothing.tistory.com/48




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
stack<int> s;

void dfs(int start) {
	int current = start;
	s.push(current);
	visited[current] = true;
	while (s.size() != 0) {
		current = s.top();
		
		cout << current << "\n";
		s.pop();
		for (int i = 0; i < 10; i++) {
			if (adjacent[current][i] != 0 && !visited[i]) {
				current = i;
				s.push(current);
				visited[current] = true;
			}
		}
	}
}


	

int main() {

	
	visited = vector<bool>(adjacent.size(), false);
	for (int i = 0; i < adjacent.size(); i++) {
		if (!visited[i]) dfs(i);
	}

	return 0;

}