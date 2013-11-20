/*******************************************************************************
 * Copyright (c) 2013 Wojciech Migda
 * All rights reserved
 * Distributed under the terms of the Apache 2.0 license
 *******************************************************************************
 *
 * Filename: FileObjectAlgo.hpp
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
 * 2013-11-05   wm              Initial version
 *
 ******************************************************************************/


#ifndef FILEOBJECTALGO_HPP_
#define FILEOBJECTALGO_HPP_

#include "IFileObject.hpp"

#include <cstdint>
#include <cstdarg>
#include <type_traits>

namespace FileObject
{

typedef std::integral_constant<bool, false> big_endian_t;
typedef std::integral_constant<bool, true> little_endian_t;

constexpr big_endian_t big_endian;
constexpr little_endian_t little_endian;

template<typename _Tp, typename _En = little_endian_t>
_Tp read(IFileObject::sptr i_file, const std::size_t i_offset)
{
    static_assert(std::is_integral<_Tp>::value, "Template argument must be of integral type.");
    static_assert(
        sizeof (_Tp) == sizeof (std::uint8_t)
        || sizeof (_Tp) == sizeof (std::uint16_t)
        || sizeof (_Tp) == sizeof (std::uint32_t),
        "Size of template argument _Tp must be either 1, 2, or 4 octets."
        );
    static_assert(
        std::is_same<_En, big_endian_t>::value
        || std::is_same<_En, little_endian_t>::value,
        "Template argument _En must be either big_endian_t or little_endian_t");

    if (sizeof (_Tp) == sizeof (std::uint8_t))
    {
        return i_file->at(i_offset);
    }
    else if (sizeof (_Tp) == sizeof (std::uint16_t))
    {
        if (std::is_same<_En, big_endian_t>::value)
        {
            return
                (i_file->at(i_offset + 0) << 8) +
                (i_file->at(i_offset + 1) << 0);
        }
        else
        {
            return
                (i_file->at(i_offset + 0) << 0) +
                (i_file->at(i_offset + 1) << 8);
        }
    }
    else if (sizeof (_Tp) == sizeof (std::uint32_t))
    {
        if (std::is_same<_En, big_endian_t>::value)
        {
            return
                (i_file->at(i_offset + 0) << 24) +
                (i_file->at(i_offset + 1) << 16) +
                (i_file->at(i_offset + 2) << 8) +
                (i_file->at(i_offset + 3) << 0);
        }
        else
        {
            return
                (i_file->at(i_offset + 0) << 0) +
                (i_file->at(i_offset + 1) << 8) +
                (i_file->at(i_offset + 2) << 16) +
                (i_file->at(i_offset + 3) << 24);
        }
    }
}

template<typename _Tp>
_Tp read_be(IFileObject::sptr i_file, const std::size_t i_offset)
{
    return read<_Tp, big_endian_t>(i_file, i_offset);
}

template<typename _Tp>
_Tp read_le(IFileObject::sptr i_file, const std::size_t i_offset)
{
    return read<_Tp, little_endian_t>(i_file, i_offset);
}

template<typename _Tp>
_Tp read(IFileObject::sptr i_file, const std::size_t i_offset, const big_endian_t)
{
    return read_be<_Tp>(i_file, i_offset);
}

template<typename _Tp>
_Tp read(IFileObject::sptr i_file, const std::size_t i_offset, const little_endian_t)
{
    return read_le<_Tp>(i_file, i_offset);
}

}

#endif /* FILEOBJECTALGO_HPP_ */
