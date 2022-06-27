#include "CardTen.h"
#include"Input.h"
#include"Output.h"




int CardTen::Price = -1;
int CardTen::Fee = -1;
Player* CardTen::pPointer = NULL;
CardTen::CardTen(const CellPosition& pos) :Base10To14(pos)
{
	cardNumber = 10;
	pOwner = NULL;
	cardName = "Ten";
	IsBought = false;

}


int CardTen::getFee() { return CardTen::Fee; }
int CardTen::getPrice() { return CardTen::Price; }
void CardTen::setFee(int n) { CardTen::Fee = n; }
void CardTen::setPrice(int n) { CardTen::Price = n; }
Player* CardTen::getPlayer() { return CardTen::pPointer; }
void CardTen::setPlayer(Player* p) { CardTen::pPointer = p; }
void CardTen::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardTen::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardTen::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


CardTen::~CardTen(void)
{
}
