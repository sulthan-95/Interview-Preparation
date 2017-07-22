#include<iostream>
using namespace std;


int main(){
    int mat[6][6];
    int i,j;
    int max=0,sum=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
            cin>>mat[i][j];
    }
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {   
            sum=0;
            sum+=mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
            if(sum>max)
                max=sum;
        }
    }
    cout<<max<<endl;
    return 0;
}
