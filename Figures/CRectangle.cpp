#include "CRectangle.h"
#include "ApplicationManager.h"


CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
CRectangle::CRectangle()
{}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::insidefig(int x, int y)
{
	bool inside = 0;
	if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y)
		inside = 1;
	return inside;
}
void CRectangle::Save(ofstream& OutFile) // save Rectangle parameters and drawing &filling color 
{
	Output* pOut = NULL;
	OutFile << "RECTANGLE\t" << to_string(ID) << "\t" << Corner1.x << "\t" << Corner1.y << "\t";
	OutFile << Corner2.x << "\t" << Corner2.y << "\t";
	OutFile << pOut->color_to_string(FigGfxInfo.DrawClr) << "\t";
	OutFile << pOut->color_to_string(FigGfxInfo.FillClr) << "\t";
	OutFile << endl;
}
void CRectangle::Load(ifstream& Infile)// Load Rectangle parameters and drawing &filling color 
{
		string Dc, Fc;
		Output* pOut = NULL;
		Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Dc >> Fc;

		FigGfxInfo.DrawClr = pOut->String_to_Color(Dc);

		if (Fc == "NO_FILL")
			FigGfxInfo.isFilled = false;

		else
		{
			FigGfxInfo.FillClr =pOut->String_to_Color(Fc);
			FigGfxInfo.isFilled = true;
		}

}
Point CRectangle::GetOldPoint()
{
	Point Center;
	Center.x = (Corner2.x + Corner1.x) / 2;
	Center.y = (Corner2.y + Corner1.y) / 2;
	return Center;
}
void CRectangle::MoveFig(Point p)
{
	if (Selected)
	{
		Point Center;
		Center.x = (Corner2.x - Corner1.x) / 2;
		Center.y= (Corner2.y - Corner1.y) / 2;

		Point newcorner1;
		Point newcorner2;
		newcorner1.x = p.x - Center.x;
		newcorner1.y = p.y - Center.y;
		newcorner2.x = p.x + Center.x;
		newcorner2.y = p.y + Center.y;

		Corner1 = newcorner1;
		Corner2 = newcorner2;
	}
}

void CRectangle::PrintInfo(Output* pOut)
{
	CFigure::PrintInfo(pOut);
	string corner1x = to_string(Corner1.x);
	string corner1y = to_string(Corner1.y);
	string corner2x = to_string(Corner2.x);
	string corner2y = to_string(Corner2.y);

	double length = Corner2.x - Corner1.x;
	string lengthstr = to_string(length);

	double width = Corner2.y - Corner1.y;
	string widthstr = to_string(width);

	pOut->PrintMessage("starting point:( " + corner1x + "," + corner1y + ")");
	pOut->PrintMessage("end point:(" + corner2x + "," + corner2y + ")");
	pOut->PrintMessage("length:" + lengthstr);
	pOut->PrintMessage("width:" + widthstr);

}