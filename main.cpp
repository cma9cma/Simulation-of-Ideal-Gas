// MC Simulation of three-dimensional ideal gas

#include <particle.h>
#include <counter.h>
#include <makeChart.h>

// total times of trial change
#define M 7500

// the parameter to make chart
#define Tmax 30

int main()
{
    particle p[N];
    counter cnt[f * Tmax];
    makeChart drawer;

    for (int i = 0; i < N; i++)
    {
        p[i].velIni();
    }

    for (int i = 0; i < f * Tmax; i++)
    {
        cnt[i].cntIni();
    }

    for (int i = 0; i < M; i++)
    {
        // randomly choose a particle to perform a trial change
        int sel_part = w(e);
        p[sel_part].trialChange();
    }

    // count the amount of particles in every velocity intervels
    for (int i = 0; i < f * Tmax; i++)
    {
        double i2 = (double)i;
        for (int j = 0; j < N; j++)
        {
            double vel = sqrt(p[j].sqvel);
            if ((vel < (i2 + 1) / f) && (vel >= (i2 / f)))
            {
                cnt[i].cntIncre();
            }
        }
    }

    // draw a histogram to show the final state of system after trial changes
    drawer.printFrame();
    for (int i = 0; i < f * Tmax; i++)
    {
        drawer.printSquares(cnt[i].cnt, i);
    }

    cin.get();
    return 0;
}
