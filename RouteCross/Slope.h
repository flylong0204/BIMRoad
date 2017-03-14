#pragma once
#include "../include/OSGBIM/OSGBIM.h"
#include "GroundLine.h"
#include "RoadSurfaceLine.h"

class CSlope_Callback;
class ROUTECROSS_API CSlope
{
public:
	struct SlopeStruce
	{
		double m_Rgradient;
		double m_Lgradient;
		double m_Rheight;
		double m_Lheight;
		double m_LstepLength;
		double m_RstepLength;
		unsigned int m_LSlopeCount;
		unsigned int m_RSlopeCount;
		bool m_LIsZhi;
		bool m_RIsZhi;
	};
public:
	CSlope();
	CSlope(CRoadSurfaceLine* RSL, CGroundLine* GL,SlopeStruce Slopemem);
	void CalcLeftSlope();
	void CalcRightSlope();
	~CSlope();
public:
	CGroundLine *m_GL;
	CRoadSurfaceLine *m_RSL;
	osg::ref_ptr<osg::Vec3Array> m_Lpoints;
	osg::ref_ptr<osg::Vec3Array> m_Rpoints;
	double m_Left_RSLToGLDistance;
	double m_Right_RSLToGLDistance;
	SlopeStruce m_Slopemem;
	CSlope_Callback *_callback;
	osg::Group* root;
};

class CSlope_Callback :public CComponentCallback
{
public:
	CSlope_Callback(CSlope *slp):
		m_slp(slp), CComponentCallback(slp->root)
		{}
	~CSlope_Callback(){}
	virtual void DoUpdate() override;
private:
	CSlope *m_slp;
};