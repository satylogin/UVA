#include<bits/stdc++.h>
using namespace std;
long long int mat[21][21][21], csum[21][21][21],a,b,c;
void pre()
{
	int i,j,k;
	for(k=0;k<c;++k)
	{
		for(i=0;i<a;++i)
		{
			for(j=0;j<b;++j)
			{
				if(i == 0 && j == 0) csum[i][j][k] = mat[i][j][k];
				else if(i == 0) csum[i][j][k] = csum[i][j-1][k]  + mat[i][j][k];
				else if(j == 0) csum[i][j][k] = csum[i-1][j][k]  + mat[i][j][k];
				else csum[i][j][k] = csum[i-1][j][k] + csum[i][j-1][k] - csum[i-1][j-1][k] + mat[i][j][k];
			}
		}
	}
}
long long int ans(int x1,int y1,int x2, int y2, int z)
{
	long long int sum = csum[x2][y2][z];
	if(x1 > 0) sum -= csum[x1-1][y2][z];
	if(y1 > 0) sum -= csum[x2][y1-1][z];
	if(x1 > 0 && y1 > 0) sum += csum[x1-1][y1-1][z];
	return sum;
}
int main()
{
	int t,cnt,minv;
	cin>>t;
	while(t--)
	{
		minv = INT_MIN;
		cnt = 0;
		int i,j,k;
		cin>>a>>b>>c;
		for(i=0;i<a;++i)
		{
			for(j=0;j<b;++j)
			{
				for(k=0;k<c;++k)
				{
					cin>>mat[i][j][k];
					if(mat[i][j][k] < 0) cnt++;
					minv = max((long long int)minv,mat[i][j][k]);
				}
			}
		}
	
	pre();
	int x1,x2,y1,y2,z;
	long long int sum, cur;
	sum = -1;
	for(x1=0;x1<a;++x1)
	{
		for(y1=0;y1<b;++y1)
		{
			for(x2=x1;x2<a;++x2)
			{
				for(y2=y1;y2<b;++y2)
				{
					cur = 0;
					for(z=0;z<c;++z)
					{
						cur = max(0ll,cur+ans(x1,y1,x2,y2,z));
						sum = max(sum,cur);
					}
				}
			}
		}
	}
	//cout << cnt << " " << minv << " " << sum << endl;
	if(cnt != a*b*c) cout<<sum<<endl;
	else cout<<minv<<endl;
	if (t != 0) {
		cout << endl;
	}
	}
}
