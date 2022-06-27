
#include "CardFive.h"
#include "RollDiceAction.h"

CardFive::CardFive(const CellPosition& pos) :Card(pos)
{
	cardNumber = 5;
	Step = 0;
}

CardFive::~CardFive()
{
}


void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	CellPosition c1 = pPlayer->GetCell()->GetCellPosition();
	c1.AddCellNum(pPlayer->GetLastRolledDice());
	pGrid->PrintErrorMessage("Player will move another "+to_string(pPlayer->GetLastRolledDice()));
	pGrid->UpdatePlayerCell(pPlayer, c1);


}



void CardFive::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardFive::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardFive::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


void CardFive::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << endl;
}

void CardFive::Read(ifstream& Infile)
{
	
}