// particle class

#include <ctime>
#include <cmath>
#include <random>

// total amount of particles
#define N 250

// max velocity of particles when the random initialization occurs
#define Vmax 15

// max new velocity of particles when a trial change occurs
#define Smax 15

// a parameter for computing the probability of accepting the trial change when energy increases, 
// related to temperature and mass of particle
#define gamma 5.74386e-3

using namespace std;
default_random_engine e(time(0));
uniform_real_distribution<double> u(0, Vmax);
uniform_int_distribution<unsigned> w(0, N - 1);
uniform_real_distribution<double> v(0, Smax);
uniform_real_distribution<double> x(0, 1);

class particle
{
private:

public:

    double velx;
    double vely;
    double velz;

    // square velocity of particles
    double sqvel;

    // make a initialization during which each particles are given a random velocity in [0, Vmax]
    void velIni();

    // perform a trial change to change configuration of the system randomly
    void trialChange();
};

void particle::velIni()
{

    velx = u(e);
    vely = u(e);
    velz = u(e);
    sqvel = (velx * velx) + (vely * vely) + (velz * velz);
}

void particle::trialChange()
{

    double new_velx = v(e);
    double new_vely = v(e);
    double new_velz = v(e);
    double new_sqvel = (new_velx * new_velx) + (new_vely * new_vely) + (new_velz * new_velz);
    double delta_sqvel = new_sqvel - sqvel;

    // if delta_sqvel <= 0, i.e. the energy decreases, accept the new configuration
    if (delta_sqvel <= 0)
    {
        sqvel = new_sqvel;
    }
    else
    {
        double r = x(e);

        // if r <= exp(-(gamma * delta_sqvel)), accept the new configuration
        if (r <= exp(-(gamma * delta_sqvel)))
        {
            sqvel = new_sqvel;
        }
    }
}
