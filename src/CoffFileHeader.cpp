/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the GNU LGPL v3
 *******************************************************************************
 *
 * Filename: CoffFileHeader.cpp
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

#include "CoffFileHeader.hpp"
#include "ICoffFileHeader.hpp"
#include "IFileObject.hpp"

#include <memory>
#include <cassert>

enum
{
    COFF0_HEADER_SIZE      = 20,
    COFF1_2_HEADER_SIZE    = 22,
};

enum
{
    MAGIC_TMS320C3x     = 0x93,
    MAGIC_TMS320C4x     = 0x93,
    MAGIC_TMS470        = 0x97,
    MAGIC_TMS320C54x    = 0x98,
    MAGIC_TMS320C6x     = 0x99,
    MAGIC_TMS320C55x    = 0x9c,
    MAGIC_TMS32028      = 0x9d,
    MAGIC_MSP430        = 0xa0,
    MAGIC_TMS320C55xp   = 0xa1,
};

enum
{
    VERSION_ID_COFF1    = 0xc1,
    VERSION_ID_COFF2    = 0xc2,
};

ICoffFileHeader::uptr Coff::FileHeader::fromFileObject(IFileObject::sptr i_file)
{
    assert(i_file->at(0) == VERSION_ID_COFF1
        || i_file->at(0) == VERSION_ID_COFF2);

    assert(i_file->size() > COFF1_2_HEADER_SIZE);

    Coff::FileHeader * instance = new Coff::FileHeader{i_file};
    ICoffFileHeader::uptr   result{instance};

    return result;
}

Coff::FileHeader::FileHeader(IFileObject::sptr i_file_object) :
    ICoffFileHeader()
{
    ;
}

std::string Coff::FileHeader::toString(void) const
{
    return "dupa";
}

std::size_t Coff::FileHeader::numSectionHeaders(void) const
{
    return 0;
}

std::size_t Coff::FileHeader::symbolTableOffset(void) const
{
    return 0;
}

std::size_t Coff::FileHeader::numSymbolTableEntries(void) const
{
    return 0;
}

bool Coff::FileHeader::hasOptionalHeader(void) const
{
    return false;
}
