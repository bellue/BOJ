#include <iostream>

using namespace std; //std ?��?���??��
namespace myspace
{
    int n=100;
}

int main()
{
    int n;
    char c;

    //std::cin >>n;     //n ?��?��받는 ?��?��
    std::cout << "Hello"<<endl<<"World!" << std::endl;
    std::cout<<1<<std::endl;
    //std::cout<<n<<std::endl;
    ::cout<<myspace::n<<::endl;
    cout<<"7+3="<<7+3<<endl;
    
}
