/*
*
*	Rock band manager
*
*	Band.h
*
*	Band class header, takes care of all band related things (members etc).
*
*	Hans Strömquist 2025
*
*/

#pragma once

class Game;

class Band
{

public:

    Band(Game& g);
    ~Band();

    void tick(Game& g);

private:

    void init(Game& g);

};
