#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
    int n,start,ender;
    cout<<"Valor: ";
    cin>>n;
    start=1;
    ender=n;
    cout<<endl<<endl;
    while(start!=ender)
    {
        for(int i=start;i<=ender;i++){cout<<i<<" ";}
        start++;
        ender--;
        cout<<endl;
    }
    cout<<start;
}
