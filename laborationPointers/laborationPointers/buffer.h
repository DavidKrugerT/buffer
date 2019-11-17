#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <time.h>
#include <stdio.h>

class int_buffer {
public:
	int_buffer() = delete;
	explicit int_buffer(size_t size); // size_t is defined in cstdlib, explicit förbjuder typomvandling
	int_buffer(const int * source, size_t size);
	int_buffer(const int_buffer & rhs); // copy construct
	int_buffer(int_buffer && rhs); // move construct
	int_buffer & operator =(const int_buffer & rhs); // copy assign
	int_buffer & operator =(int_buffer && rhs); // move assign
	size_t size() const;
	int * begin();
	int * end();
	const int * begin() const;  //denna tar in och returnar helt talets begin
	const int * end() const; //denna tar in och returnar helt talets end
	~int_buffer();
	int& operator[](size_t index); //operatoröverlagringar
	static void swap(int_buffer&, int_buffer&);
	// Dessa private pekare kommer att användas för att peka och påverka vårt allocerat minne 
private:
	int* ptrBegin; 
	int* ptrEnd;
};



#endif

