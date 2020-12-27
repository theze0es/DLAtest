#ifndef TPARTICLE_H
#define TPARTICLE_H
#include <math.h>
#include "RandUtils.h"

class TParticle
{
    public:
        TParticle(int);
        virtual ~TParticle();
        int xc, yc, xs, ys, xd, yd, L;
        void Move();
        bool mob;

    protected:

    private:

};

#endif // TPARTICLE_H
