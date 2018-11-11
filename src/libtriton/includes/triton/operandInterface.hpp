//! \file
/*
**  Copyright (C) - Triton
**
**  This program is under the terms of the BSD License.
*/

#ifndef TRITON_OPERANDINTERFACE_H
#define TRITON_OPERANDINTERFACE_H

#include <triton/archEnums.hpp>
#include <triton/dllexport.hpp>
#include <triton/tritonTypes.hpp>



//! The Triton namespace
namespace triton {
/*!
 *  \addtogroup triton
 *  @{
 */

  //! The Triton namespace
  namespace arch {
  /*!
   *  \ingroup triton
   *  \addtogroup arch
   *  @{
   */

    /*! \interface OperandInterface
     *  \brief This interface is used for instruction operands.
     */
    class OperandInterface {
      public:
        //! Destructor.
        TRITON_EXPORT virtual ~OperandInterface() {};

        //! Returns the size (in bits) of the operand.
        TRITON_EXPORT virtual triton::uint32 getBitSize(void) const = 0;

        //! Returns the size (in bytes) of the operand.
        TRITON_EXPORT virtual triton::uint32 getSize(void) const = 0;

        //! Returns the highest bit of the operand vector.
        TRITON_EXPORT virtual triton::uint32 getHigh(void) const = 0;

        //! Returns the lower bit of the operand vector.
        TRITON_EXPORT virtual triton::uint32 getLow(void) const = 0;

        //! Returns the type of the operand (`Imm`, `Mem`, `Reg`).
        TRITON_EXPORT virtual triton::uint32 getType(void) const = 0;
    };

  /*! @} End of arch namespace */
  };
/*! @} End of triton namespace */
};

#endif /* TRITON_OPERANDINTERFACE_H */
