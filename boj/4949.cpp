#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    while(1){
        vector<int> v;
        string s;
        int test=1;

        getline(cin,s);

        if(s=="."){
            break;
        }

        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='('||s[i]=='['){
                v.push_back(s[i]);
            }

			else if(s[i] == ']'){
				if(v.empty()){
					test=0;
					break;
				}
				
				else if(v.back() == '['){
					v.pop_back();
				}
				
				else if(v.back() == '('){
					test = 0;
					break;
				}
        }
        			else if(s[i] == ')'){
				if(v.empty()){
					test = 0;
					break;
				}
				
				else if(v.back() == '('){
					v.pop_back();
				}
				
				else if(v.back() == '['){
					test = 0;
					break;
				}
			}

            if(s.empty()&&test){
                cout << "yes" << endl;
            }
            else cout << "no" << endl;
    }
}
}