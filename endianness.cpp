#include<iostream>
#include<cstdint>
using namespace std;

//bool is_little_endian(void){
//}
uint32_t bswap32(uint32_t v){

	return ((v & 0x000000FF) << 24 ) | 
		((v & 0x0000FF00) << 8 ) | 
		((v & 0x00FF0000) >> 8 ) | 
		((v & 0xFF000000) >> 24) ;

}
int main(){
	uint32_t some = 0xFFFFFFFF;
	cout << "some before : " << some << endl;
	some = bswap32(some);
	cout<< some << endl;
}
