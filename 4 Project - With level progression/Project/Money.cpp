#include <iostream>
#include "Money.h"
#include "Player.h"

Money::Money(int x, int y, int worth)
	: PlaceableActor(x, y)
	, m_worth(worth)
{

}

void Money::Draw()
{
	std::cout << "$";
}

void Money::HandleCollision(PlaceableActor& player)
{
	AudioManager::GetInstance()->PlayMoneySound();
	Remove();
	dynamic_cast<Player&>(player).AddMoney(GetWorth());
	player.SetPosition(GetXPosition(), GetYPosition());
}
