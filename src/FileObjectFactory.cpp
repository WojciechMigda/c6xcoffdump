/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: FileObjectFactory.cpp
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

#include "FileObjectFactory.hpp"
#include "BoostMmappedFileObject.hpp"

#include <memory>
#include <string>

std::shared_ptr<IFileObject> createFileObject(const std::string & in_path)
{
    return BoostMmappedFileObject::fromPath(in_path);
}
