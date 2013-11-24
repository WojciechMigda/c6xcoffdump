/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: ICoffFileHeader.hpp
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
 * 2013-11-04   wm              Initial version
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

#ifndef ICOFFFILEHEADER_HPP_
#define ICOFFFILEHEADER_HPP_

#include <cstdarg>
#include <string>
#include <memory>

class ICoffFileHeader
{
public:
typedef std::unique_ptr<ICoffFileHeader> uptr;
typedef std::shared_ptr<ICoffFileHeader> sptr;
typedef std::size_t                      size_type;

virtual ~ICoffFileHeader(){}

virtual size_type sectionHeadersNum(void) const = 0;
virtual size_type symbolTableOffset(void) const = 0;
virtual size_type symbolTableEntriesNum(void) const = 0;
virtual bool hasOptionalHeader(void) const = 0;
virtual size_type size(void) const = 0;

virtual std::string toString(void) const = 0;

private:
ICoffFileHeader & operator=(const ICoffFileHeader &) = delete;
};

#endif /* ICOFFFILEHEADER_HPP_ */
