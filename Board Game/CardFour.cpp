#include "CardFour.h"
#include "Snake.h"

CardFour::CardFour(const CellPosition& pos) :Card(pos)
{
	pCell = NULL;
	cardNumber = 4;
}

CardFour::~CardFour()
{
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	//if after the card there is a snake go to its start position if there isnt just do nothing and stay on this card
	if (pCell->HasSnake()) {
		Snake* s = pGrid->GetNextSnake(position);
		pGrid->UpdatePlayerCell(pPlayer, s->GetEndPosition());

	}
}



void CardFour::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardFour::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardFour::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


void CardFour::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << endl;
}

void CardFour::Read(ifstream& Infile)
{
	
}

