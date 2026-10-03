#include<iostream>
#include<cstdint>
using namespace std;

int main(){
	uint32_t v;
	//v = 7;
	cout << "enter the input : "<<endl;
	cin >> v ;
	int count = 0 ;
	while(v){
		if(v&1)count++;
		v = v>>1;
	}
	cout<<"the no of set bits in v are : " << count << endl;
}
