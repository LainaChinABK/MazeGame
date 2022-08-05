#pragma once

class GameState
{
public:
	virtual ~GameState() {}

	virtual void Enter() {}
	virtual void ProcessInput() {}
	virtual bool Update(bool processInput = true) { return false; }
	virtual void Draw() = 0;
	virtual void Exit() {}
};