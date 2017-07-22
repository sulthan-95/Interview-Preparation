#include<iostream>
using namespace std;
int countParenth(char *symbol,char *oper,int n)
{
	int T[n][n];
	int F[n][n];
	for(int i=0;i<n;i++)
	{
		T[i][i]=(symbol[i]=='F')?0:1;
		F[i][i]=(symbol[i]=='T')?0:1;
	}
	//Sets the gap between i and j
	for(int gap=1;gap<n;gap++)
	{
		//Sets the i and j based on the gap
		for(int i=0,int j=gap,j<n;i++,j++)
		{
			T[i][j]=F[i][j]=0;
			//Now Let us fill the gap from 0 to gap
			//gap is analagous to chain length l
			for(int g=0;g<gap;g++)
			{
				int k=i+g;
				
				int tik=T[i][k]+T[k][j];
				int tkj=T[k+1][j]+F[k+1][j];
				
				//Based on the operator now
				if(oper[k]=='&')
				{
					T[i][j]+=T[i][k]*T[k+1][j];
					F[i][j]+=(tik*tkj-T[i][k]*T[k+1][j]);
				}
				if(oper[k]=='|')
				{
					T[i][j]+=(tik*tkj-F[i][k]*F[k+1][j]);
					F[i][j]+=F[i][k]*F[k+1][j];
				}
				if(oper[k]=='^')
				{
					T[i][j]+=(T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j]);
					F[i][j]+=(T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]);
				}
			}
		}
	}
	return T[0][n-1];
}
		
int main()
{
    char symbols[] = "TTFT";
    char operators[] = "|&^";
    int n = strlen(symbols);
 
    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
    cout << countParenth(symbols, operators, n);
    return 0;
}
