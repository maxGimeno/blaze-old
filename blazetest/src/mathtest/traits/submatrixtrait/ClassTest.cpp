//=================================================================================================
/*!
//  \file src/mathtest/traits/submatrixtrait/ClassTest.cpp
//  \brief Source file for the SubmatrixTrait class test
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


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <utility>
#include <blaze/math/CompressedMatrix.h>
#include <blaze/math/CustomMatrix.h>
#include <blaze/math/DiagonalMatrix.h>
#include <blaze/math/DynamicMatrix.h>
#include <blaze/math/HermitianMatrix.h>
#include <blaze/math/HybridMatrix.h>
#include <blaze/math/InitializerMatrix.h>
#include <blaze/math/LowerMatrix.h>
#include <blaze/math/StaticMatrix.h>
#include <blaze/math/StrictlyLowerMatrix.h>
#include <blaze/math/StrictlyUpperMatrix.h>
#include <blaze/math/SymmetricMatrix.h>
#include <blaze/math/traits/SubmatrixTrait.h>
#include <blaze/math/typetraits/StorageOrder.h>
#include <blaze/math/UniformMatrix.h>
#include <blaze/math/UniLowerMatrix.h>
#include <blaze/math/UniUpperMatrix.h>
#include <blaze/math/UpperMatrix.h>
#include <blaze/math/Views.h>
#include <blaze/math/ZeroMatrix.h>
#include <blaze/util/typetraits/IsSame.h>
#include <blaze/util/typetraits/RemoveCVRef.h>
#include <blazetest/mathtest/traits/submatrixtrait/ClassTest.h>


namespace blazetest {

namespace mathtest {

namespace traits {

namespace submatrixtrait {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the SubmatrixTrait class test.
//
// \exception std::runtime_error Error detected.
*/
ClassTest::ClassTest()
{
   testSubmatrixOperation();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the 'SubmatrixTrait' class template for submatrix operations.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a compile time test of the 'SubmatrixTrait' class template for submatrix
// operations. In case an error is detected, a compilation error is created.
*/
void ClassTest::testSubmatrixOperation()
{
   using namespace blaze;


   // StaticMatrix
   {
      {
         using MT = StaticMatrix<int,3UL,5UL,rowMajor>;
         using RT = HybridMatrix<int,3UL,5UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StaticMatrix<int,3UL,5UL,columnMajor>;
         using RT = HybridMatrix<int,3UL,5UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StaticMatrix<int,3UL,5UL,rowMajor>;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StaticMatrix<int,3UL,5UL,columnMajor>;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // HybridMatrix
   {
      {
         using MT = HybridMatrix<int,3UL,5UL,rowMajor>;
         using RT = HybridMatrix<int,3UL,5UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HybridMatrix<int,3UL,5UL,columnMajor>;
         using RT = HybridMatrix<int,3UL,5UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HybridMatrix<int,3UL,5UL,rowMajor>;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HybridMatrix<int,3UL,5UL,columnMajor>;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // DynamicMatrix
   {
      {
         using MT = DynamicMatrix<int,rowMajor>;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DynamicMatrix<int,columnMajor>;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DynamicMatrix<int,rowMajor>;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DynamicMatrix<int,columnMajor>;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // CustomMatrix
   {
      {
         using MT = CustomMatrix<int,unaligned,unpadded,rowMajor>;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = CustomMatrix<int,unaligned,unpadded,columnMajor>;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = CustomMatrix<int,unaligned,unpadded,rowMajor>;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = CustomMatrix<int,unaligned,unpadded,columnMajor>;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // UniformMatrix
   {
      {
         using MT = UniformMatrix<int,rowMajor>;
         using RT = UniformMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniformMatrix<int,columnMajor>;
         using RT = UniformMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniformMatrix<int,rowMajor>;
         using RT = UniformMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniformMatrix<int,columnMajor>;
         using RT = UniformMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // InitializerMatrix
   {
      {
         using MT = InitializerMatrix<int>;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = InitializerMatrix<int>;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // CompressedMatrix
   {
      {
         using MT = CompressedMatrix<int,rowMajor>;
         using RT = CompressedMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = CompressedMatrix<int,columnMajor>;
         using RT = CompressedMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = CompressedMatrix<int,rowMajor>;
         using RT = CompressedMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = CompressedMatrix<int,columnMajor>;
         using RT = CompressedMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // IdentityMatrix
   {
      {
         using MT = IdentityMatrix<int,rowMajor>;
         using RT = CompressedMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = IdentityMatrix<int,columnMajor>;
         using RT = CompressedMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = IdentityMatrix<int,rowMajor>;
         using RT = CompressedMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = IdentityMatrix<int,columnMajor>;
         using RT = CompressedMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // ZeroMatrix
   {
      {
         using MT = ZeroMatrix<int,rowMajor>;
         using RT = ZeroMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = ZeroMatrix<int,columnMajor>;
         using RT = ZeroMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = ZeroMatrix<int,rowMajor>;
         using RT = ZeroMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = ZeroMatrix<int,columnMajor>;
         using RT = ZeroMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // SymmetricMatrix<DynamicMatrix> (real)
   {
      {
         using MT = SymmetricMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = SymmetricMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = SymmetricMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // SymmetricMatrix<DynamicMatrix> (complex)
   {
      {
         using MT = SymmetricMatrix< DynamicMatrix<complex<int>,rowMajor> >;
         using RT = DynamicMatrix<complex<int>,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<complex<int>,columnMajor> >;
         using RT = DynamicMatrix<complex<int>,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<complex<int>,rowMajor> >;
         using RT = StaticMatrix<complex<int>,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<complex<int>,columnMajor> >;
         using RT = StaticMatrix<complex<int>,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<complex<int>,rowMajor> >;
         using RT = SymmetricMatrix< StaticMatrix<complex<int>,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< DynamicMatrix<complex<int>,columnMajor> >;
         using RT = SymmetricMatrix< StaticMatrix<complex<int>,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // SymmetricMatrix<UniformMatrix> (real)
   {
      {
         using MT = SymmetricMatrix< UniformMatrix<int,rowMajor> >;
         using RT = UniformMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< UniformMatrix<int,columnMajor> >;
         using RT = UniformMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< UniformMatrix<int,rowMajor> >;
         using RT = UniformMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< UniformMatrix<int,columnMajor> >;
         using RT = UniformMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< UniformMatrix<int,rowMajor> >;
         using RT = UniformMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< UniformMatrix<int,columnMajor> >;
         using RT = UniformMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // SymmetricMatrix<ZeroMatrix> (real)
   {
      {
         using MT = SymmetricMatrix< ZeroMatrix<int,rowMajor> >;
         using RT = ZeroMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< ZeroMatrix<int,columnMajor> >;
         using RT = ZeroMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< ZeroMatrix<int,rowMajor> >;
         using RT = ZeroMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< ZeroMatrix<int,columnMajor> >;
         using RT = ZeroMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< ZeroMatrix<int,rowMajor> >;
         using RT = ZeroMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = SymmetricMatrix< ZeroMatrix<int,columnMajor> >;
         using RT = ZeroMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // HermitianMatrix<DynamicMatrix> (symmetric)
   {
      {
         using MT = HermitianMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = SymmetricMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = SymmetricMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // HermitianMatrix<DynamicMatrix> (Hermitian)
   {
      {
         using MT = HermitianMatrix< DynamicMatrix<complex<int>,rowMajor> >;
         using RT = DynamicMatrix<complex<int>,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<complex<int>,columnMajor> >;
         using RT = DynamicMatrix<complex<int>,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<complex<int>,rowMajor> >;
         using RT = StaticMatrix<complex<int>,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<complex<int>,columnMajor> >;
         using RT = StaticMatrix<complex<int>,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<complex<int>,rowMajor> >;
         using RT = HermitianMatrix< StaticMatrix<complex<int>,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = HermitianMatrix< DynamicMatrix<complex<int>,columnMajor> >;
         using RT = HermitianMatrix< StaticMatrix<complex<int>,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // LowerMatrix<DynamicMatrix>
   {
      {
         using MT = LowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = LowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = LowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = LowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = LowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = LowerMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = LowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = LowerMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // UniLowerMatrix<DynamicMatrix>
   {
      {
         using MT = UniLowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniLowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniLowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniLowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniLowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = UniLowerMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniLowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = UniLowerMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // StrictlyLowerMatrix<DynamicMatrix>
   {
      {
         using MT = StrictlyLowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyLowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyLowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyLowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyLowerMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StrictlyLowerMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyLowerMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StrictlyLowerMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // UpperMatrix<DynamicMatrix>
   {
      {
         using MT = UpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = UpperMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = UpperMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // UniUpperMatrix<DynamicMatrix>
   {
      {
         using MT = UniUpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniUpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniUpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniUpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniUpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = UniUpperMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = UniUpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = UniUpperMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // StrictlyUpperMatrix<DynamicMatrix>
   {
      {
         using MT = StrictlyUpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyUpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyUpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyUpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyUpperMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StrictlyUpperMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = StrictlyUpperMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StrictlyUpperMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }

   // DiagonalMatrix<DynamicMatrix>
   {
      {
         using MT = DiagonalMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DynamicMatrix<int,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DiagonalMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DynamicMatrix<int,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix( std::declval<MT>(), 0UL, 1UL, 2UL, 3UL ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DiagonalMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,rowMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DiagonalMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = StaticMatrix<int,2UL,3UL,columnMajor>;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,0UL,1UL,2UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<0UL,1UL,2UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DiagonalMatrix< DynamicMatrix<int,rowMajor> >;
         using RT = DiagonalMatrix< StaticMatrix<int,3UL,3UL,rowMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
      {
         using MT = DiagonalMatrix< DynamicMatrix<int,columnMajor> >;
         using RT = DiagonalMatrix< StaticMatrix<int,3UL,3UL,columnMajor> >;
         static_assert( IsSame_v< SubmatrixTrait_t<MT,1UL,1UL,3UL,3UL>, RT >, "Non-matching type detected" );

         using Expr = RemoveCVRef_t< decltype( submatrix<1UL,1UL,3UL,3UL>( std::declval<MT>() ) ) >;
         static_assert( IsSame_v< ResultType_t<Expr>, RT >, "Non-matching type detected" );
         static_assert( StorageOrder_v<Expr> == StorageOrder_v<RT>, "Non-matching storage order detected" );
      }
   }
}
//*************************************************************************************************

} // namespace submatrixtrait

} // namespace traits

} // namespace mathtest

} // namespace blazetest




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running SubmatrixTrait class test..." << std::endl;

   try
   {
      RUN_SUBMATRIXTRAIT_CLASS_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during SubmatrixTrait class test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
