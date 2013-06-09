//
//  TestDictionary.cpp
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#include "TestDictionary.h"
#include "Dictionary.h"

TestDictionary::TestDictionary()
{
    
}

TestDictionary::~TestDictionary()
{
    
}

void TestDictionary::SetUp()
{

}

void TestDictionary::TearDown()
{
    
}

TEST_F(TestDictionary, NewDictionaryIsEmpty)
{
    Dictionary dict;
    EXPECT_TRUE(dict.empty());
}

TEST_F(TestDictionary, DictionaryWithOneItemIsNotEmpty)
{
    Dictionary dict;
    EXPECT_TRUE(dict.empty());
    dict.add("anything");
    EXPECT_FALSE(dict.empty());
}

TEST_F(TestDictionary, NewDictionaryHasSizeZero)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
}

TEST_F(TestDictionary, DictionaryWithOneItemHasSizeOfOne)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("imagination");
    EXPECT_EQ(1, dict.size());
}

TEST_F(TestDictionary, DictionaryWithTwoDistinctItemsHasSizeOfTwo)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("imagination");
    EXPECT_EQ(1, dict.size());
    dict.add("awesome");
    EXPECT_EQ(2, dict.size());
}

TEST_F(TestDictionary, DictionaryWithTwoEqualItemsHasSizeOfOne)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("piano");
    EXPECT_EQ(1, dict.size());
    dict.add("piano");
    EXPECT_EQ(1, dict.size());
}
