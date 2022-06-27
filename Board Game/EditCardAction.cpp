#include "EditCardAction.h"


EditCardAction::EditCardAction(ApplicationManager *pApp) : Action(pApp)
{

}

void EditCardAction::ReadActionParameters(){
	Grid * pGrid = pManager->GetGrid();
	Output * pOut=	pGrid->GetOutput();
	Input * pIn =	pGrid->GetInput();


	//Get pointer to the card to be clicked
	pOut->PrintMessage("Click on the card you want to edit.");
	CellPosition C1 = pIn->GetCellClicked();
	
	GameObject * Gobj = pGrid->GetGameObject(C1);

	CardToBeEdited = dynamic_cast<Card*>(Gobj);
	

}

void EditCardAction::Execute(){

	ReadActionParameters();
	Grid * pGrid = pManager->GetGrid();
	if(CardToBeEdited){

		CardToBeEdited->Edit(pGrid);


	}
	else
		pManager->GetGrid()->PrintErrorMessage("There's no card in the cell you clicked.");


}

EditCardAction::~EditCardAction(void)
{
}
