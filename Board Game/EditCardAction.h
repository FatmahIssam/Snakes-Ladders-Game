#pragma once
#include "Action.h"
#include"Card.h"
#include"CellPosition.h"
class EditCardAction :
	public Action
{
	Card * CardToBeEdited ;
public:
	EditCardAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~EditCardAction(void);
};

