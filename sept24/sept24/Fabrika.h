#pragma once
#include <iostream>

template <typename T>
//gde god je float tu je T
class Fabrika
{
private:
	int tr;
	int maks;
	T* niz;
public:
	Fabrika(int maks);
};