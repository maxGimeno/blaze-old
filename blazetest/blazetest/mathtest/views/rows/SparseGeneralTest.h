//=================================================================================================
/*!
//  \file blazetest/mathtest/views/rows/SparseGeneralTest.h
//  \brief Header file for the Rows sparse general test
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

#ifndef _BLAZETEST_MATHTEST_VIEWS_ROWS_SPARSEGENERALTEST_H_
#define _BLAZETEST_MATHTEST_VIEWS_ROWS_SPARSEGENERALTEST_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <sstream>
#include <stdexcept>
#include <string>
#include <blaze/math/constraints/ColumnMajorMatrix.h>
#include <blaze/math/constraints/RowMajorMatrix.h>
#include <blaze/math/constraints/SparseMatrix.h>
#include <blaze/math/CompressedMatrix.h>
#include <blaze/math/Rows.h>
#include <blazetest/system/Types.h>


namespace blazetest {

namespace mathtest {

namespace views {

namespace rows {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Auxiliary class for all tests of the sparse general Rows specialization.
//
// This class represents a test suite for the blaze::Rows class template specialization for
// sparse general matrices. It performs a series of both compile time as well as runtime tests.
*/
class SparseGeneralTest
{
 public:
   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit SparseGeneralTest();
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

 private:
   //**Test functions******************************************************************************
   /*!\name Test functions */
   //@{
   void testConstructors();
   void testAssignment();
   void testAddAssign();
   void testSubAssign();
   void testSchurAssign();
   void testMultAssign();
   void testScaling();
   void testFunctionCall();
   void testIterator();
   void testNonZeros();
   void testReset();
   void testClear();
   void testReserve();
   void testTrim();
   void testSet();
   void testInsert();
   void testAppend();
   void testErase();
   void testFind();
   void testLowerBound();
   void testUpperBound();
   void testTranspose();
   void testCTranspose();
   void testIsDefault();
   void testIsSame();
   void testSubmatrix();
   void testRow();
   void testRows();
   void testColumn();
   void testColumns();
   void testBand();

   template< typename Type >
   void checkRows( const Type& matrix, size_t expectedRows ) const;

   template< typename Type >
   void checkColumns( const Type& matrix, size_t expectedColumns ) const;

   template< typename Type >
   void checkCapacity( const Type& matrix, size_t minCapacity ) const;

   template< typename Type >
   void checkCapacity( const Type& matrix, size_t index, size_t minCapacity ) const;

   template< typename Type >
   void checkNonZeros( const Type& matrix, size_t expectedNonZeros ) const;

   template< typename Type >
   void checkNonZeros( const Type& matrix, size_t index, size_t expectedNonZeros ) const;
   //@}
   //**********************************************************************************************

   //**Utility functions***************************************************************************
   /*!\name Utility functions */
   //@{
   void initialize();
   //@}
   //**********************************************************************************************

   //**Type definitions****************************************************************************
   using MT  = blaze::CompressedMatrix<int,blaze::rowMajor>;  //!< Row-major compressed matrix type.
   using OMT = MT::OppositeType;                              //!< Column-major compressed matrix type.
   using RT  = blaze::Rows<MT>;                               //!< Sparse rows type for row-major matrices.
   using ORT = blaze::Rows<OMT>;                              //!< Sparse rows type for column-major matrices.
   //**********************************************************************************************

   //**Member variables****************************************************************************
   /*!\name Member variables */
   //@{
   MT  mat_;   //!< Row-major dynamic matrix.
               /*!< The \f$ 5 \times 4 \f$ matrix is initialized as
                    \f[\left(\begin{array}{*{4}{c}}
                     0 &  0 &  0 &  0 \\
                     0 &  1 &  0 &  0 \\
                    -2 &  0 & -3 &  0 \\
                     0 &  4 &  5 & -6 \\
                     7 & -8 &  9 & 10 \\
                    \end{array}\right)\f]. */
   OMT tmat_;  //!< Column-major dynamic matrix.
               /*!< The \f$ 5 \times 4 \f$ matrix is initialized as
                    \f[\left(\begin{array}{*{4}{c}}
                     0 &  0 &  0 &  0 \\
                     0 &  1 &  0 &  0 \\
                    -2 &  0 & -3 &  0 \\
                     0 &  4 &  5 & -6 \\
                     7 & -8 &  9 & 10 \\
                    \end{array}\right)\f]. */

   std::string test_;  //!< Label of the currently performed test.
   //@}
   //**********************************************************************************************

