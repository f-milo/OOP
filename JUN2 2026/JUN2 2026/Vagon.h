#pragma once
#include <iostream>
#include <fstream>

class Vagon
{
private:
	float sopstvenaMasa;
	float masaTereta;

public:
	Vagon();
	Vagon(float _sopstvenaMasa, float _masaTereta);

	friend std::istream& operator>>(std::istream& in, Vagon& v);

	friend std::ostream& operator<<(std::ostream& out, const Vagon& v);
	Vagon operator+(const Vagon& v);
	bool operator>(const Vagon& v);
	Vagon& operator=(const Vagon& v);
};

