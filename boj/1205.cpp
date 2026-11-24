#include <iostream>
#include <vector>

using namespace std;

int n, p;
vector<int> v;

int main() {
    int new_score;
    cin >> n >> new_score >> p; // 기존 점수 개수, 신규 점수, 벡터 최대 사이즈
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        v.push_back(x);
    }
    int cnt = 1;

    for(int i = 0; i < v.size(); i ++) {
        if(v[i] <= new_score) { // 신규 점수가 더 높거나 같으면
            break;
        }
        cnt ++;
    }
    if(p == v.size()) {
        if(v[v.size() - 1] >= new_score) {
            cout << "-1";
        }
        else cout << cnt;
    }else {
        cout << cnt;
    }
}

/*
벡터 돌면서 새로운 점수의 등수 확인. 벡터 사이즈가 p고 맨 마지막 원소보다 새로운 점수가 작거나 같으면 -1 출력
*/