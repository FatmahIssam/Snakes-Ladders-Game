#pragma once
#include "Action.h"
#include"ApplicationManager.h"
#include "Output.h"
#include "Input.h"
#include "Grid.h"
#include <fstream>
#include "AddSnakeAction.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"
#include "CardSeven.h"
#include "CardEight.h"



class OpenAction : public Action
{
	string Name;
	GameObject* OBJ;

public:
	OpenAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~OpenAction();
};

