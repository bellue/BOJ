#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
        {
            sum -= s.back();
            s.pop_back();
        }
        else
        {
            s.push_back(tmp);
            sum += s.back();
        }
    }
    cout << sum << endl;

    return 0;
}