#include"CTriangle.h"
#include"ApplicationManager.h"
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	corner1 = p1;
	corner2 = p2;
	corner3 = p3;
}
CTriangle::CTriangle()
{}

void CTriangle::Draw(Output* pOut)const {

	//Call Output::DrawRect to draw a rectangle on the screen
	pOut->DrawTri(corner1, corner2, corner3, FigGfxInfo, Selected);
}
bool CTriangle::insidefig(int x, int y)
{
	bool inside=0;
	//get the distance between each 2 corners of the triangle
	double ab = sqrt(pow(corner1.x - corner2.x, 2) + pow(corner1.y - corner2.y, 2));
	double bc = sqrt(pow(corner2.x - corner3.x, 2) + pow(corner2.y - corner3.y, 2));
	double ac = sqrt(pow(corner1.x - corner3.x, 2) + pow(corner1.y - corner3.y, 2));
	//get the distance between the point and each corner of the triangle
	double pa = sqrt(pow(corner1.x - x, 2) + pow(corner1.y - y, 2));
	double pb = sqrt(pow(corner2.x - x, 2) + pow(corner2.y - y, 2));
	double pc = sqrt(pow(corner3.x - x, 2) + pow(corner3.y - y, 2));

	if((pa+pb+pc)<=(ab+bc+ac))
		inside = 1;
	return inside;
}
void CTriangle::Save(ofstream& OutFile)  // save Triangle parameters and drawing &filling color 
{
	Output* pOut=NULL;
	OutFile << "TRIANGLE\t" << to_string(ID) << "\t" << corner1.x << "\t" << corner1.y << "\t";
	OutFile << corner2.x << "\t" <<corner2.y<< "\t";
	OutFile << corner3.x << "\t" << corner3.y << "\t";
	OutFile << pOut->color_to_string(FigGfxInfo.DrawClr) << "\t";
	OutFile << pOut->color_to_string(FigGfxInfo.FillClr) << "\t";
	OutFile << endl;
}
void CTriangle::Load(ifstream& Infile) //Load Triangle parameters and drwaing&filling color
{
	string Dc, Fc;
	Output* pOut = NULL;
	Infile >> ID >> corner1.x >> corner1.y >> corner2.x >> corner2.y >>corner3.x>>corner3.y>>Dc >> Fc;

	FigGfxInfo.DrawClr = pOut->String_to_Color(Dc);

	if (Fc == "NO_FILL")
		FigGfxInfo.isFilled = false;

	else
	{
		FigGfxInfo.FillClr = pOut->String_to_Color(Fc);
		FigGfxInfo.isFilled = true;
	}
}
Point CTriangle::GetOldPoint()
{
	Point Center;
	Center.x = (corner1.x + corner2.x + corner3.x) / 3;
	Center.y = (corner1.y + corner2.y + corner3.y) / 3;
	return Center;
}
void CTriangle::MoveFig(Point p)//, ApplicationManager* pApp)
{
	//Output* pOut=pApp->GetOutput();
	if (Selected)
	{
		Point Center;
		Center.x = (corner1.x + corner2.x + corner3.x) / 3;
		Center.y = (corner1.y + corner2.y + corner3.y) / 3;
		Point Temp1;
		Point Temp2;
		Point Temp3;
		Temp1.x = Center.x - corner1.x;
		Temp1.y = Center.y - corner1.y;
		Temp2.x = Center.x - corner2.x;
		Temp2.y = Center.y - corner2.y;
		Temp3.x = Center.x - corner3.x;
		Temp3.y = Center.y - corner3.y;
		if (Temp1.x < 0)
			corner1.x = p.x + (-1 * Temp1.x);
		else
			corner1.x = p.x - Temp1.x;
		if (Temp1.y < 0)
			corner1.y = p.y + (-1 * Temp1.y);
		else
			corner1.y = p.y - Temp1.y;
		if (Temp2.x < 0)
			corner2.x = p.x + (-1 * Temp2.x);
		else
			corner2.x = p.x - Temp2.x;
		if (Temp2.y < 0)
			corner2.y = p.y + (-1 * Temp2.y);
		else
			corner2.y = p.y - Temp2.y;

		if (Temp3.x < 0)
			corner3.x = p.x + (-1 * Temp3.x);
		else
			corner3.x = p.x - Temp3.x;
		if (Temp3.y < 0)
			corner3.y = p.y + (-1 * Temp3.y);
		else
			corner3.y = p.y - Temp3.y;

	}
}

void CTriangle::PrintInfo(Output* pOut) 
{
	CFigure::PrintInfo(pOut);

	string corner1x = to_string(corner1.x);
	string corner1y = to_string(corner1.y);
	string corner2x = to_string(corner2.x);
	string corner2y = to_string(corner2.y);
	string corner3x = to_string(corner3.x);
	string corner3y = to_string(corner3.y);

	pOut->PrintMessage("point1:(" + corner1x + "," + corner1y + ")");
	pOut->PrintMessage("point2:(" + corner2x + "," + corner2y + ")");
	pOut->PrintMessage("point3:(" + corner3x + "," + corner3y + ")");

}
