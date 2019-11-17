#ifndef INT_SORTED_H
#define INT_SORTED_H
#include "buffer.h"

class int_sorted {
public:
	int_sorted() = delete;
	int_sorted(const int * source, size_t size);
	size_t size() const;
	int * insert(int value);
	const int * begin() const;
	const int * end() const;
	int_sorted merge(const int_sorted & merge_with) const;
	void selectionSort(int_buffer & rhs);
	int_sorted msort(const int* begin, const int* end);
	void print();
private: 
	//medlemsvariabel
	int_buffer buf; 
};

#endif