#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos) :Card(pos)

{
	cardNumber = 7;
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	int diceNumber = 1 + rand() % 6;
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	pGrid->PrintErrorMessage(" Roll dice another time :");
	pGrid->GetCurrentPlayer()->Move(pGrid, diceNumber);
	//turnCount
	//pGrid->GetCurrentPlayer()->GetTurnCount() - 1;
	//pGrid->GetCurrentPlayer()->
	//pPlayer->GetTurnCount() -1;
}


void CardSeven::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardSeven::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardSeven::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


void CardSeven::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << endl;
}

void CardSeven::Read(ifstream& Infile)
{
	
}


CardSeven:: ~CardSeven()
{}