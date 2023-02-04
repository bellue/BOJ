#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int tcase;
    cin>>tcase;
    string vps;
    while (tcase--)
    {
        int ol = 1;
        cin >> vps;
        queue<int> q;
        for (int i = 0; i < vps.size(); i++)
        {
            if (vps[i] == '(')
            {
                q.push(vps[i]);
            }
            else
            {
                if (q.empty())
                {
                    ol = 0;
                    cout << "NO" << endl;
                    break;
                }
                q.pop();
            }
        }
        if (ol)
        {
            if (q.empty())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}