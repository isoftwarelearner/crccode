#include <iostream>
#include <string.h>
#define N strlen(g)

using namespace std;

char t[128],cs[128],g[]="10001000000100001";
int a,e,c;

void xori()
{
    for(c=1;c<N;c++)
        cs[c]=((cs[c]==g[c])?'0':'1');
}

void crc()
{
    for(e=0;e<N;e++)
        cs[e]=t[e];

    do
    {
        if(cs[0]=='1')
            xori();
        for(c=0;c<N-1;c++)
            cs[c]=cs[c+1];
        cs[c]=t[e++];
    }while(e<=a+N-1);

}

int main()
{

cout<<"Enter the poly:";
    cin>>t;
    cout<<"poly:"<<t<<endl<<endl;
    a=strlen(t);
    for(e=a;e<a+N-1;e++)
        t[e]='0';
    cout<<"modified poly: ";
    cout<<t<<endl<<endl;

    crc();

    cout<<"checksum: "<<cs<<endl<<endl;

    int i=0;
    for(e=a;e<a+N-1;e++)
        t[e]=cs[i++];
    cout<<"Final codeword:"<<t<<endl<<endl;
    char ch;
    cout<<"Do you want to make an error?(y|n):";
    cin>>ch;
    int pos;
    if(ch=='y')
    {
        cout<<"Enter position:";
        cin>>pos;
        t[pos]=((t[pos]=='1')?'0':'1');
        cout<<"Errorneous data:"<<t<<endl<<endl;
    }
    crc();
    for(e=0;e<N-1;e++)
    {
        if(cs[e]=='1')
            break;
    }
    if(e<N-1)
        cout<<"Error detected"<<endl;
    else
        cout<<"No error detected"<<endl;
}