   //**Compile time checks*************************************************************************
   /*! \cond BLAZE_INTERNAL */
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( MT  );
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( OMT );
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( RT  );
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( ORT );

   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( MT  );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( OMT );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( RT  );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( ORT );
   /*! \endcond */
   //**********************************************************************************************
};
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Checking the number of rows of the given sparse matrix.
//
// \param matrix The sparse matrix to be checked.
// \param expectedRows The expected number of rows of the sparse matrix.
// \return void
// \exception std::runtime_error Error detected.
//
// This function checks the number of rows of the given sparse matrix. In case the
// actual number of rows does not correspond to the given expected number of rows, a
// \a std::runtime_error exception is thrown.
*/
template< typename Type >  // Type of the sparse matrix
void SparseGeneralTest::checkRows( const Type& matrix, size_t expectedRows ) const
{
   using blaze::rows;

   if( rows( matrix ) != expectedRows ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid number of rows detected\n"
          << " Details:\n"
          << "   Number of rows         : " << rows( matrix ) << "\n"
          << "   Expected number of rows: " << expectedRows << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Checking the number of columns of the given sparse matrix.
//
// \param matrix The sparse matrix to be checked.
// \param expectedColumns The expected number of columns of the sparse matrix.
// \return void
// \exception std::runtime_error Error detected.
//
// This function checks the number of columns of the given sparse matrix. In case the
// actual number of columns does not correspond to the given expected number of columns,
// a \a std::runtime_error exception is thrown.
*/
template< typename Type >  // Type of the sparse matrix
void SparseGeneralTest::checkColumns( const Type& matrix, size_t expectedColumns ) const
{
   using blaze::columns;

   if( columns( matrix ) != expectedColumns ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid number of columns detected\n"
          << " Details:\n"
          << "   Number of columns         : " << columns( matrix ) << "\n"
          << "   Expected number of columns: " << expectedColumns << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Checking the capacity of the given sparse matrix.
//
// \param matrix The sparse matrix to be checked.
// \param minCapacity The expected minimum capacity of the sparse matrix.
// \return void
// \exception std::runtime_error Error detected.
//
// This function checks the capacity of the given sparse matrix. In case the actual capacity
// is smaller than the given expected minimum capacity, a \a std::runtime_error exception is
// thrown.
*/
template< typename Type >  // Type of the sparse matrix
void SparseGeneralTest::checkCapacity( const Type& matrix, size_t minCapacity ) const
{
   using blaze::capacity;

   if( capacity( matrix ) < minCapacity ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid capacity detected\n"
          << " Details:\n"
          << "   Capacity                 : " << capacity( matrix ) << "\n"
          << "   Expected minimum capacity: " << minCapacity << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Checking the capacity of a specific row/column of the given sparse matrix.
//
// \param matrix The sparse matrix to be checked.
// \param index The row/column to be checked.
// \param minCapacity The expected minimum capacity of the specified row/column.
// \return void
// \exception std::runtime_error Error detected.
//
// This function checks the capacity of a specific row/column of the given sparse matrix.
// In case the actual capacity is smaller than the given expected minimum capacity, a
// \a std::runtime_error exception is thrown.
*/
template< typename Type >  // Type of the compressed matrix
void SparseGeneralTest::checkCapacity( const Type& matrix, size_t index, size_t minCapacity ) const
{
   using blaze::capacity;

   if( capacity( matrix, index ) < minCapacity ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid capacity detected in "
          << ( blaze::IsRowMajorMatrix<Type>::value ? "row " : "column " ) << index << "\n"
          << " Details:\n"
          << "   Capacity                 : " << capacity( matrix, index ) << "\n"
          << "   Expected minimum capacity: " << minCapacity << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Checking the number of non-zero elements of the given sparse matrix.
//
// \param matrix The sparse matrix to be checked.
// \param expectedNonZeros The expected number of non-zero elements of the sparse matrix.
// \return void
// \exception std::runtime_error Error detected.
//
// This function checks the number of non-zero elements of the given sparse matrix. In
// case the actual number of non-zero elements does not correspond to the given expected
// number, a \a std::runtime_error exception is thrown.
*/
template< typename Type >  // Type of the sparse matrix
void SparseGeneralTest::checkNonZeros( const Type& matrix, size_t expectedNonZeros ) const
{
   using blaze::capacity;
   using blaze::nonZeros;

   if( nonZeros( matrix ) != expectedNonZeros ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid number of non-zero elements\n"
          << " Details:\n"
          << "   Number of non-zeros         : " << nonZeros( matrix ) << "\n"
          << "   Expected number of non-zeros: " << expectedNonZeros << "\n";
      throw std::runtime_error( oss.str() );
   }

   if( capacity( matrix ) < nonZeros( matrix ) ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid capacity detected\n"
          << " Details:\n"
          << "   Number of non-zeros: " << nonZeros( matrix ) << "\n"
          << "   Capacity           : " << capacity( matrix ) << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Checking the number of non-zero elements in a specific row/column of the given sparse matrix.
//
// \param matrix The sparse matrix to be checked.
// \param index The row/column to be checked.
// \param expectedNonZeros The expected number of non-zero elements in the specified row/column.
// \return void
// \exception std::runtime_error Error detected.
//
// This function checks the number of non-zero elements in the specified row/column of the
// given sparse matrix. In case the actual number of non-zero elements does not correspond
// to the given expected number, a \a std::runtime_error exception is thrown.
*/
template< typename Type >  // Type of the sparse matrix
void SparseGeneralTest::checkNonZeros( const Type& matrix, size_t index, size_t expectedNonZeros ) const
{
   using blaze::capacity;
   using blaze::nonZeros;

   if( nonZeros( matrix, index ) != expectedNonZeros ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid number of non-zero elements in "
          << ( blaze::IsRowMajorMatrix<Type>::value ? "row " : "column " ) << index << "\n"
          << " Details:\n"
          << "   Number of non-zeros         : " << nonZeros( matrix, index ) << "\n"
          << "   Expected number of non-zeros: " << expectedNonZeros << "\n";
      throw std::runtime_error( oss.str() );
   }

   if( capacity( matrix, index ) < nonZeros( matrix, index ) ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Invalid capacity detected in "
          << ( blaze::IsRowMajorMatrix<Type>::value ? "row " : "column " ) << index << "\n"
          << " Details:\n"
          << "   Number of non-zeros: " << nonZeros( matrix, index ) << "\n"
          << "   Capacity           : " << capacity( matrix, index ) << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Testing the functionality of the sparse general Rows specialization.
//
// \return void
*/
void runTest()
{
   SparseGeneralTest();
}
//*************************************************************************************************




//=================================================================================================
//
//  MACRO DEFINITIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Macro for the execution of the Rows sparse general test.
*/
#define RUN_ROWS_SPARSEGENERAL_TEST \
   blazetest::mathtest::views::rows::runTest()
/*! \endcond */
//*************************************************************************************************

} // namespace rows

} // namespace views

} // namespace mathtest

} // namespace blazetest

#endif
