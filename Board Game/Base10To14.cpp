#include "Base10To14.h"


Base10To14::Base10To14(const CellPosition& pos) :Card(pos)
{
}

void Base10To14::ReadCardParameters(Grid* pGrid) {

	Output* pOut = pGrid->GetOutput();
	if (!(this->Validate())) {
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("New Card " + cardName + ".Enter The price required to buy card.");
		this->setPrice(pIn->GetInteger(pOut));
		pOut->PrintMessage("Enter the Fee players will pay if they pass on card.");
		this->setFee(pIn->GetInteger(pOut));

		pOut->ClearStatusBar();
	}
	else pGrid->PrintErrorMessage("Parameters previously set . Price " + to_string(this->getPrice()) + " Fee : " + to_string(this->getFee()));

}

void Base10To14::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);

	if ((this->getPlayer())) {
		if (this->getPlayer() == pPlayer) {
			pGrid->PrintErrorMessage("This player is the owner of the card. No changes will happen");
			return;
		}
		else
		{
			pGrid->PrintErrorMessage(to_string(this->getFee()) + " will be removed from your wallet");
			pPlayer->SetWallet(pPlayer->GetWallet() - this->getFee());

		}



	}
	else
	{
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		pOut->PrintMessage("Nobody owns this card.would you like to buy it for " + to_string(this->getPrice()) + " Passing Fee : " + to_string(this->getFee()) + " (y/n)?");
		string yOrn = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
		if (yOrn == "y" || yOrn == "Y") {
			if (pPlayer->GetWallet() >= this->getPrice()) {
				pGrid->PrintErrorMessage("Card Succesfully bought.Click to Continue");
				this->setPlayer(pPlayer);
				IsBought = true;
				pPlayer->SetWallet(pPlayer->GetWallet() - this->getPrice());

			}
			else pGrid->PrintErrorMessage("Not enough coins to buy the card !!");


		}
		else return;



	}

}

void Base10To14::Edit(Grid* pGrid) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Editing Card " + cardName + " . Enter the new price for the Card.");
	int tstPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter the Fee that the player will pay for Card " + cardName + ".");
	int tstFee = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
	if (tstFee <= 0 || tstPrice <= 0) {
		pGrid->PrintErrorMessage("Invalid Values for Price or Fee. No changes will happen . Click to continue .");
		return;
	}
	else pGrid->PrintErrorMessage("Card Successfully Edited . Click to continue .");
	this->setPrice(tstPrice); this->setFee(tstFee);

}

bool Base10To14::Validate() {
	if (this->getFee() <= 0 || this->getPrice() < 0) {
		return false;
	}
	return true;
}

void Base10To14::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << getPrice() << "\t" << getFee() << endl;
}

void Base10To14::Read(ifstream& Infile)
{
	int price, fee;
	Infile >> price >> fee;
	setPrice(price);
	setFee(fee);
}

Base10To14::~Base10To14(void)
{
}