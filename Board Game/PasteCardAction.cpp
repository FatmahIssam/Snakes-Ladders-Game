#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) :Action(pApp)
{

}

void PasteCardAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the destination cell for pasting");
	CellPosition C1 = pIn->GetCellClicked();
	GameObject* Gobj = pGrid->GetClipboard();

	/*CC3 = dynamic_cast<Card*>(Gobj);*/
}

void PasteCardAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	CellPosition C1 = pIn->GetCellClicked();
	Cell* pCell = new Cell(C1);

	/*if (CC3) {

		CC3->PasteCard(pGrid);


	}
	else*/ if (pCell->HasCard() || pCell->HasLadder() || pCell->HasSnake()) {

		pManager->GetGrid()->PrintErrorMessage("An object exists in the destination cell");
	}
	else
		pManager->GetGrid()->PrintErrorMessage("No card in the clipboard");
}

PasteCardAction::~PasteCardAction()
{
}

