#include<iostream>
#include<vector>
#include<String>

using namespace std;
 
void COMPUTE_PREFIX_FUNCTION(string P,vector<int> &PI){
	
	int m = P.size()-1;
	PI[1] = 0;
	int k=0;
	for(int q=2;q<=m;q++)
	{
		while(k>0&&P[k+1]!=P[q])
			k=PI[k];
		
		if(P[k+1]==P[q])
			k=k+1;
		
		PI[q]=k;	
		
	}
	return;
}
 
void KMP_MATCHER(string T,string P)
{
	int n = T.size()-1;
	int m = P.size()-1;
	
	//cout<<m<<' '<<n;
	
	vector<int> PI = vector<int>(m);
	
	COMPUTE_PREFIX_FUNCTION(P,PI);
	
	int q=0;
	for(int i=1;i<=n;i++)
	{
		while(q>0&&P[q+1]!=T[i])
			q=PI[q];
		
		if(P[q+1]==T[i])
			q=q+1;
		
		if(q==m)
		{
			cout<<"Pattern occurs with shift"<<i-m+1<<endl;
			q=PI[q];
		}
			
		
	}
	
	return;

}
 
 
int main(){
  
  string a,b;
  
  cin>>a>>b;
  a=' '+a;
  b=' '+b;
 
  KMP_MATCHER(a,b);
  
  
  return 0;
}

