#pragma once
#include "Pice.h"
class Sok :
    public Pice
{
private:
    char* ukus;
    double procenatVoca;
    double odnosCene;
public:
    Sok() {};
    Sok(double _zapreminaAmbalaze, const char* _ukus, double _procenatVoca, double _odnosCene);
    ~Sok();
    void stampaj(std::ostream& out) const override;



};

