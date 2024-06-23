 #pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class LoadAction : public Action
{
	string FileName;
public:
	LoadAction(ApplicationManager* pApp);
	~LoadAction();
	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};

