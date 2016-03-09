//=================================================================================================
/*!
//  \file blaze/math/typetraits/IsDenseVector.h
//  \brief Header file for the IsDenseVector type trait
//
//  Copyright (C) 2013 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_TYPETRAITS_ISDENSEVECTOR_H_
#define _BLAZE_MATH_TYPETRAITS_ISDENSEVECTOR_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/expressions/DenseVector.h>
#include <blaze/util/IntegralConstant.h>
#include <blaze/util/mpl/Or.h>
#include <blaze/util/typetraits/IsBaseOf.h>
#include <blaze/util/typetraits/RemoveCV.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time check for dense vector types.
// \ingroup math_type_traits
//
// This type trait tests whether or not the given template parameter is a dense, N-dimensional
// vector type. In case the type is a dense vector type, the \a value member constant is set
// to \a true, the nested type definition \a Type is \a TrueType, and the class derives from
// \a TrueType. Otherwise \a value is set to \a false, \a Type is \a FalseType, and the class
// derives from \a FalseType.

   \code
   blaze::IsDenseVector< DynamicVector<double,false> >::value       // Evaluates to 1
   blaze::IsDenseVector< const StaticVector<float,3U,true> >::Type  // Results in TrueType
   blaze::IsDenseVector< volatile StaticVector<int,6U,true> >       // Is derived from TrueType
   blaze::IsDenseVector< CompressedVector<double,false> >::value    // Evaluates to 0
   blaze::IsDenseVector< CompressedMatrix<double,true> >::Type      // Results in FalseType
   blaze::IsDenseVector< DynamicMatrix<double,true> >               // Is derived from FalseType
   \endcode
*/
template< typename T >
struct IsDenseVector
   : public BoolConstant< Or< IsBaseOf<DenseVector<typename RemoveCV<T>::Type,false>,T>
                            , IsBaseOf<DenseVector<typename RemoveCV<T>::Type,true>,T> >::value >
{};
//*************************************************************************************************

} // namespace blaze

#endif
