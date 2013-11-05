/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffFileHeader.hpp
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


#ifndef COFFFILEHEADER_HPP_
#define COFFFILEHEADER_HPP_

#include "IFileObject.hpp"
#include "ICoffFileHeader.hpp"

#include <string>
#include <cstdarg>

namespace Coff
{

class FileHeader : public ICoffFileHeader
{
public:
static ICoffFileHeader::uptr fromFileObject(IFileObject::sptr i_file);

~FileHeader(){}

private:
FileHeader(IFileObject::sptr i_file);

virtual std::string toString(void) const;
virtual std::size_t numSectionHeaders(void) const;
virtual std::size_t symbolTableOffset(void) const;
virtual std::size_t numSymbolTableEntries(void) const;
virtual bool hasOptionalHeader(void) const;
};

}


#endif /* COFFFILEHEADER_HPP_ */
