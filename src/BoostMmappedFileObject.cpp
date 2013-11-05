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
#include <cstdint>
#include <string>
#include <cstddef>
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

const std::uint8_t * BoostMmappedFileObject::data(void) const
{
    return reinterpret_cast<const std::uint8_t *>(m_file.data());
}

std::size_t BoostMmappedFileObject::size(void) const
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

std::uint8_t BoostMmappedFileObject::at(const std::size_t pos) const
{
    return m_file.data()[pos];
}

std::size_t BoostMmappedFileObject::read(
    std::uint8_t & o_buf,
    const std::size_t i_size,
    const std::size_t i_offset) const
{
    const std::size_t nbytes = std::min(i_size, this->size() - i_offset);

    std::copy(this->data(), this->data() + nbytes, &o_buf);

    return nbytes;
}
