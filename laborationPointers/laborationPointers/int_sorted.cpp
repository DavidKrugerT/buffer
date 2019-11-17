#include "int_sorted.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <utility>

int_sorted::int_sorted(const int * source, size_t size) : buf(source, size){
	if (size <= 1) {
		return;
	}
	auto a = msort(buf.begin(), buf.end());
	buf = std::move(a.buf);
}

size_t int_sorted::size() const
{
	return buf.size();
}

int * int_sorted::insert(int value)
{
	int_sorted tmp(&value, 1);
	buf = std::move(merge(tmp).buf);
	return std::find(buf.begin(), buf.end(), value);
}

const int * int_sorted::begin() const
{
	return buf.begin();
}

const int * int_sorted::end() const
{
	return buf.end();
}

int_sorted int_sorted::merge(const int_sorted & merge_with) const
{
	int_sorted f(nullptr, 0);
	int_buffer tmp(merge_with.size() + buf.size());
	const int* mergeBegin = merge_with.begin();
	const int* bufBegin = buf.begin();
	int* tmpBegin = tmp.begin();
	while (bufBegin != buf.end() && mergeBegin != merge_with.end())
	{
		if (*bufBegin < *mergeBegin)
		{
			*tmpBegin = *bufBegin;
			bufBegin++;
			tmpBegin++;
		}
		else
		{
			*tmpBegin = *mergeBegin;
			mergeBegin++;
			tmpBegin++;
		}
		
	}
	while (bufBegin != buf.end())
	{
		*tmpBegin = *bufBegin;
		bufBegin++;
		tmpBegin++;

	}
	while (mergeBegin != merge_with.end())
	{
		*tmpBegin = *mergeBegin;
		mergeBegin++;
		tmpBegin++;
	}
	f.buf = std::move(tmp); 
	return f;
}

void int_sorted::selectionSort(int_buffer& rhs)
{
	for (int* ptrA = rhs.begin(); ptrA != rhs.end()-1; ptrA++) {

		int* minP = ptrA;

		for (int* ptrB = (ptrA +1); ptrB != rhs.end(); ptrB++)
		{
			if (*ptrB < *minP)
			{
				minP = ptrB;
			}
		}

		if (minP != ptrA)
		{
			std::swap(*ptrA, *minP);
		}
	}
	this->buf = std::move(rhs);
}

int_sorted int_sorted::msort(const int * begin, const int * end)
{
	if (begin == end)
		return int_sorted(nullptr, 0);
	if (begin == end - 1)
		return int_sorted(begin, 1);
	
	ptrdiff_t half = (end - begin) / 2;
	const int* mid = begin + half;
	return msort(begin, mid).merge( msort(mid, end));
}

void int_sorted::print()
{
	for(auto i = buf.begin(); i != buf.end(); i++)
	{
		std::cout << *i << std::endl;
	}
}
