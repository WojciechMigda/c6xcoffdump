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
#include <cstddef>

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

const char * BoostMmappedFileObject::data(void) const
{
    return m_file.data();
}

std::size_t BoostMmappedFileObject::size(void) const
{
    return m_file.size();
}

std::shared_ptr<BoostMmappedFileObject> BoostMmappedFileObject::fromPath(const std::string & in_path)
{
    std::shared_ptr<BoostMmappedFileObject> result;

    boost::iostreams::mapped_file_source file(in_path);

//    result = std::make_shared<BoostMmappedFileObject>(file);
    BoostMmappedFileObject * instance = new BoostMmappedFileObject(file);
    result.reset(instance);

    return result;
}
