#pragma once
#include "Card.h"
class CardSeven : public Card
{

public:

	CardSeven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void CopyCard(Grid* pGrid);
	virtual void CutCard(Grid* pGrid);
	virtual void PasteCard(Grid* pGrid);
	void Save(ofstream& OutFile, TYPE CARD);
	void Read(ifstream& Infile);

	virtual ~CardSeven();

};