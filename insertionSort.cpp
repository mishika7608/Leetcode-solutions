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
  for(int i=1;i<n;i++)
	{
		ele=uth[i];
		int j=i-1;
		while (uth[j]>ele && j>=0)
		{
			uth[j+1]=uth[j];
			j--;
		}
		uth[j+1]=ele;
	}

	for (int i=0;i<n;i++)
	{
		cout<<*(uth+i)<<"\t";
	}

  return 0;
}
