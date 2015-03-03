#ifndef __Point2d_H__
#define __Point2d_H__

#include <math.h>
#include <iostream>


class Point2d
{
public:

	float x, y;


	bool IsZero() const
	{
		return x == 0.0f && y == 0.0f;

	}

	void SetZero()
	{
		x = y = 0.0f;

	}

	float DistanceTo(const Point2d &z)
	{
		return sqrt(((z.x - x)*(z.x - x)) + ((z.y - y)*(z.y - y)));
	}

	Point2d& Point2d::operator+ (const Point2d &z) const
	{
		Point2d tmp;
		tmp.x = x + z.x;
		tmp.y = y + z.y;
		return(tmp);
	}

	Point2d& Point2d::operator- (const Point2d &z) const
	{
		Point2d tmp;
		tmp.x = x - z.x;
		tmp.y = y - z.y;

		return(tmp);
	}

	const Point2d& Point2d::operator+= (const Point2d &z)
	{
		x += z.x;
		y += z.y;
		return *(this);
	}

	const Point2d& Point2d::operator-=(const Point2d &z)
	{
		x -= z.x;
		y -= z.y;
		return *(this);
	}

	bool Point2d::operator==(const Point2d &z) const
	{


		return (x == z.x && y == z.y);

	}

	bool Point2d::operator!=(const Point2d &z) const
	{

		return (x != z.x || y != z.y);

	}
};



#endif //__Point2d_h__