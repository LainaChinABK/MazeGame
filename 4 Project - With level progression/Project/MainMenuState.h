#pragma once
#include "GameState.h"

class StateMachineExampleGame;

class MainMenuState : public GameState
{
	StateMachineExampleGame* m_pOwner;

public:
	MainMenuState(StateMachineExampleGame* pOwner);
	~MainMenuState() = default;

	virtual void ProcessInput() override;
	virtual bool Update(bool processInput = true) override;
	virtual void Draw() override;

private:
	bool m_shouldQuit;
};

