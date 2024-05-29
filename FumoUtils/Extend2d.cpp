#include "pch.h"
#include "Extend2d.h"

namespace Geometry
{
	Point2d Extend2d::GetMinPnt() const
	{
		return m_minPnt;
	}

	void Extend2d::SetMinPnt(Point2d minPnt)
	{
		m_minPnt = minPnt;
	}

	Point2d Extend2d::GetMaxPnt() const
	{
		return m_maxPnt;
	}

	void Extend2d::SetMaxPnt(Point2d maxPnt)
	{
		m_maxPnt = maxPnt;
	}

	Extend2d::Extend2d()
	{
	}

	Extend2d::~Extend2d()
	{
	}
}