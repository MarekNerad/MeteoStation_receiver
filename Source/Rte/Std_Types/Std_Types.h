//******************************************************************************
//! \file        Std_Types.h
//! \date        12-02-2023
//! \author      Nerad
//! \brief       <MODULE_DESCRIPTION>
//******************************************************************************
//   This module is classified as QM.
//******************************************************************************
#ifndef STD_TYPES_H
#define STD_TYPES_H

//******************************************************************************
//                      Include
//******************************************************************************

//******************************************************************************
//                      Define
//******************************************************************************
#ifndef NULL_PTR
/** @brief NULL_PTR type define */
#define NULL_PTR ((void*)0)
#endif

#ifndef TRUE
/** @brief is meant to be used for type #stdBool
 *  @detail lowercase used due to generated pin configuration structure
 */
#define TRUE 1U
#else
#error "Already defined type: true !"
#endif

#ifndef FALSE
/** @brief is meant to be used for type #stdBool
 *  @detail lowercase used due to generated pin configuration structure
 */
#define FALSE 0U
#else
#error "Already defined type: false !"
#endif

/** @brief maximum value for defined #uint8 */
#define STD_UINT8_MAX 0xFFU
/** @brief minimum value for defined #uint8 */
#define STD_UINT8_MIN 0x0U
/** @brief maximum value for defined #uint16 */
#define STD_UINT16_MAX 0xFFFFU
/** @brief minimum value for defined #uint16 */
#define STD_UINT16_MIN 0x0U
/** @brief maximum value for defined #uint32 */
#define STD_UINT32_MAX 0xFFFFFFFFU
/** @brief minimum value for defined #uint32 */
#define STD_UINT32_MIN 0x0U
/** @brief maximum value for defined #sint8 */
#define STD_SINT8_MAX 127
/** @brief minimum value for defined #sint8 */
#define STD_SINT8_MIN -128
/** @brief maximum value for defined #sint16 */
#define STD_SINT16_MAX 32767
/** @brief minimum value for defined #sint16 */
#define STD_SINT16_MIN -32768
/** @brief maximum value for defined #sint32 */
#define STD_SINT32_MAX 2147483647
/** @brief minimum value for defined #sint32 */
#define STD_SINT32_MIN -2147483648

//******************************************************************************
//                      Define with parameter
//******************************************************************************

//******************************************************************************
//                      Enumeration
//******************************************************************************

//******************************************************************************
//                      Structure
//******************************************************************************

//******************************************************************************
//                      Typedef
//******************************************************************************

/** @brief typedef shall be only #true or #false */
typedef unsigned char stdBool;
/** @brief typedef shall be used for values #UINT8_MIN - #UINT8_MAX */
typedef unsigned char uint8;
/** @brief typedef shall be used for values #UINT16_MIN - #UINT16_MAX */
typedef unsigned short uint16;
/** @brief typedef shall be used for values #UINT32_MIN - #UINT32_MAX */
typedef unsigned long uint32;
/** @brief typedef shall be used for values #SINT8_MIN - #SINT8_MAX */
typedef signed char sint8;
/** @brief typedef shall be used for values #SINT16_MIN - #SINT16_MAX */
typedef signed short sint16;
/** @brief typedef shall be used for values #SINT32_MIN - #SINT32_MAX */
typedef signed long sint32;

//******************************************************************************
//                      Declaration of global variable
//******************************************************************************

//******************************************************************************
//                      Declaration of global function
//******************************************************************************

//******************************************************************************
//                      Declaration of inline function
//******************************************************************************

//******************************************************************************
//                      Definition of inline function
//******************************************************************************

#endif // STD_TYPES_H
