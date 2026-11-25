#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {

    int t; cin >> t;

    while(t --) {
        int n;
        cin >> n;
        int mem[1003];
        int team[1003];
        fill(mem, mem + 1003, 0);
        fill(team, team + 1003, 0);
        //vector<pair<int, int>> v;

        for (int i = 0; i < n; i ++) {
            cin >> mem[i]; // 순서대로 팀번호 받음
            team[mem[i]] ++; // 팀번호 인원수 체크
        }
        for (int i = 1; i <= n; i ++) {
            if(team[i] < 6) { // 팀 인원이 6명 미만이면 다 0으로
                team[i] = 0;
            }
        }
        int cnt = 0;
        int score[1003];
        fill(score, score + 1003, 0);
        for(int i = 0;i < n; i ++) {
            if(mem[i] && team[mem[i]] > 2) { // 앞에서부터 순위별 점수 부여
                cnt ++;
                team[mem[i]] -= 1;
                score[mem[i]] += cnt;
            }
        }
        int Min = 1e9;
        int res = 0;
        for(int i = 1; i <= n; i ++) {
            if(score[i] == 0) continue;
            if(Min > score[i]) {
                Min = score[i];
                res = i;
            } else if(Min == score[i]) { //점수가 같으면 5등 점수 비교
                int final[2] = {0,0};
                for(int j = 0; j < n; j ++) {
                    if(final[0] == 5) {
                        break;
                    } else if(final[1] == 5) {
                        res = i;
                        break;
                    }
                    if(mem[j] == res) {
                        final[0] ++;
                    } else if(mem[j] == i) {
                        final[1] ++;
                    }
                }
            }
        }
        cout <<"                           " << res << endl;
    }

}

/*
순서 중요? 그냥 1000짜리 배열 만들고 앞에서부터 입력받고 합이 6 안되면 거르고 되면 점수랑 같이 pair로 묶어서 벡터에 넣고..
*/