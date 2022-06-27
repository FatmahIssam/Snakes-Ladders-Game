#include "DiceValue.h"



DiceValue::DiceValue(ApplicationManager * pApp) : Action(pApp)
{
}

void DiceValue::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter a dice value between 1-6 ");
	diceNumber = pIn->GetInteger(pOut);
	while (diceNumber < 0 || diceNumber > 6) //if number is invalid for dice
	{
		pOut->PrintMessage("Invalid dice number, Please enter a dice value between 1-6 ");
		diceNumber = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
}

void DiceValue::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	
	ReadActionParameters();
	
	if (pGrid->GetEndGame()) // if game has ended
	{
		pGrid->PrintErrorMessage("Game has ended. Can't roll dice ");
		return;
	}

	//moves player with apply fn of the game object
	pGrid->GetCurrentPlayer()->Move(pGrid, diceNumber);
	
	//next player
	pGrid->AdvanceCurrentPlayer();

}


DiceValue::~DiceValue()
{

}
