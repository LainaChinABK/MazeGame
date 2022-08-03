#include <iostream>
#include <windows.h>
#include "Door.h"
#include "Player.h"

Door::Door(int x, int y, ActorColor color, ActorColor closedColor)
	: PlaceableActor(x, y, color)
	, m_isOpen(false)
	, m_closedColor(closedColor)
{

}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_isOpen)
	{
		SetConsoleTextAttribute(console, (int)m_color);
	}
	else
	{
		SetConsoleTextAttribute(console, (int)m_closedColor);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}

void Door::HandleCollision(PlaceableActor& player)
{
	if (!m_isOpen)
	{
		Player& m_player = dynamic_cast<Player&>(player);
		if (m_player.HasKey(m_color))
		{
			Open();
			Remove();
			m_player.UseKey();
			m_player.SetPosition(GetXPosition(), GetYPosition());
			AudioManager::GetInstance()->PlayDoorOpenSound();
		}
		else
		{
			AudioManager::GetInstance()->PlayDoorClosedSound();
		}
	}
	else
	{
		player.SetPosition(GetXPosition(), GetYPosition());
	}
}
