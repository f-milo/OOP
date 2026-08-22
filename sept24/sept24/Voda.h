#pragma once
#include "Pice.h"
class Voda :
    public Pice
{
private:

public:
    Voda(double _zapreminaAmbalaze);
    ~Voda() {};
    void stampaj(std::ostream& out) const override;
};

