#include "DeleteAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"




DeleteAction::DeleteAction(ApplicationManager * pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Click on the Cell you want to delete");
	CellPos = pIn->GetCellClicked();

	pOut->ClearStatusBar();
}

void DeleteAction::Execute()
{
	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid();

	pGrid->RemoveObjectFromCell(CellPos); //deallocates gameobjects and sets pointer to NULL
}

DeleteAction::~DeleteAction()
{
}
