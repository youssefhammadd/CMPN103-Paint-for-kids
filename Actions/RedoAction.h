#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class RedoAction:public Action
{
public:
	RedoAction(ApplicationManager*pApp);
	~RedoAction();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};

