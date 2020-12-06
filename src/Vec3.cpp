#include <cmath>
#include "Vec3.h"

Vec3::Vec3()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vec3::Vec3(float a)
{
	m_x = a;
	m_y = a;
	m_z = a;
}

Vec3::Vec3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

Vec3::~Vec3() {}

float Vec3::length()
{
	return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

void Vec3::normalize()
{
	float len = length();
	m_x /= len;
	m_y /= len;
	m_z /= len;
}

// Component-wise operations
bool operator== (const Vec3& a, const Vec3& b)
{
	if (a.m_x == b.m_x && a.m_y == b.m_y && a.m_z == b.m_z)
		return true;
	return false;
}

Vec3 operator+ (const Vec3& a, const Vec3& b)
{
	return Vec3(a.m_x + b.m_x, a.m_y + b.m_y, a.m_z + b.m_z);
}

Vec3 operator- (const Vec3& a, const Vec3& b)
{
	return Vec3(a.m_x - b.m_x, a.m_y - b.m_y, a.m_z - b.m_z);
}

Vec3 operator/ (const Vec3& a, float d)
{
	return Vec3(a.m_x / d, a.m_y / d, a.m_z / d);
}

Vec3 operator/ (const Vec3& a, const Vec3& b)
{
	return Vec3(a.m_x / b.m_x, a.m_y / b.m_y, a.m_z / b.m_z);
}

Vec3 operator* (const Vec3& a, float d)
{
	return Vec3(a.m_x * d, a.m_y * d, a.m_z * d);
}

Vec3 cross(const Vec3& a, const Vec3& b)
{
	float x, y, z;
	x = a.m_y*b.m_z - a.m_z*b.m_y;
	y = a.m_z*b.m_x - a.m_x*b.m_z;
	z = a.m_x*b.m_y - a.m_y*b.m_x;
	return Vec3(x, y, z);
}

float dot(const Vec3& a, const Vec3& b)
{
	return a.m_x*b.m_x + a.m_y*b.m_y + a.m_z*b.m_z;
}
