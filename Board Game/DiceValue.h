#pragma once
#include "RollDiceAction.h"
#include "Grid.h"
#include "Player.h"
#include "Card.h"
#include "DEFS.h"
#include "Ladder.h"

class DiceValue : public Action
{
	int diceNumber;

public:
	DiceValue(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~DiceValue();
};

