

#include <iostream>
#include <fstream>
#include "Rocket.h"
#include <vector>
#include <thread>
using namespace std;


class Timer
{
public:
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> difer = end - start;
		std::cout << " Duratioun - " << difer.count() << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};

int main()
{
	Timer oclock;
	calc_roket();


}
