#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "TParticle.h"
#include "RandUtils.h"
#include <vector>

//definisco una costante esterna (non variabile) cioè i parametri
#define N 500  // numero particelle
#define LEN 500  // dimensioni spazio
#define T 1000000 // tempo di simulazione

//dichiaro funzioni

int main(){

sf::RenderWindow app(sf::VideoMode(LEN,LEN), "Simulazione Diffusione Monomeri");
sf::Event event;

//inizializzo un vettore di elementi di tipo "Particella"
std::vector<TParticle> AllPart;

//inizializzo il generatore random
seedMT2();

//inizializzo il vettore N classi "Particle", x e y random e mob=false
TParticle::L=LEN;

for (int i=0; i<N; i++)
    {
    TParticle x;
    AllPart.push_back(x);
    }

// per vedere se il posizionamento iniziale delle particelle va bene:

    /*for (auto &i : AllPart)
    {sf::Vertex monomeroC=sf::Vertex(sf::Vector2f(i.xc,i.yc), sf::Color::Red);
        app.draw(&monomeroC,1,sf::Points);

        sf::Vertex monomeroS=sf::Vertex(sf::Vector2f(i.xs,i.ys), sf::Color::White);
        app.draw(&monomeroS,1,sf::Points);

        sf::Vertex monomeroD=sf::Vertex(sf::Vector2f(i.xd,i.yd), sf::Color::White);
        app.draw(&monomeroD,1,sf::Points);}

    app.display();

    while (app.isOpen()) while (app.pollEvent(event)) if (event.type == sf::Event::Closed) app.close();

    return 0;
    }*/

//moto browniano delle particelle
for (int t=0; t<T; ++t)
    {
    app.clear();
    for (auto &i : AllPart)
        {
        i.Move();
        sf::Vertex monomeroC=sf::Vertex(sf::Vector2f(i.xc,i.yc), sf::Color::Red);
        app.draw(&monomeroC,1,sf::Points);

        sf::Vertex monomeroS=sf::Vertex(sf::Vector2f(i.xs,i.ys), sf::Color::White);
        app.draw(&monomeroS,1,sf::Points);

        sf::Vertex monomeroD=sf::Vertex(sf::Vector2f(i.xd,i.yd), sf::Color::White);
        app.draw(&monomeroD,1,sf::Points);
        }
    app.display();
    app.pollEvent(event); if (event.type == sf::Event::Closed) app.close();
    }
while (app.isOpen()) while (app.pollEvent(event)) if (event.type == sf::Event::Closed) app.close();
return 0;
}
