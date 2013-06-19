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
    
    // http://www.boost.org/doc/libs/1_51_0/doc/html/interprocess/allocators_containers.html#interprocess.allocators_containers.containers_explained.containers_of_containers
    char_string keyObj(voidAllocator);
    keyObj = "count";
    ShmStringUInt32CachedNodeMap::iterator itCount = myShmMap->find(keyObj);
    if(myShmMap->end() == itCount)
    {
        map_value_type valueObj(keyObj, 0);
        myShmMap->insert(valueObj);
    }
    itCount = myShmMap->find(keyObj);
    
    std::cout << "==== I AM THE MODIFIER ====" << std::endl;
    std::cout << "---- Before: The Count = " << itCount->second << " ----" << std::endl;
    
    myShmVector->reserve(256);
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
        ++(itCount->second);
    }
    
    std::cout << "---- After: The Count = " << itCount->second << " ----" << std::endl;
    
    // http://stackoverflow.com/questions/4153110/how-do-i-use-for-each-to-output-to-cout
    std::copy(myShmVector->begin(), myShmVector->end(), std::ostream_iterator<uint32_t>(std::cout, "\n"));
    
    return 0;
}
