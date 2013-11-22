/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: IFileObject.hpp
 *
 * Description:
 *      description
 *
 * Authors:
 *          Wojciech Migda (wm)
 *
 *******************************************************************************
 * History:
 * --------
 * Date         Who  Ticket     Description
 * ----------   ---  ---------  ------------------------------------------------
 * 2013-11-03   wm              Initial version
 *
 ******************************************************************************/

/*
 *  Interface class Checklist:
 *  ==========================
 *  [x] Methods are abstract: virtual method() = 0;
 *  [x] No ctor is defined
 *  [x] Destructor is not abstract: virtual ~dtor();
 *  [x] Copy operator is private and undefined: T& operator=(const T &);
 */

#ifndef IFILEOBJECT_HPP_
#define IFILEOBJECT_HPP_

#include <cstdint>
#include <cstddef>
#include <memory>

class IFileObject
{
public:
typedef std::unique_ptr<IFileObject>    uptr;
typedef std::shared_ptr<IFileObject>    sptr;
typedef std::size_t                     size_type;
typedef std::uint8_t                    byte_type;
typedef std::uint8_t *                  byte_ptr;

virtual ~IFileObject(){}

virtual size_type size(void) const = 0;
virtual byte_type at(size_type const i_pos) const = 0;
virtual size_type read(byte_ptr const o_buf, size_type const i_size, size_type const i_offset) const = 0;

private:
IFileObject & operator=(const IFileObject  &) = delete;
};

#endif /* IFILEOBJECT_HPP_ */
