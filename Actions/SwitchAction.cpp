#include "SwitchAction.h"
#include "GUI/UI_Info.h"
SwitchAction::SwitchAction(ApplicationManager*pApp):Action(pApp)
{

}
SwitchAction::~SwitchAction()
{

}
void SwitchAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}
void SwitchAction::Undoaction()
{

}
void SwitchAction::Redoaction()
{

}
void SwitchAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (UI.InterfaceMode == MODE_DRAW)
	{
		pOut->PrintMessage("Switch to Play Mode");
		pOut->ClearToolBar();
		pOut->CreatePlayToolBar();
		UI.InterfaceMode = MODE_PLAY;
	}
	else
	{
		pOut->PrintMessage("Switch to Draw Mode.");
		pOut->ClearToolBar();
		pOut->CreateDrawToolBar();
		UI.InterfaceMode = MODE_DRAW;
	}
}