#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class SaveAction :public Action
{
	string FileName;
public:
	SaveAction(ApplicationManager* pApp);
	~SaveAction();
	virtual void Execute();
	virtual void ReadActionParameters();
	virtual void Undoaction();
	virtual void Redoaction();
};

