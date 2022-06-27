#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition& pos) :Card(pos)
{
	pCell = NULL;
	cardNumber = 3;


}

CardThree::~CardThree()
{

}


void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	//if after the card there is a ladder go to its start position if there isnt just do nothing and stay on this card
	//if (pCell->HasLadder()) {
		Ladder* l = pGrid->GetNextLadder(position);
		pGrid->UpdatePlayerCell(pPlayer, l->GetPosition());
	//}
	


}

void CardThree::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardThree::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardThree::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


void CardThree::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << endl;
}

void CardThree::Read(ifstream& Infile)
{
	/*int type, position;
	CellPosition p;
	Infile >> type >> position;
	Card::SetCardNumber(type);
	GameObject::position = p.GetCellPositionFromNum(position);*/
}


