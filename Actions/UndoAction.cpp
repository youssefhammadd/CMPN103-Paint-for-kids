#include "UndoAction.h"
UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
}
void UndoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}
void UndoAction::Undoaction()
{

}
void UndoAction::Redoaction()
{

}
void UndoAction::Execute()
{
   pManager->UndoLastAction();
}
UndoAction::~UndoAction()
{

}