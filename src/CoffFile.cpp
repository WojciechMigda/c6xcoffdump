/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffFile.cpp
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

#include "IFileObject.hpp"
#include "ICoffFileHeader.hpp"
#include "ICoffFile.hpp"

#include "CoffFileHeader.hpp"
#include "CoffFile.hpp"
#include "CoffSectionHeaderColl.hpp"

#include <memory>
#include <string>
#include <cassert>
#include <algorithm>

using size_type = Coff::File::size_type;

ICoffFile::uptr Coff::File::fromFileObject(IFileObject::sptr i_file, size_type const i_pos)
{
    ICoffFileHeader::uptr   file_header = Coff::FileHeader::fromFileObject(i_file, i_pos);

    assert(file_header);

    ICoffSectionHeaderColl::uptr    section_header_coll =
        Coff::SectionHeaderColl::fromFileObject(i_file, i_pos + file_header->size(), file_header->sectionHeadersNum());

    assert(section_header_coll);

    Coff::File * instance =
        new (std::nothrow)
        Coff::File
        {
            std::move(file_header),
            std::move(section_header_coll)
        };
    Coff::File::uptr     result{instance};

    return result;
}

Coff::File::File(
    ICoffFileHeader::uptr i_file_header,
    ICoffSectionHeaderColl::uptr i_section_hdr_coll
    )
:
    ICoffFile(),
    m_file_header(std::move(i_file_header)),
    m_section_header_coll(std::move(i_section_hdr_coll))
{
    ;
}

std::string Coff::File::toString(void) const
{
    return
        m_file_header->toString() +
        m_section_header_coll->toString();
}
