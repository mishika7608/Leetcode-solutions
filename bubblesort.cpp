#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int uth[n];
  for (int i=0;i<n;i++){
    cin >> uth[i];
  }
  int j=n;
  	while(j>0)
  	{
  	for (int i=0;i<n-1;i++)
  	{
  		if (uth[i]>uth[i+1])
  		{
  			int c=uth[i];
  			uth[i]=uth[i+1];
  			uth[i+1]=c;
  		}
  	}
  	j--;
  	}
  	for (int i=0;i<n;i++)
  	{
  		cout<<*(uth+i)<<"\t";
  	}
  return 0;
}
