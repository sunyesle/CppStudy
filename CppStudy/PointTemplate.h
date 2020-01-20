#ifndef __POINT_TEMPLATE__
#define __POINT_TEMPLATE__

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition()	const;
};

#endif