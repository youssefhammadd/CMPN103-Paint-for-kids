#ifndef CCIRC_H
#define CCIRC_H

#include"DEFS.h"
#include "Figures/CFigure.h"
#include "GUI/Output.h"


class CCircle :public CFigure {
private:
	Point center;
	Point circomference;    //a point on the circle circomference
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void Draw(Output* pOut) const;
	virtual bool insidefig(int x,int y);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void MoveFig(Point p);
	virtual Point GetOldPoint();
	void PrintInfo(Output* pOut) ;

};


#endif

