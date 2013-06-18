#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/interprocess/managed_mapped_file.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/allocators/cached_adaptive_pool.hpp>
#include <boost/interprocess/allocators/cached_node_allocator.hpp>
#include <boost/interprocess/containers/vector.hpp>

using namespace boost::interprocess;

int main(int argc, char * argv[])
{
    typedef cached_adaptive_pool<uint32_t,
        managed_mapped_file::segment_manager> cached_adaptive_pool_t;
    typedef allocator<uint32_t,
        managed_mapped_file::segment_manager> UInt32Allocator;
    typedef cached_node_allocator<uint32_t,
    managed_mapped_file::segment_manager> UInt32CachedNodeAllocator;
    typedef vector<uint32_t, UInt32Allocator> ShmUInt32Vector;
    typedef vector<uint32_t, UInt32CachedNodeAllocator> ShmUInt32CachedNodeVector;
    
    managed_mapped_file segment(open_or_create, "NeoMMapFile", 1024*1024);
    cached_adaptive_pool_t allocator_instance(segment.get_segment_manager());
    UInt32Allocator uint32Allocator(segment.get_segment_manager());
    UInt32CachedNodeAllocator uint32CachedNodeAllocator(segment.get_segment_manager());
    
    allocator_instance.set_max_cached_nodes(3);
    
    //ShmUInt32Vector * myShmVector = segment.find_or_construct<ShmUInt32Vector>("MagicNumbers")(uint32Allocator);
    ShmUInt32CachedNodeVector * myShmVector = segment.find_or_construct<ShmUInt32CachedNodeVector>("MagicNumbers")(uint32CachedNodeAllocator);
    
    myShmVector->reserve(256);
    
    std::cout << "==== I AM THE MODIFIER ====" << std::endl;
    
    for(int i = 0; i < 10000000; ++i)
    {
        if(myShmVector->empty())
        {
            myShmVector->push_back(27);
            myShmVector->push_back(9);
            myShmVector->push_back(1985);
        }
        else
        {
            ShmUInt32Vector::iterator it = myShmVector->begin();
            const ShmUInt32Vector::iterator end = myShmVector->end();
            while(end != it)
            {
                *it = (*it) + time(NULL) + 1;
                ++it;
            }
        }
    }
    
    // http://stackoverflow.com/questions/4153110/how-do-i-use-for-each-to-output-to-cout
    std::copy(myShmVector->begin(), myShmVector->end(), std::ostream_iterator<uint32_t>(std::cout, "\n"));
    
    return 0;
}
