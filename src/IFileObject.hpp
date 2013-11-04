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
 *  [ ] Methods are abstract: virtual method() = 0;
 *  [ ] No ctor is defined
 *  [ ] Destructor is not abstract: virtual ~dtor();
 *  [ ] Copy operator is private and undefined: T& operator=(const T &);
 */

#ifndef IFILEOBJECT_HPP_
#define IFILEOBJECT_HPP_

#include <cstdint>
#include <cstddef>

class IFileObject
{
public:
virtual ~IFileObject(){}
//virtual const std::uint8_t * data(void) const = 0;
virtual std::size_t size(void) const = 0;
virtual std::uint8_t at(const std::size_t) const = 0;

private:
IFileObject & operator=(const IFileObject  &) = delete;
};

#endif /* IFILEOBJECT_HPP_ */
