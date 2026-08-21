#pragma once
template <typename T, int br>
class GenerickiNiz
{
private:
	int tr=0;
	int maks;
	T* niz;

public:
	GenerickiNiz()
	{
		niz = nullptr;
		tr = 0;
		maks = 0;
	}
	GenerickiNiz(T pod, int br)
	{
		niz = new T[br];
	}

	friend std::istream& operator>>(std::istream& in, GenerickiNiz& n)
	{
		while (n.tr < n.maks)
		{
			in >> n.niz[i];
			n.tr++;
		}

		return out;
	}

	friend std::ostream& operator<<(std::ostream& out, const GenerickiNiz& n)
	{
		for (int i = 0; i < g.tr; i++)
		{
			out << n.niz[i] << " ";
		}
		out << std::endl;
		return out;
	}

};