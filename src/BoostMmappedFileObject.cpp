/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: BoostMmappedFileObject.cpp
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

#include "boost/iostreams/device/mapped_file.hpp"

#include "BoostMmappedFileObject.hpp"

#include <string>
#include <cassert>
#include <algorithm>

BoostMmappedFileObject::BoostMmappedFileObject(boost::iostreams::mapped_file_source & in_file) :
    IFileObject(),
    m_file(in_file)
{
    ;
}

BoostMmappedFileObject::~BoostMmappedFileObject(void)
{
    m_file.close();
}

BoostMmappedFileObject::cbyte_ptr BoostMmappedFileObject::data(void) const
{
    return reinterpret_cast<BoostMmappedFileObject::cbyte_ptr>(m_file.data());
}

BoostMmappedFileObject::size_type BoostMmappedFileObject::size(void) const
{
    return m_file.size();
}

IFileObject::uptr BoostMmappedFileObject::fromPath(const std::string & in_path)
{
    boost::iostreams::mapped_file_source file(in_path);

    assert(file.is_open());

    BoostMmappedFileObject * instance = new (std::nothrow) BoostMmappedFileObject(file);
    IFileObject::uptr result(instance);

    return result;
}

BoostMmappedFileObject::byte_type BoostMmappedFileObject::at(size_type const pos) const
{
    return m_file.data()[pos];
}

BoostMmappedFileObject::size_type BoostMmappedFileObject::read(
    BoostMmappedFileObject::byte_ptr const o_buf,
    BoostMmappedFileObject::size_type const i_size,
    BoostMmappedFileObject::size_type const i_offset) const
{
    assert(o_buf != nullptr);

    BoostMmappedFileObject::size_type const nbytes = std::min(i_size, this->size() - i_offset);

    std::copy(this->data() + i_offset, this->data() + i_offset + nbytes, o_buf);

    return nbytes;
}
