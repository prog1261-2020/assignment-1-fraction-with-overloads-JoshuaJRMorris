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

#pragma once

#include <string>
#include <sstream>
class Fraction
{
public:
	Fraction(int, int);

	bool operator ==(const Fraction& other) const;					//equal to
	bool operator !=(const Fraction& other) const;					//not equal
	bool operator <(const Fraction& other) const;					//less than
	bool operator >(const Fraction& other) const;					//greater than
	bool operator <=(const Fraction& other) const;					//less than or equal to
	bool operator >=(const Fraction& other) const;					//greater than or equal to
	friend bool operator<(const Fraction lhs, const int rhs);		//lesser than Fraction to Int
	friend bool operator<(const int rhs, const Fraction lhs);		//lesser than Int to Fraction
	friend bool operator>(const Fraction lhs, const int rhs);		//greater than Fraction to Int
	friend bool operator>(const int rhs, const Fraction lhs);		//greater than Int to Fraction



	Fraction operator -(const Fraction other)const;					//subtraction operator
	Fraction operator +(const Fraction& other) const;				//addition operator
	Fraction& operator +=(const Fraction& other);					//addition-equals operator
	Fraction operator -=(const Fraction other);						//subtraction-equals operator
	Fraction operator *(const Fraction other)const;					//multiplication operator
	Fraction operator *=(const Fraction other);						//multiplication-equals operator
	Fraction operator /(const Fraction other)const;					//division operator
	Fraction operator /=(const Fraction other);						//division equals operator
	
	friend Fraction operator+(Fraction lhs, int rhs);				//addition operator Fraction to Int
	friend Fraction operator+(int lhs, Fraction rhs);				//addition operator Int to Fraction
	friend Fraction operator-(Fraction lhs, int rhs);				//subtraction operatro Fraction to Int
	friend Fraction operator-(int lhs, Fraction rhs);				//subtraction operator Int to Fraction
	friend Fraction operator*(Fraction lhs, int rhs);				//multiplication operator Fraction to Int
	friend Fraction operator*(int lhs, Fraction rhs);				//multiplication operator Int to Fraction
	friend Fraction operator/(Fraction lhs, int rhs);				//division operator Fraction to Int
	friend Fraction operator/(int lhs, Fraction rhs);				//division operator Int to Fraction
	friend Fraction operator+=(Fraction lhs, int rhs);				//addition-equals operator Fraction to Int
	friend Fraction operator-=(Fraction lhs, int rhs);				//subtraction-equals operator Fraction to Int
	friend Fraction operator*=(Fraction lhs, int rhs);				//multiplication-equals operator Fracion to Int
	friend Fraction operator/=(Fraction lhs, int rhs);				//division-equals operator Fraction to Int


	//friend std::ostream& operator <<(std::ostream&, const Fraction&);
	//friend std::istream& operator >>(std::istream&, Fraction&);

private:
	void reduce();

	int numerator;
	int denominator;

	int _x;
	int _y;

};



