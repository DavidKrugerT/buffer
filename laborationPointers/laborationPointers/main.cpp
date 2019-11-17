#include "buffer.h"
#include "int_sorted.h"


void f(int_buffer buf);
void printa(int_buffer buf);
void generate(int_buffer&);


int main(int argc, char** argv)
{
	std::srand(time(NULL));

	// martins sort
	int_buffer a(10);
	f(a);
	/*
	generate(a);
	std::cout << "#######################" << std::endl;
	int_sorted hej(a.begin(), 400000);

	auto start = std::chrono::system_clock::now();


	hej.msort(a.begin(), a.end());

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	*/

	/*
	
	auto start = std::chrono::system_clock::now();

	int_sorted b(a.begin(), a.size());
	b.selectionSort(a);

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;	
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	std::cout << "b sorted: " << std::endl;
	for (auto elem : b) {
		std::cout << elem << std::endl;
	}
		*/
	system("PAUSE");
	return 0;
}
//printa en buffer
void printa(int_buffer buf) {
	for (size_t i = 0; i < buf.size(); i++)
	{
		std::cout << buf[i] << std::endl;
	}
}
//skapa en buffer och ge den int per address.
void f(int_buffer buf)
{
	int x = 1;
	for (int * i = buf.begin(); i != buf.end(); i++)
	{
		buf[x - 1] = x;
		x++;
	}

	int y = 0;
	for (const int * i = buf.begin(); i != buf.end(); i++)
	{
		std::cout << buf[y] << std::endl;
		y++;
	}
	
};

//genererar randomiserade siffror
void generate(int_buffer& buf) {

	for (int* i = buf.begin(); i != buf.end(); i++)
	{
		auto number = rand() % 10 + 1;
		*i = number;
	}
}
	