//=================================================================================================
/*!
//  \file blaze/math/typetraits/HasResultType.h
//  \brief Header file for the HasResultType type trait
//
//  Copyright (C) 2012-2020 Klaus Iglberger - All Rights Reserved
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

#ifndef _BLAZE_MATH_TYPETRAITS_HASRESULTTYPE_H_
#define _BLAZE_MATH_TYPETRAITS_HASRESULTTYPE_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/Aliases.h>
#include <blaze/util/typetraits/IsDetected.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time check for a public nested type alias \a ResultType.
// \ingroup math_type_traits
//
// This type trait tests whether the given data type \a T provides a public nested type alias
// named \a ResultType. If it does, the \a value member constant is set to \a true, the nested
// type definition \a Type is \a TrueType, and the class derives from \a TrueType. Otherwise
// \a value is set to \a false, \a Type is \a FalseType, and the class derives from \a FalseType.

   \code
   blaze::HasResultType< StaticVector<float,3U> >::value      // Evaluates to 1
   blaze::HasResultType< const CompressedVector<int> >::Type  // Results in TrueType
   blaze::HasResultType< volatile DynamicMatrix<double> >     // Is derived from TrueType
   blaze::HasResultType< int >::value                         // Evaluates to 0
   blaze::HasResultType< const double >::Type                 // Results in FalseType
   blaze::HasResultType< volatile complex<float> >            // Is derived from FalseType
   \endcode
*/
template< typename T >
using HasResultType = IsDetected< ResultType_t, T >;
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Auxiliary variable template for the HasResultType type trait.
// \ingroup math_type_traits
//
// The HasResultType_v variable template provides a convenient shortcut to access the nested
// \a value of the HasResultType class template. For instance, given the type \a T the
// following two statements are identical:

   \code
   constexpr bool value1 = blaze::HasResultType<T>::value;
   constexpr bool value2 = blaze::HasResultType_v<T>;
   \endcode
*/
template< typename T >
constexpr bool HasResultType_v = HasResultType<T>::value;
//*************************************************************************************************

} // namespace blaze

#endif
