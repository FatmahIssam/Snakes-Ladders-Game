#include "CardFourteen.h"


int CardFourteen::Price = -1;
int CardFourteen::Fee = -1;
Player* CardFourteen::pPointer = NULL;
CardFourteen::CardFourteen(const CellPosition& pos) : Base10To14(pos)
{
	cardNumber = 14;
	pOwner = NULL;
	cardName = "Fourteen";
	IsBought = false;

}

int CardFourteen::getFee() { return CardFourteen::Fee; }
int CardFourteen::getPrice() { return CardFourteen::Price; }
void CardFourteen::setFee(int n) { CardFourteen::Fee = n; }
void CardFourteen::setPrice(int n) { CardFourteen::Price = n; }
Player* CardFourteen::getPlayer() { return CardFourteen::pPointer; }
void CardFourteen::setPlayer(Player* p) { CardFourteen::pPointer = p; }

void CardFourteen::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardFourteen::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardFourteen::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


CardFourteen::~CardFourteen(void)
{
}
