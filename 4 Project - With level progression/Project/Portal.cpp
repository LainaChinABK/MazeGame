#include "Portal.h"

Portal::Portal(int x, int y, int dx, int dy)
	: PlaceableActor(x, y)
	, m_destX(dx)
	, m_destY(dy)
{

}

Portal::~Portal()
{

}

void Portal::Draw()
{
	std::cout << "&";
}

void Portal::HandleCollision(PlaceableActor& player)
{
	player.SetPosition(m_destX, m_destY);
}

void Portal::SetDestination(int x, int y)
{
	m_destX = x;
	m_destY = y;
}
