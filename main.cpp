#include "notString.h"
using namespace std;

int main()
{
    //constructors
    char temp[] = "Hello";
    notString a {temp};
    notString b = "Goodbye";
    notString c=a;
    notString d{ notString{ temp } };

    //various functions
    cout<<c.length()<<endl;
    cout<<(a=="Hello")<<endl;
    cout<<(b>a)<<endl;
    d[3]='p';
    d.at(4)='s';
    cout <<d<<endl;
    const char* str = a.c_str();

    //+ and +=
    c+='H';
    c+='i';
    c+="Hi";
    cout<<c<<endl;
    d+=d;
    cout<<d<<endl;

    c=c+a;
    cout<<c<<endl;
    c="start"+c;
    c=c+"End";
    c='*'+c;
    c=c+'*';
    cout<<c<<endl;

    //find
    cout<<b.find('o')<<endl;
    cout<<b.find('o',2)<<endl;
    cout<<b.find("Good")<<endl;
    cout<<b.find("bye",2)<<endl;
    cout<<b.find("bye_my_friend",2,3)<<endl;
    notString bye{"bye"};
    cout<<b.find(bye)<<endl;
    cout<<b.find(bye,2)<<endl;
    bye+="_my_friend";
    cout<<b.find(bye,2,2)<<endl;

    cin>>c;
    cout<<c;

    return 0;
}

