#include "pch.h"
#include "FmGeExtend2d.h"

namespace Geometry
{
	FmGePoint2d FmGeExtend2d::GetMinPnt() const
	{
		return m_minPnt;
	}

	void FmGeExtend2d::SetMinPnt(FmGePoint2d minPnt)
	{
		m_minPnt = minPnt;
	}

	FmGePoint2d FmGeExtend2d::GetMaxPnt() const
	{
		return m_maxPnt;
	}

	void FmGeExtend2d::SetMaxPnt(FmGePoint2d maxPnt)
	{
		m_maxPnt = maxPnt;
	}

	FmGeExtend2d::FmGeExtend2d(FmGePoint2d minPnt, FmGePoint2d maxPnt)
	{
		m_minPnt = minPnt;
		m_maxPnt = maxPnt;
	}

	FmGeExtend2d::~FmGeExtend2d()
	{
	}
}