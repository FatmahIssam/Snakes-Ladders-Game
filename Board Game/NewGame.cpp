#include "NewGame.h"
#include "Player.h"
#include "Grid.h"



NewGame::NewGame(ApplicationManager*pApp) :Action(pApp)
{
}



void NewGame::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Game ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->StartNewGame(); //returns all to starting state
}


NewGame::~NewGame()
{
}

