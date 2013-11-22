/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: CoffSectionHeader.cpp
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

#include "CoffSectionHeader.hpp"
#include "ICoffSectionHeader.hpp"
#include "IFileObject.hpp"
#include "FileObjectAlgo.hpp"

#include "boost/format.hpp"

#include <cstdint>
#include <iomanip>
#include <string>
#include <bitset>

enum
{
    COFF2_SECTION_HEADER_SIZE = 48
};

ICoffSectionHeader::uptr Coff::SectionHeader::fromFileObject(IFileObject::sptr i_file, size_type const i_pos)
{
//    assert(i_file->size() >= COFF1_2_HEADER_SIZE);

    SectionName     section_name;
    i_file->read(((name_array_type &)section_name).begin(), ((name_array_type &)section_name).size(), i_pos);

    PhysicalAddress const phys_address = FileObject::read_le<std::uint32_t>(i_file, i_pos + 8);
    VirtualAddress const virt_address = FileObject::read_le<std::uint32_t>(i_file, i_pos + 12);
    SectionSize const section_size = FileObject::read_le<std::uint32_t>(i_file, i_pos + 16);
    RawDataPtr const raw_data_ptr = FileObject::read_le<std::uint32_t>(i_file, i_pos + 20);
    RelocEntriesPtr const reloc_entries_ptr = FileObject::read_le<std::uint32_t>(i_file, i_pos + 24);
    // reserved - 4 bytes
    RelocEntriesNum const reloc_entries_num = FileObject::read_le<std::uint32_t>(i_file, i_pos + 32);
    // reserved - 4 bytes
    Flags const flags = std::bitset<32>(FileObject::read_le<std::uint32_t>(i_file, i_pos + 40));
    // reserved - 2 bytes
    MemoryPageNum const mem_page_num = FileObject::read_le<std::uint32_t>(i_file, i_pos + 46);

    ICoffSectionHeader * instance = new Coff::SectionHeader
    {
        section_name,
        phys_address,
        virt_address,
        section_size,
        raw_data_ptr,
        reloc_entries_ptr,
        reloc_entries_num,
        flags,
        mem_page_num
    };
    ICoffSectionHeader::uptr   result{instance};

    return result;
}

Coff::SectionHeader::SectionHeader(
    SectionName const           sectionName,
    PhysicalAddress const       physicalAddress,
    VirtualAddress const        virtualAddress,
    SectionSize const           sectionSize,
    RawDataPtr const            rawDataPtr,
    RelocEntriesPtr const       relocEntriesPtr,
    RelocEntriesNum const       relocEntriesNum,
    Flags const                 flags,
    MemoryPageNum const         memoryPageNum
)
:
    ICoffSectionHeader(),
    mSectionName(sectionName),
    mPhysicalAddress(physicalAddress),
    mVirtualAddress(virtualAddress),
    mSectionSize(sectionSize),
    mRawDataPtr(rawDataPtr),
    mRelocEntriesPtr(relocEntriesPtr),
    mRelocEntriesNum(relocEntriesNum),
    mFlags(flags),
    mMemoryPageNum(memoryPageNum)
{
    ;
}

std::string Coff::SectionHeader::toString(void) const
{
    using boost::format;
    using boost::io::group;
    using std::setw;
    using std::setfill;
    using std::left;
    using std::right;

    std::string section_name;
    std::string retval;

    retval =
        (format("%1%\n") % group(left, setw(64), setfill('='), "==[COFF Section Header]")).str() +
//        (format("%1%\n") % (SectionName::type &)mSectionName).str() +
//        (format("%1% : VersionId\n") %
//            group(setw(10), (format("%1$04X") % mVersionId).str())).str() +
        (format("%1% : PhysicalAddress\n") %
            group(setw(10), (format("%1$08X") % mPhysicalAddress).str())).str() +
        (format("%1% : VirtualAddress\n") %
            group(setw(10), (format("%1$08X") % mVirtualAddress).str())).str() +
        (format("%1% : SectionSize\n") %
            group(setw(10), (format("%1$08X") % mSectionSize).str())).str() +
        (format("%1% : RawDataPtr\n") %
            group(setw(10), (format("%1$08X") % mRawDataPtr).str())).str() +
        (format("%1% : RelocEntriesPtr\n") %
            group(setw(10), (format("%1$08X") % mRelocEntriesPtr).str())).str() +
        (format("%1% : RelocEntriesNum\n") %
            group(setw(10), (format("%1$08X") % mRelocEntriesNum).str())).str() +
        (format("%1% : Flags\n") %
            group(setw(10), (format("%1$08X") % ((Flags::type &)mFlags).to_ulong()).str())).str() +
        (format("%1% : MemoryPageNum\n") %
            group(setw(10), (format("%1$04X") % mMemoryPageNum).str())).str() +
        "";

    return retval;
}

Coff::SectionHeader::size_type Coff::SectionHeader::size(void) const
{
    return COFF2_SECTION_HEADER_SIZE;
}
