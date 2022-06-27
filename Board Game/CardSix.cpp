#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos) :Card(pos)
{
	cardNumber = 6;
	Step = 0;
}

CardSix::~CardSix()
{
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CellPosition c1 = pPlayer->GetCell()->GetCellPosition();
	c1.AddCellNum(-pPlayer->GetLastRolledDice());
	pGrid->PrintErrorMessage("Player last move will be negated");
	pGrid->UpdatePlayerCell(pPlayer, c1);

}



void CardSix::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardSix::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardSix::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


void CardSix::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << endl;
}

void CardSix::Read(ifstream& Infile)
{
	
}
