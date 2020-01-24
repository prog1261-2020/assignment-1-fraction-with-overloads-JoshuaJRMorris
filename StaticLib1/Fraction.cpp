/*
* @file <FunctionOverloading>
*
* @author  <Joshua Morris joshuajrmorris@gmail.com>
* @version <1.0>
*
* change log
* name  J Morris    date 2016/01/23
*
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  < Fraction class with ALL of the opertors overloaded>
*
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/
//
//
//

#include "Fraction.h"
#include <sstream>
#include <cmath>
#include <iostream>

//Fraction constructor
Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom)
{
	//9-18 tests for negatives and zeros
	if (numerator < 0) {
		numerator = numerator * -1;
	}
	if (denominator < 0) {
		denominator = denominator * -1;
	}
	if (denominator == 0) {
		denominator = 1;
	}
	reduce();
}							

//greatest common denominator function
int gcd(int numerator, int denominator) {
	if (denominator == 0)
		return numerator;
	else
		return gcd(denominator, numerator % denominator);
}

//reduce function
void Fraction::reduce()
{
	if (numerator != 0 && denominator != 0) {
		int d = gcd(numerator, denominator);
		numerator /= d;
		denominator /= d;
	}
}

//equal to
bool Fraction::operator==(const Fraction& other) const
{
		return (numerator == other.numerator && denominator == other.denominator);
}

//not equal to
bool Fraction::operator!=(const Fraction& other) const
{
	return !((*this) == other);
}

//lesser than
bool Fraction::operator<(const Fraction& other) const
{
	return (numerator < other.numerator) || (denominator < other.denominator);
}

//greater than
bool Fraction::operator>(const Fraction& other) const
{
	return !(numerator < other.numerator) || (denominator < other.denominator);
}

//lesser than or equal to
bool Fraction::operator<=(const Fraction& other) const
{
	return (numerator < other.numerator && denominator < other.denominator) ||
		(numerator == other.numerator && denominator == other.denominator);
}

//greater than or equal to
bool Fraction::operator>=(const Fraction& other) const
{
	return (((*this) == other) || !((*this) < other));
}

//subtraction operator
Fraction Fraction::operator-(const Fraction other) const
{
	Fraction result(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
	return result;
}

//addition operator
Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction tmp(1, 1);
	tmp.numerator = numerator * other.denominator + other.numerator * denominator;
	tmp.denominator = denominator * other.denominator;

	return tmp;
}

//addition-equals operator
Fraction& Fraction::operator+=(const Fraction& other)
{
	numerator = numerator * other.denominator + other.numerator * denominator;
	denominator = denominator * other.denominator;
	return *this;
}

//subtraction-equals operator
Fraction Fraction::operator-=(const Fraction other) 
{
	numerator = numerator * other.denominator - other.numerator * denominator;
	denominator = denominator * other.denominator;
	return *this;
}

//multiplication operator
Fraction Fraction::operator*(const Fraction other) const
{
	Fraction result(numerator * other.numerator, denominator * other.denominator);
	return result;
}

//multiplication-equals operator
Fraction Fraction::operator*=(const Fraction other) 
{
	numerator = numerator * other.numerator;
	denominator = denominator * other.denominator;
	return *this;
}

//division operator
Fraction Fraction::operator/(const Fraction other) const
{
	Fraction result(numerator * other.denominator, denominator * other.numerator);
	return result;
}

//division-equals operator
Fraction Fraction::operator/=(const Fraction other)
{
	numerator = numerator * other.denominator;
	denominator = denominator * other.numerator;
	reduce();
	return *this;
}

//lesser than Fraction to Int
bool operator<(const Fraction lhs, const int rhs)
{
	return (lhs.numerator && lhs.denominator < rhs);
}

//lesser than Int to Fraction
bool operator<(const int lhs, const Fraction rhs)
{
	return (lhs < rhs.numerator && rhs.denominator);
}

//greater than Fraction to Int
bool operator>(const Fraction lhs, const int rhs)
{
	return !(lhs.numerator && lhs.denominator < rhs);
}

//greater than Int to Fraction
bool operator>(const int lhs, const Fraction rhs)
{
	return !(lhs < rhs.numerator && rhs.denominator);
}

//addition Fraction to Int
Fraction operator+(Fraction lhs, int rhs)
{
	Fraction tmp(1, 1);
	tmp.numerator = lhs.numerator * rhs + rhs * lhs.denominator;
	tmp.denominator = lhs.denominator * rhs;
	return tmp;
}

//addition Int to Fraction
Fraction operator+(int lhs, Fraction rhs)
{
	Fraction tmp(1, 1);
	tmp.numerator = rhs.numerator * lhs + lhs * rhs.denominator;
	tmp.denominator = rhs.denominator * lhs;
	return tmp;
}

//subtraction Fraction to Int
Fraction operator-(Fraction lhs, int rhs)
{
	Fraction result(lhs.numerator * rhs - rhs * lhs.denominator, lhs.denominator * rhs);
	return result;
}

//subtraction Int to Fraction
Fraction operator-(int lhs, Fraction rhs)
{
	Fraction result( lhs * rhs.numerator, rhs.denominator * lhs);
	return result;
}

//multiplication Fraction to Int
Fraction operator*(Fraction lhs, int rhs)
{
	Fraction result(lhs.numerator *rhs, lhs.denominator * 1);
	return result;
}

//multiplication Int to Fraction
Fraction operator*(int lhs, Fraction rhs)
{
	Fraction result(rhs.numerator * lhs, rhs.denominator * 1);	
	return result;
}

//addition-equals Fraction to Int
Fraction operator+=(Fraction lhs, int rhs)
{
	Fraction tmp(1, 1);
	tmp.numerator = lhs.numerator * rhs + rhs * lhs.denominator;			
	tmp.denominator = lhs.denominator * rhs;
	
	return tmp;
}

//subtraction-equals Fraction to Int
Fraction operator-=(Fraction lhs, int rhs)
{
	Fraction result(lhs.numerator * rhs - rhs * lhs.denominator, lhs.denominator * rhs);
	return result;
}

//multiplication-equals Fraction to Int
Fraction operator*=(Fraction lhs, int rhs)
{
	Fraction result(lhs.numerator * rhs, lhs.denominator * 1);									
	return result;
}

//division Fraction to Int
Fraction operator/(Fraction lhs, int rhs)
{
	Fraction result(lhs.numerator * rhs, lhs.denominator * rhs);					
	return result;
}

//division Int to Fraction
Fraction operator/(int lhs, Fraction rhs)
{
	Fraction result(rhs.numerator * lhs, rhs.denominator * lhs);				
	return result;
}

//division-equals Fraction to Int
Fraction operator/=(Fraction lhs, int rhs)
{
	Fraction result
		((lhs.numerator * rhs),	(lhs.denominator * rhs));
	return result;
}



//std::ostream& operator<<(std::ostream& os, const Fraction& rhs)
//{
//	os << "(" << rhs._x << ", " << rhs._y << ")";
//	return os;
//}

//std::istream& operator>>(std::istream& is, Fraction& rhs)
//{
//	char L;
//	is >> L >> rhs._x >> L >> rhs._y >> L;
//	return is;
//}
