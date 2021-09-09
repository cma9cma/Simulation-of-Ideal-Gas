// count the amount of particles in every velocity intervels

class counter
{
private:
public:
    int cnt;
    void cntIni();
    void cntIncre();
};

void counter::cntIni()
{
    cnt = 0;
}

void counter::cntIncre()
{
    cnt++;
}