void selectionSort(int a[], int n){
    for (int i=0;i<n-1;i++){
        int j=i, k=i;
        for (;j<n;j++){
            if (a[k]>a[j]){
                k=j;
            }
        }int temp=a[k];
        a[k]=a[i];
        a[i]=temp;
    }
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  for (int i=0;i<n;i++){cin>>arr[i];}
  selectionSort(arr,n);
  for (int i=0;i<n;i++){cout<<arr[i]<<"\t";}
  return 0;
}
