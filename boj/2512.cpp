#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int s[10004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int maxRequest = 0;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        maxRequest = max(maxRequest, s[i]);
    }

    cin >> m;

    int left = 0;
    int right = maxRequest;
    int answer = 0;
    sort(s, s + n);

    while (left <= right) {
        int mid = left + (right - left) / 2;

        long long total = 0;

        for (int i = 0; i < n; i++) {
            total += min(s[i], mid);
        }

        if (total <= m) {
            // 가능한 상한액: 저장하고 더 큰 값 탐색
            answer = mid;
            left = mid + 1;
        } else {
            // 예산 초과: 상한액 낮추기
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}