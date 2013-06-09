//
//  TestDictionary.h
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#ifndef __WordPath__TestDictionary__
#define __WordPath__TestDictionary__

#include <gtest/gtest.h>

class TestDictionary: public ::testing::Test
{
protected:
    TestDictionary();
    
    virtual ~TestDictionary();
    
    virtual void SetUp();
    
    virtual void TearDown();
};

#endif /* defined(__WordPath__TestDictionary__) */
