#include "buffer.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <utility>

//maker int buffer
//initiering n�r vi callar funktionen
int_buffer::int_buffer(size_t size) : ptrBegin(new int[size]), ptrEnd(ptrBegin + size){ // 1 Denna k�rs

}
//storleksf�r�ndring. source int pekaren.
int_buffer::int_buffer(const int * source, size_t size) : ptrBegin(new int[size]), ptrEnd(ptrBegin + size){ // 1 denna k�rs inte 
	for ( size_t i = 0; i < size; i++)
		ptrBegin[i] = *(source+i);	
}
//Copy construct funka
int_buffer::int_buffer(const int_buffer & rhs) : int_buffer(rhs.ptrBegin, rhs.size()) { // 1 denna k�rs inte 

}

//move construct 
int_buffer::int_buffer(int_buffer && rhs) : ptrBegin(rhs.ptrBegin), ptrEnd(rhs.ptrEnd) {
	rhs.ptrBegin = nullptr;
	rhs.ptrEnd = nullptr;
}

//Copy assign
int_buffer & int_buffer::operator=(const int_buffer & rhs){
	int_buffer tmp = rhs;
	swap(*this, tmp);
	return *this;
}
//Move assign DENNA FUNKTION FUNGERAR �NDRA INGET H�R 
int_buffer & int_buffer::operator=(int_buffer && rhs){
	swap(*this, rhs);
	return *this;
}

//FUNKAR
size_t int_buffer::size() const {
	return ptrEnd - ptrBegin;
}
//FUNKAR
int * int_buffer::begin(){
	return ptrBegin;
}
//FUNKAR
int * int_buffer::end(){
	return ptrEnd;
}
//FUNKAR
const int * int_buffer::begin() const{
	return ptrBegin;
}
//FUNKAR
const int * int_buffer::end() const{
	return ptrEnd;
}
//FUNKAR 
int_buffer::~int_buffer(){ // 1 denna k�rs 
	delete[] ptrBegin;
}

//funktion som l�ter oss g� in i en array eller buffer p� detta vis buf[0] 
int& int_buffer::operator[](size_t index) {
	return ptrBegin[index];
}

void int_buffer::swap(int_buffer& a, int_buffer& b)
{
	std::swap(a.ptrBegin, b.ptrBegin);
	std::swap(a.ptrEnd, b.ptrEnd);
}