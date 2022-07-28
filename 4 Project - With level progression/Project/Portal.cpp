#include "Portal.h"

Portal::Portal(int x, int y, int dx, int dy)
	: PlaceableActor(x, y)
	, m_destX(dx)
	, m_destY(dy)
{

}

void Portal::Draw()
{
	std::cout << "&";
}

void Portal::SetDestination(int x, int y)
{
	m_destX = x;
	m_destY = y;
}
