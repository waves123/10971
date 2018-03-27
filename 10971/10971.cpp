#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> w(N, vector<int>(N, 0));
	vector<int> d(N);
	for (int i = 0; i < N; i++) {
		d[i] = i;
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}
	int min_ans = 100000000, ans = 0;
	bool isTravel = true;
	do {
		isTravel = true;
		ans = 0;
		for (int i = 0; i < N - 1; i++) {
			if (w[d[i]][d[i + 1]] != 0) {
				ans += w[d[i]][d[i + 1]];
			}
			else {
				isTravel = false;
				break;
			}
		}
		if (isTravel && w[d[N - 1]][d[0]] != 0) {
			ans += w[d[N - 1]][d[0]];
			min_ans = min(ans, min_ans);
		}
	} while (next_permutation(d.begin(), d.end()));
	cout << min_ans << endl;
}