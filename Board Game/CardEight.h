#pragma once
#include "Card.h"
class CardEight : public Card
{

public:

	CardEight(const CellPosition& pos);

	void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void CopyCard(Grid* pGrid);
	virtual void CutCard(Grid* pGrid);
	virtual void PasteCard(Grid* pGrid);
	void Save(ofstream& OutFile, TYPE CARD);
	void Read(ifstream& Infile);

	virtual ~CardEight();

};