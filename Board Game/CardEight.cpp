#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) :Card(pos)
{
	cardNumber = 8;
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

}



void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	pGrid->PrintErrorMessage(" You wont roll dice the next turn :( ");
	//pGrid->GetCurrentPlayer()->Move(pGrid, 0);
	pPlayer->SetZeroRoll();
	//pGrid->AdvanceCurrentPlayer();
	pOut->ClearStatusBar();
}

void CardEight::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardEight::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardEight::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


void CardEight::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << endl;
}

void CardEight::Read(ifstream& Infile)
{
	
}

CardEight::~CardEight()
{}