// https://www.acmicpc.net/problem/2240#include <iostream>#include <algorithm>
using namespace std;

#define MAX 1004

int plum[MAX][3];
int T, W;

//현재 시간 i, 이동 횟수 j, 현재 위치 k 모두를 관리할 3차원 배열 count[i][j][k]를 이용하여 세운 식은 다음과 같다.
//count[i][j][1] = max(count[i - 1][j][1], count[i - 1][j - 1][2]) + (plum[i] == 1)
//count[i][j][2] = max(count[i - 1][j - 1][1], count[i - 1][j][2]) + (plum[i] == 2)

int DP() {
    int result = 0; // 최종 결과
    int count[MAX][32][3]; // 자두 개수 세는 배열

    // 초기화
    fill(&count[0][0][0], &count[0][0][0] + MAX * 32 * 3, 0);
    
    // 초기 사례
    count[1][0][1] = plum[1][1];
    count[1][1][2] = plum[1][2];

    result = max(count[1][0][1], count[1][1][2]);

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            if (j > i) continue;
            if (j == 0) { 
                // 아래 검사시 j==0 일때, [j-1] 인덱스가 음수로 쓰이는 것을 예외처리.
                // 자두의 시작위치는 1번 나무 부터이므로, count[i][0][2]의 경우는 존재하지 않는다.
                //                                        최소 count[i][1][2] 부터 경우가 존재한다.
                count[i][j][1] = count[i - 1][j][1] + plum[i][1];
                result = max(result, count[i][j][1]);
                continue;
            }
            count[i][j][1] = max(count[i - 1][j][1], count[i - 1][j - 1][2]) + plum[i][1];
            count[i][j][2] = max(count[i - 1][j - 1][1], count[i - 1][j][2]) + plum[i][2];

            result = max(max(result, count[i][j][1]), count[i][j][2]);
        }
    }
    return result;
}

int main(void) {
    cin >> T >> W;

    for (int i = 1; i <= T; i++) {
        int num;
        cin >> num;
        plum[i][num] = 1;
    }

    cout << DP() << "\n";
    return 0;
}
