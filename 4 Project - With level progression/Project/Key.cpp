#include <iostream>
#include <windows.h>

#include "Key.h"
#include "Player.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "+";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}

void Key::HandleCollision(PlaceableActor& player)
{
	Player& m_player = dynamic_cast<Player&>(player);
	if (!m_player.HasKey())
	{
		m_player.PickupKey(this);
		Remove();
		m_player.SetPosition(GetXPosition(), GetYPosition());
		AudioManager::GetInstance()->PlayKeyPickupSound();
	}
}

