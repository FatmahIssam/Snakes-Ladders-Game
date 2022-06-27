#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) :Action(pApp)
{
}

void CutCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the source cell for cutting");
	
	CellPosition C1 = pIn->GetCellClicked();



}

void CutCardAction::Execute()
{
	ReadActionParameters();

	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	CellPosition C1 = pIn->GetCellClicked();
	Cell* pCell = new Cell(C1);
	GameObject* G = pGrid->GetGameObject(C1);
	if (pCell->HasCard()) {
		return pGrid->SetClipboard(CC2);
	}

	CC2 = dynamic_cast<Card*>(G);
	if (CC2) {
		CC2->CopyCard(pGrid);
	}
	else
		pManager->GetGrid()->PrintErrorMessage("No card in the clicked cell");
}

CutCardAction::~CutCardAction()
{
}
