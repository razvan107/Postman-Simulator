#include <iostream>
#include <thread>
#include <chrono>
#include "Header.h"
using namespace std;
void wait(int s)
{
	this_thread::sleep_for(chrono::seconds(s));
}