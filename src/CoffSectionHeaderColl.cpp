/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffSectionHeaderColl.cpp
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
 * 2013-11-21   wm              Initial version
 *
 ******************************************************************************/

#include "CoffSectionHeaderColl.hpp"
#include "CoffSectionHeader.hpp"

#include <string>
#include <algorithm>

using size_type = Coff::SectionHeaderColl::size_type;

ICoffSectionHeaderColl::uptr Coff::SectionHeaderColl::fromFileObject(
    IFileObject::sptr i_file,
    size_type const i_pos,
    size_type const i_hdr_count)
{
    ICoffSectionHeaderColl::coll    coll;
    coll.reserve(i_hdr_count);

    for (size_type it = 0, pos = i_pos; it < i_hdr_count; ++it)
    {
        ICoffSectionHeader::uptr section_hdr = Coff::SectionHeader::fromFileObject(i_file, pos);
        pos += section_hdr->size();
        coll.push_back(std::move(section_hdr));
    }

    ICoffSectionHeaderColl * const instance = new Coff::SectionHeaderColl{std::move(coll)};

    ICoffSectionHeaderColl::uptr   result{instance};

    return result;
}

Coff::SectionHeaderColl::SectionHeaderColl(ICoffSectionHeaderColl::coll && i_coll) :
    ICoffSectionHeaderColl(),
    m_coll(std::move(i_coll))
{
    ;
}

std::string Coff::SectionHeaderColl::toString(void) const
{
//    using boost::format;
//    using boost::io::group;
//    using std::setw;
//    using std::setfill;
//    using std::left;
//    using std::right;

    std::string retval;

//    retval =
//        (format("%1%\n") % group(left, setw(64), setfill('='), "==[COFF Section Header Collection]")).str() +
//        (format("%1% : VersionId\n") %
//            group(setw(10), (format("%1$04X") % mVersionId).str())).str() +
//        (format("%1% : PhysicalAddress\n") %
//            group(setw(10), (format("%1$08X") % mPhysicalAddress).str())).str() +
//        "";

    std::for_each(m_coll.cbegin(), m_coll.cend(),
        [&retval](ICoffSectionHeader::sptr i_header)
        {
            retval += i_header->toString();
        }
    );

    return retval;
}

size_type Coff::SectionHeaderColl::size(void) const
{
    return 0;
}
