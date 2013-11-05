/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: main.cpp
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
 * 2013-11-02   wm              Initial version
 *
 ******************************************************************************/

#include "CoffFile.hpp"
#include "IFileObject.hpp"
#include "ICoffFile.hpp"
#include "FileObjectFactory.hpp"

#include <iostream>
#include <cstdarg>

int main()
{
    IFileObject::sptr   file_object = createFileObject("sample.obj");

    std::size_t size = file_object->size();
    std::cout << size << std::endl;

    ICoffFile::uptr   file = Coff::File::fromFileObject(file_object);

    std::cout << file->toString() << std::endl;

    return 0;
}
