//
// Copyright (C) 2010  Aleksandar Zlateski <zlateski@mit.edu>
// ----------------------------------------------------------
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef ZI_ATOMIC_FENCED_BLOCK_HPP
#define ZI_ATOMIC_FENCED_BLOCK_HPP 1

#include <zi/atomic/config.hpp>
#include <zi/utility/non_copyable.hpp>

#define ZI_ATOMIC_FENCED_BLOCK_HPP_INCLUDING 1

#if defined( ZI_HAS_GCC_SYNC )
#
#elif defined( __GNUC__ ) && ( defined( __i386__ ) || defined( __x86_64__ ) )
#
#elif defined( ZI_OS_WINDOWS )
#
#elif defined( ZI_OS_MACOS )
#  include <libkern/OSAtomic.h>
#
#else
#  error "no fenced_block functions available"
#
#endif

namespace zi {
namespace atomic {

#if defined( ZI_HAS_GCC_SYNC )
#  include <zi/atomic/detail/fenced_block_gcc_sync.hpp>
#
#elif defined( __GNUC__ ) && ( defined( __i386__ ) || defined( __x86_64__ ) )
#  include <zi/atomic/detail/fenced_block_gcc_x86.hpp>
#
#elif defined( ZI_OS_MACOS )
#  include <zi/atomic/detail/fenced_block_macos.hpp>
#
#elif defined( ZI_OS_WINDOWS )
#  include <zi/atomic/detail/fenced_block_win32.hpp>
#
#else
#  error "no fenced_block functions available"
#
#endif


} // namespace atomic
} // namespace zi

#undef ZI_ATOMIC_FENCED_BLOCK_HPP_INCLUDING

#endif
