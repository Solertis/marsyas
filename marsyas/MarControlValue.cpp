/*
** Copyright (C) 1998-2006 George Tzanetakis <gtzan@cs.uvic.ca>
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software 
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/** 
	\class MarControlValue
	\brief Generic class for Marsyas control values
	Created by lfpt@inescporto.pt and lmartins@inescporto.pt
*/

#include "MarControlValue.h"

using namespace std;
using namespace Marsyas;

/************************************************************************/
/* MarControlValue implementation                                       */
/************************************************************************/
int
MarControlValue::getType() const
{
	return type_;
}

string 
MarControlValue::getSType() const
{
	string res;
	if(getType() == mar_null) res = "mrs_null";
	if(getType() == mar_string) res = "mrs_string";
	if(getType() == mar_real) res = "mrs_real";
	if(getType() == mar_vec) res = "mrs_realvec";
	if(getType() == mar_natural) res = "mrs_natural";
	if(getType() == mar_bool) res = "mrs_bool";
	return res; 
}

/************************************************************************/
/* MarControlValueT realvec specialization                              */
/************************************************************************/
realvec MarControlValueT<realvec>::invalidValue;

// constructor specialization for realvec
MarControlValueT<realvec>::MarControlValueT(realvec value)
{
	value_.create(value.getSize());
	value_ = value;
	type_ = mar_vec;
}

MarControlValueT<realvec>::MarControlValueT(const MarControlValueT& val)
{
	value_.create(val.value_.getSize());
	value_ = val.value_;
	type_ = mar_vec;
}

MarControlValueT<realvec>& 
MarControlValueT<realvec>::operator=(const MarControlValueT& a)
{
	if (this != &a)
	{
		value_.create(a.value_.getSize());
		value_ = a.value_;
		type_ = a.type_;
	}
	return *this;
}

MarControlValue*
MarControlValueT<realvec>::clone()
{
	return new MarControlValueT<realvec>(*this);
}

MarControlValue*
MarControlValueT<realvec>::create()
{
	return new MarControlValueT<realvec>(realvec());
}

void
MarControlValueT<realvec>::set(realvec &val)
{
	if(value_.getSize() != val.getSize()) 
	{
		value_.create(val.getSize());
	}
	value_ = val;
}

const realvec&
MarControlValueT<realvec>::get() const
{
	return value_;
}

bool
MarControlValueT<realvec>::isNotEqual(MarControlValue *v)
{
	if(this != v)//if referring to different objects, check if their contents is different...
	{
		if (type_ != mar_vec)
		{
			MRSWARN("Types of MarControlValue are different");
		}

		return value_ != dynamic_cast<MarControlValueT<realvec>*>(v)->get();
	}
	else //if v1 and v2 refer to the same object, they must be equal (=> return false)
		return false;
}

std::ostream&
MarControlValueT<realvec>::serialize(std::ostream& os)
{
	os << value_;
	return os;
}

MarControlValue*
MarControlValueT<realvec>::sum(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

MarControlValue*
MarControlValueT<realvec>::subtract(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

MarControlValue*
MarControlValueT<realvec>::multiply(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

MarControlValue*
MarControlValueT<realvec>::divide(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

/************************************************************************/
/* MarControlValueT bool specialization                                 */
/************************************************************************/
bool MarControlValueT<bool>::invalidValue;

// constructor specialization for realvec
MarControlValueT<bool>::MarControlValueT(bool value)
{
	value_ = value;
	type_ = mar_bool;
}

MarControlValueT<bool>::MarControlValueT(const MarControlValueT& val)
{
	value_ = val.value_;
	type_ = mar_bool;
}

MarControlValueT<bool>& 
MarControlValueT<bool>::operator=(const MarControlValueT& a)
{
	if (this != &a)
	{
		value_ = a.value_;
		type_ = a.type_;
	}
	return *this;
}

MarControlValue*
MarControlValueT<bool>::clone()
{
	return new MarControlValueT<bool>(*this);
}

MarControlValue*
MarControlValueT<bool>::create()
{
	return new MarControlValueT<bool>(false);
}

const bool&
MarControlValueT<bool>::get() const
{
	return value_;
}

bool
MarControlValueT<bool>::isNotEqual(MarControlValue *v)
{
	if(this != v)//if referring to different objects, check if their contents is different...
	{
		if (type_ != mar_bool)
		{
			MRSWARN("Types of MarControlValue are different");
		}

		return value_ != dynamic_cast<MarControlValueT<bool>*>(v)->get();
	}
	else //if v1 and v2 refer to the same object, they must be equal (=> return false)
		return false;
}

std::ostream&
MarControlValueT<bool>::serialize(std::ostream& os)
{
	os << value_;
	return os;
}

MarControlValue*
MarControlValueT<bool>::sum(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

MarControlValue*
MarControlValueT<bool>::subtract(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

MarControlValue*
MarControlValueT<bool>::multiply(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

MarControlValue*
MarControlValueT<bool>::divide(MarControlValue *v)
{
	MRSASSERT(0); //not implemented
	return 0;
}

