#include "Vagon.h"

std::istream& operator>>(std::istream& in, Vagon& v)
{
    // TODO: insert return statement here
    float sm, mt;
    in >> sm;
    in >> mt;
    if (mt > sm)
        throw "mt veca od mv pri unosu";

    v.sopstvenaMasa = sm;
    v.masaTereta = mt;
    //in >> v.sopstvenaMasa;
    //in >> v.masaTereta;
}

std::ostream& operator<<(std::ostream& out, const Vagon& v)
{
    // TODO: insert return statement here
    out << v.sopstvenaMasa << std::endl;
    out << v.masaTereta << std::endl;
    return out;
}

Vagon::Vagon()
{
    sopstvenaMasa = 0;
    masaTereta = 0;
}

Vagon::Vagon(float _sopstvenaMasa, float _masaTereta)
{
    if (_sopstvenaMasa < _masaTereta)
        throw("Masa tereta prevelikaA!!!");
    sopstvenaMasa = _sopstvenaMasa;
    masaTereta = _masaTereta;
}

Vagon Vagon::operator+(const Vagon& v)
{
    return Vagon(sopstvenaMasa + v.sopstvenaMasa, masaTereta + v.masaTereta);;
}
bool Vagon::operator>(const Vagon& v)
{
    return masaTereta > v.masaTereta;
}

Vagon& Vagon::operator=(const Vagon& v)
{
    this->masaTereta = v.masaTereta;
    this->sopstvenaMasa = v.sopstvenaMasa;

    return *this;
}
