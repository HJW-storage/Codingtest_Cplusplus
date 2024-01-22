//https://www.acmicpc.net/problem/13913

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define prev aaa
#define next aaaa
const int max_n = 200004;
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;

int main() {
    vector<int> v;
    queue<int> q;
    cin >> n >> k;
    visited[n] = 1; // 规巩贸府
    q.push(n);
    while (q.size()) {
        here = q.front();
        q.pop();
        if (here == k) {
            ret = visited[k];
            break;
        }

        for (int next : {here + 1, here - 1, 2 * here}) {
            if ((next >= 0 && next < max_n) && visited[next] == 0) {
                visited[next] = visited[here] + 1;  // 弥家 芭府 棺 规巩 贸府
                prev[next] = here;  // 版肺 眠利
                q.push(next);
            }
        }
    }
    
    for (int i = k; i != n; i = prev[i]) {
        v.push_back(i);
    }
    v.push_back(n);

    cout << ret - 1 << '\n';
    reverse(v.begin(), v.end());
    for (int i : v) cout << i << ' ';
    return 0;
}