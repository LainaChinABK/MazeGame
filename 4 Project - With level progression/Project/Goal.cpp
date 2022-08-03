#include <iostream>
#include "Goal.h"
#include "Player.h"

Goal::Goal(int x, int y)
	: PlaceableActor(x, y)
{
	
}

void Goal::Draw()
{
	std::cout << "X";
}

void Goal::HandleCollision(PlaceableActor& player)
{
	Player& m_player = dynamic_cast<Player&>(player);
	Remove();
	m_player.SetPosition(GetXPosition(), GetYPosition());
	// TODO: figure out how to set m_beatLevel to true
}