#include "Game.h"
#include <thread>

Game::Game()
	: m_pStateMachine(nullptr)
{

}

void Game::Initialize(GameStateMachine* pStateMachine)
{
	if (pStateMachine != nullptr)
	{
		pStateMachine->Init();
		m_pStateMachine = pStateMachine;
	}
}

void Game::RunGameLoop()
{
	bool isGameOver = false;
	std::thread InputThread(&Game::ProcessInput, this);

	while (!isGameOver)
	{
		// update with no input
		Update(false);
		// TODO: only call draw function during game
		// Draw
		Draw();
		// Update with input
		isGameOver = m_pStateMachine->GameOver();
	}

	Draw();
	InputThread.join();
}

void Game::Deinitialize()
{
	if (m_pStateMachine != nullptr)
		m_pStateMachine->Cleanup();
}

void Game::ProcessInput()
{
	while (!m_pStateMachine->GameOver())
	{
		m_pStateMachine->ProcessInput();
	}
}

bool Game::Update(bool processInput)
{
	return m_pStateMachine->UpdateCurrentState(processInput);
}

void Game::Draw()
{
	m_pStateMachine->DrawCurrentState();
}
