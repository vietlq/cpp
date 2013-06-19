#include <iostream>
#include <algorithm>
#include <iterator>

#include "utils.h"

int main(int argc, char * argv[])
{
    bipc::managed_mapped_file segment(bipc::open_or_create, create_mmap_name().c_str(), SHM_SEG_SIZE);
    cached_adaptive_pool_t allocator_instance(segment.get_segment_manager());
    UInt32Allocator uint32Allocator(segment.get_segment_manager());
    UInt32CachedNodeAllocator uint32CachedNodeAllocator(segment.get_segment_manager());
    void_allocator_t voidAllocator(segment.get_segment_manager());
    
    allocator_instance.set_max_cached_nodes(3);
    
    //ShmUInt32Vector * myShmVector = segment.find_or_construct<ShmUInt32Vector>("MagicNumbers")(uint32Allocator);
    ShmUInt32CachedNodeVector * myShmVector = segment.find_or_construct<ShmUInt32CachedNodeVector>("MagicNumbers")(uint32CachedNodeAllocator);
    ShmStringUInt32CachedNodeMap * myShmMap = segment.find_or_construct<ShmStringUInt32CachedNodeMap>("MagicMap")(std::less<char_string>(), voidAllocator);
    
    std::cout << "==== I AM THE INSPECTOR ====" << std::endl;
    
    // http://www.boost.org/doc/libs/1_51_0/doc/html/interprocess/allocators_containers.html#interprocess.allocators_containers.containers_explained.containers_of_containers
    char_string keyObj(voidAllocator);
    keyObj = "count";
    ShmStringUInt32CachedNodeMap::iterator itCount = myShmMap->find(keyObj);
    if(myShmMap->end() == itCount)
    {
        std::cout << "---- The Count DOES NOT EXIST! ----" << std::endl;
    }
    else
    {
        std::cout << "---- The Count = " << itCount->second << " ----" << std::endl;   
    }
    
    // http://stackoverflow.com/questions/4153110/how-do-i-use-for-each-to-output-to-cout
    std::copy(myShmVector->begin(), myShmVector->end(), std::ostream_iterator<uint32_t>(std::cout, "\n"));
    
    return 0;
}
