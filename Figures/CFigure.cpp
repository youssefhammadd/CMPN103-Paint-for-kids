#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

CFigure::CFigure()
{}
void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }
bool CFigure::isColorFilled()
{
	return isFilled;
}
bool CFigure::isColorDraw()
{
	return isDraw;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::SetID(int id)
{
	ID = id;
}
int CFigure::GetID()
{
	return ID;
}
void CFigure::PrintInfo(Output* pOut)
{
	string Id = to_string(ID);
	string sel = to_string(Selected);

	pOut->PrintMessage("ID:" + Id + ", selected:" + sel);

}

