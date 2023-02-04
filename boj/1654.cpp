#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> v;
int ans;

int main(){
    int k; cin >> k;
    int n; cin >> n;
    for( int i = 0; i < k; i ++ ){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end()); 

    //�̺�Ž�� ���� (�ð����⵵ log n)
    int left = 1, right = v[0], mid;
	
	while (left <= right)
	{
		// mid ����
		mid = (left + right) / 2;
        
		// ���� ���� �����ϴ� ����
		int now = 0; 
        
		for (int i = 0; i < k; i++)
		{
			//mid�� ���� ���� ����
			now += v[i] / mid;
		}

		if (now >= n)
		{
			// ���� mid�� ���� ���� N���� ũ�ų� ���ٸ�,
			// left�� ������ ���̰� �� �� ���� �������� �˻�
			left = mid + 1;
            
			// N���� ���� �� ���� ��, ���� �� ū ������ ��� ����
			ans = max(ans,mid);
		}
		else
		{
			// ���� mid�� ���� ���� N���� �۴ٸ�,
			// right ������ ���̰� �� ª�� ���� �������� �˻�
			right = mid - 1;
		}
	}
	
	cout << ans << '\n';
    //�̺�Ž�� ��
}