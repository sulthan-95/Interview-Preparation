#include <bits/stdc++.h>

using namespace std;

int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        int m,ai,bi;
        long long int x,so=0;
        cin >> n >> m >> x;
        stack<long long int> a,b,temp;
        for(int i=0;i<n;i++)
        {
            cin>>ai;
            so+=ai;
            a.push(so);
        }
        so=0;
        for(int i=0;i<m;i++)
        {
            cin>>bi;
            so+=bi;
            b.push(so);
        }
        while(!a.empty() && a.top()>x)
            a.pop();    
        while(!b.empty() && b.top()>x)
            b.pop();
        so=a.top()+b.top();
        while(so>x)
        {
            if(!a.empty())
                long long int in1=a.top()/a.size();
            if(!b.empty())
                long long int in2=b.top()/b.size();
            if(in1>in2)
            {
                if(!a.empty())
                    a.pop();
            }
            else if(in2>in1){
                if(!b.empty())
                    b.pop();
            }
            else
            {
                long long int k1=a.top();
                a.pop();
                
            }
            so=a.top()+b.top();
        }
        //cout<<so<<endl;
        cout<<a.size()+b.size()<<endl;
    }
    return 0;
}

