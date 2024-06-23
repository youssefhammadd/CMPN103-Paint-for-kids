#include"CCircle.h"
#include"ApplicationManager.h"
CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = p1;
	circomference = p2;
}
CCircle::CCircle()
{}
void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen
	pOut->DrawCirc(center, circomference, FigGfxInfo,Selected);
}
bool CCircle::insidefig(int x, int y)
{
	bool inside = 0;
	double radius;
	radius = sqrt(pow(center.y - circomference.y, 2) + pow(center.x - circomference.x, 2));
	if((pow(x-center.x,2)+pow(y-center.y,2))<=pow(radius,2))
		inside = 1;
	return inside;
}
void CCircle::Save(ofstream& OutFile)   // save Circle figure and parameters and drawing and filled color 
{
	Output* pOut =NULL;
	OutFile << "CIRCLE\t" << to_string(ID) << "\t" << center.x << "\t" << center.y << "\t";
	OutFile  << circomference.x << "\t" << circomference.y << "\t";
	string DrawColor = pOut->color_to_string(FigGfxInfo.DrawClr);
	OutFile << DrawColor << "\t";
	string Filledcolor = pOut->color_to_string(FigGfxInfo.FillClr);
	OutFile << Filledcolor << "\t";
	OutFile << endl;
}
void CCircle::Load(ifstream& Infile)
{
	string Dc, Fc;
	Output* pOut = NULL;
	Infile >> ID >> center.x >> center.y >> circomference.x >> circomference.y >> Dc >> Fc;

	FigGfxInfo.DrawClr = pOut->String_to_Color(Dc);

	if (Fc == "NO_FILL")
		FigGfxInfo.isFilled = false;

	else
	{
		FigGfxInfo.FillClr = pOut->String_to_Color(Fc);
		FigGfxInfo.isFilled = true;
	}
}
Point CCircle::GetOldPoint()
{
	return center;
}
void CCircle::MoveFig(Point p)    
{
	if (Selected)
	{
		Point Temp1;
		Point Temp2;
		Temp1.x = center.x - circomference.x;
		Temp1.y = center.y - circomference.y;
		Temp2.x = p.x + Temp1.x;
		Temp2.y = p.y + Temp1.y;
		center = p;
		circomference = Temp2;
	}
}
void CCircle::PrintInfo(Output*pOut) 
{
	CFigure::PrintInfo(pOut);
	
	string centerstrx = to_string(center.x);
	string centerstry = to_string(center.y);
	string circomstrx = to_string(circomference.x);
	string circomstry = to_string(circomference.y);
	double radius;
	radius = sqrt(pow(center.y - circomference.y, 2) + pow(center.x - circomference.x, 2));
	string radiusstr = to_string(radius);

	pOut->PrintMessage("center:(" + centerstrx + "," + centerstry + ")" );
	pOut->PrintMessage("radius:" + radiusstr);
	
}
