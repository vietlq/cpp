#ifndef BOOST_IPC_UTILS_H
#define BOOST_IPC_UTILS_H

#include <boost/interprocess/managed_mapped_file.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/allocators/cached_adaptive_pool.hpp>
#include <boost/interprocess/allocators/cached_node_allocator.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/containers/string.hpp>

namespace bipc = boost::interprocess;

typedef bipc::managed_mapped_file::segment_manager segment_manager_t;
typedef bipc::cached_adaptive_pool<uint32_t, segment_manager_t> cached_adaptive_pool_t;
typedef bipc::allocator<uint32_t, segment_manager_t> UInt32Allocator;
typedef bipc::cached_node_allocator<uint32_t, segment_manager_t> UInt32CachedNodeAllocator;
typedef bipc::vector<uint32_t, UInt32Allocator> ShmUInt32Vector;
typedef bipc::vector<uint32_t, UInt32CachedNodeAllocator> ShmUInt32CachedNodeVector;
typedef bipc::allocator<char, segment_manager_t> char_allocator;
typedef bipc::basic_string<char, std::char_traits<char>, char_allocator> char_string;
typedef std::pair<const char_string, uint32_t> map_value_type;
typedef bipc::allocator<map_value_type, segment_manager_t> map_value_type_allocator_t;
typedef bipc::map<char_string, uint32_t, std::less<char_string>, map_value_type_allocator_t> ShmStringUInt32CachedNodeMap;

const size_t SHM_SEG_SIZE = 1 << 14;

#include <string>
std::string create_mmap_name();

#endif // BOOST_IPC_UTILS_H
