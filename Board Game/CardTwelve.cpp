#include "CardTwelve.h"



int CardTwelve::Price = -1;
int CardTwelve::Fee = -1;
Player* CardTwelve::pPointer = NULL;
CardTwelve::CardTwelve(const CellPosition& pos) :Base10To14(pos)
{
	cardNumber = 12;
	pOwner = NULL;
	cardName = "Twelve";
	IsBought = false;

}


int CardTwelve::getFee() { return CardTwelve::Fee; }
int CardTwelve::getPrice() { return CardTwelve::Price; }
void CardTwelve::setFee(int n) { CardTwelve::Fee = n; }
void CardTwelve::setPrice(int n) { CardTwelve::Price = n; }
Player* CardTwelve::getPlayer() { return CardTwelve::pPointer; }
void CardTwelve::setPlayer(Player* p) { CardTwelve::pPointer = p; }
void CardTwelve::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardTwelve::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardTwelve::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


CardTwelve::~CardTwelve(void)
{
}
