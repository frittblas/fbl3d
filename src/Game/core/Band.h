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

#include <entt/entt.hpp>

class Game;

class Band
{

public:

    Band(Game& g);
    ~Band();

    void tick(Game& g);
    void init(Game& g);

    static const int mMaxMembers = 4;

    std::vector<entt::entity> mLineUp;

private:

};
