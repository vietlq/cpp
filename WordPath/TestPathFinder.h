//
//  TestPathFinder.h
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#ifndef __WordPath__TestPathFinder__
#define __WordPath__TestPathFinder__

#include <iostream>
#include <gtest/gtest.h>

class TestPathFinder: public ::testing::Test
{
protected:
    TestPathFinder();
    
    virtual ~TestPathFinder();
    
    virtual void SetUp();
    
    virtual void TearDown();
};

#endif /* defined(__WordPath__TestPathFinder__) */
