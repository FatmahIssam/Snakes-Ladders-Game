#include "CopyCardAction.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) :Action(pApp)
{
}

void CopyCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the source cell for copying");


	CellPosition C1 = pIn->GetCellClicked();



}

void CopyCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	CellPosition C1 = pIn->GetCellClicked();

	Cell* pCell = new Cell(C1);
	GameObject* G = pGrid->GetGameObject(C1);
	if (CC) {
		return pGrid->SetClipboard(CC);
	}
	/*CC = dynamic_cast<Card*>(G);
	if (CC) {

		CC->CopyCard(pGrid);
	}*/
	else
		pManager->GetGrid()->PrintErrorMessage("No card in the clicked cell");
}

CopyCardAction::~CopyCardAction(void)
{
}
