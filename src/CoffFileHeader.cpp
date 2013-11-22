/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
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
#include "FileObjectAlgo.hpp"

#include <boost/format.hpp>

#include <memory>
#include <cassert>
#include <string>
#include <iomanip>

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

namespace
{

bool isSupported(IFileObject::sptr i_file)
{
    const std::uint16_t   magic = FileObject::read_le<std::uint16_t>(i_file, 0);

    bool retval = (magic == VERSION_ID_COFF2);

    return retval;
}

}

ICoffFileHeader::uptr Coff::FileHeader::fromFileObject(IFileObject::sptr i_file, std::size_t const i_pos)
{
    assert(i_file->size() >= COFF1_2_HEADER_SIZE);

    if (!isSupported(i_file))
    {
        assert(isSupported(i_file));
        return ICoffFileHeader::uptr{nullptr};
    }

    SectionHeadersNum const section_hdrs_n = FileObject::read_le<std::uint16_t>(i_file, i_pos + 2);
    DateTimeStamp const date_time_stamp = FileObject::read_le<std::uint32_t>(i_file, i_pos + 4);
    SymbolTableOffset const symtab_offset = FileObject::read_le<std::uint32_t>(i_file, i_pos + 8);
    SymbolTableEntriesNum const symtab_entries_n = FileObject::read_le<std::uint32_t>(i_file, i_pos + 12);
    OptionalHeaderSize const optional_hdr_size = FileObject::read_le<std::uint16_t>(i_file, i_pos + 16);
    Flags const flags = std::bitset<16>(FileObject::read_le<std::uint16_t>(i_file, i_pos + 18));
    TargetId const target_id = FileObject::read_le<std::uint16_t>(i_file, i_pos + 20);

    Coff::FileHeader * instance = new Coff::FileHeader
    {
        VERSION_ID_COFF2,
        section_hdrs_n,
        date_time_stamp,
        symtab_offset,
        symtab_entries_n,
        optional_hdr_size,
        flags,
        target_id
    };
    ICoffFileHeader::uptr   result{instance};

    return result;
}

Coff::FileHeader::FileHeader(
    VersionId const             versionId,
    SectionHeadersNum const     sectionHeadersNum,
    DateTimeStamp const         dateTimeStamp,
    SymbolTableOffset const     symbolTableOffset,
    SymbolTableEntriesNum const symbolTableEntriesNum,
    OptionalHeaderSize const    optionalHeaderSize,
    Flags const                 flags,
    TargetId const              targetId)
:
    ICoffFileHeader(),
    mVersionId(versionId),
    mSectionHeadersNum(sectionHeadersNum),
    mDateTimeStamp(dateTimeStamp),
    mSymbolTableOffset(symbolTableOffset),
    mSymbolTableEntriesNum(symbolTableEntriesNum),
    mOptionalHeaderSize(optionalHeaderSize),
    mFlags(flags),
    mTargetId(targetId)
{
    ;
}

std::string Coff::FileHeader::toString(void) const
{
    using boost::format;
    using boost::io::group;
    using std::setw;
    using std::setfill;
    using std::left;
    using std::right;

    std::string retval;

    retval =
        (format("%1%\n") % group(left, setw(64), setfill('='), "==[COFF File Header]")).str() +
        (format("%1% : VersionId\n") %
            group(setw(10), (format("%1$04X") % mVersionId).str())).str() +
        (format("%1% : SectionHeadersNum\n") %
            group(setw(10), (format("%1$04X") % mSectionHeadersNum).str())).str() +
        (format("%1% : DateTimeStamp\n") %
            group(setw(10), (format("%1$08X") % mDateTimeStamp).str())).str() +
        (format("%1% : SymbolTableOffset\n") %
            group(setw(10), (format("%1$08X") % mSymbolTableOffset).str())).str() +
        (format("%1% : SymbolTableEntriesNum\n") %
            group(setw(10), (format("%1$08X") % mSymbolTableEntriesNum).str())).str() +
        (format("%1% : OptionalHeaderSize\n") %
            group(setw(10), (format("%1$04X") % mOptionalHeaderSize).str())).str() +
        (format("%1% : Flags\n") %
            group(setw(10), (format("%1$04X") % ((Flags::type &)mFlags).to_ulong()).str())).str() +
        (format("%1% : TargetId\n") %
            group(setw(10), (format("%1$04X") % mTargetId).str())).str() +
        "";

    return retval;
}

std::size_t Coff::FileHeader::sectionHeadersNum(void) const
{
    return mSectionHeadersNum;
}

std::size_t Coff::FileHeader::symbolTableOffset(void) const
{
    return mSymbolTableOffset;
}

std::size_t Coff::FileHeader::symbolTableEntriesNum(void) const
{
    return mSymbolTableEntriesNum;
}

bool Coff::FileHeader::hasOptionalHeader(void) const
{
    return mOptionalHeaderSize != 0;
}

std::size_t Coff::FileHeader::size(void) const
{
    return COFF1_2_HEADER_SIZE;
}
