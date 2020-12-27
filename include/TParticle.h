#ifndef TPARTICLE_H
#define TPARTICLE_H
#include <math.h>
#include "RandUtils.h"

class TParticle
{
    public:
        inline static int L;
        TParticle();
        virtual ~TParticle();
        int xc, yc, xs, ys, xd, yd;
        //!Muove la particella di 1 istante temporale secondo le regole in essa definite
        void Move();

    protected:
        bool mob;

    private:
        //Dichiariamo i vettori dx e dy costanti instanziate globalmente una sola volta.
        static constexpr int dx[6] = {-2,2,1,-1,1,-1};
        static constexpr int dy[6] = {0,0,1,1,-1,-1};
        //!Dispone una la particella in una posizione random della griglia
        //!Attenzione: non viene effettuato alcun controllo di sovrapposizione
        //!con altre particelle
        void RandomizePosition();

};

#endif // TPARTICLE_H
