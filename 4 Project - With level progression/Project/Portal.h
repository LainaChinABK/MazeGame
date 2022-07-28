#pragma once
#include <iostream>
#include "PlaceableActor.h"

class Portal :
    public PlaceableActor
{
public:
    Portal(int x, int y, int dx = -1, int dy = -1);
    virtual void Draw() override;

    virtual ActorType GetType() override { return ActorType::Portal; }

    int GetXDestination() { return m_destX; }
    int GetYDestination() { return m_destY; }
    void SetDestination(int x, int y);

private:
    int m_destX;
    int m_destY;
};

