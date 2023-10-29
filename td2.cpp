#include<iostream> 

#include <algorithm>

using namespace std;

int main(){
	int n;
	cout<<"Moi nhap so lan";
	cin>>n;
	
	int arr[n][4];
	int i , j ;
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			cout<<"Moi nhap so thu "<<i+1;
			cin>>arr[i][j]; 
		} 
	} 
//	s?p x?p tãng d?n
  for(i=0;i<n;i++){
  	 int h = sizeof(arr[i]) / sizeof(arr[i][0]);
  	 sort(arr, arr + n);
  } 
  int sum; 
  int k=0; 
  for(i=0;i<n;i++){
  	for(j=0;j<4;j++){
  	 if((arr[i][j]<0)&&(j<2)){ 
  	sum+=arr[i][j];
	  k++; 
  }
  cout<<sum<<"\n"; 	
	  } 
 
   
  } 
} 
