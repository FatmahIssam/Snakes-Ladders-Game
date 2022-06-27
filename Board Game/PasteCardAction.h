#pragma once
#include "Action.h"
#include"Card.h"
class PasteCardAction :public Action
{

	Card* CC3;
	
public:
	PasteCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~PasteCardAction();

};