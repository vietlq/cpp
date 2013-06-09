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

TEST_F(TestDictionary, EmptyDictionaryContainsNoMatch)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    EXPECT_FALSE(dict.contains("piano"));
    EXPECT_FALSE(dict.contains("clarinet"));
    EXPECT_FALSE(dict.contains("harmonica"));
    EXPECT_FALSE(dict.contains("violin"));
}

TEST_F(TestDictionary, DictionaryWithOneItemContainsMatch)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("piano");
    EXPECT_TRUE(dict.contains("piano"));
    EXPECT_FALSE(dict.contains("clarinet"));
    EXPECT_FALSE(dict.contains("harmonica"));
    EXPECT_FALSE(dict.contains("violin"));
}

TEST_F(TestDictionary, DictionaryContainsNoMatchAfterRemoving_1)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("piano");
    EXPECT_TRUE(dict.contains("piano"));
    dict.remove("piano");
    EXPECT_FALSE(dict.contains("piano"));
    EXPECT_FALSE(dict.contains("clarinet"));
    EXPECT_FALSE(dict.contains("harmonica"));
    EXPECT_FALSE(dict.contains("violin"));
}

TEST_F(TestDictionary, DictionaryContainsNoMatchAfterRemoving_2)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("piano");
    dict.add("clarinet");
    dict.add("harmonica");
    dict.add("violin");
    EXPECT_TRUE(dict.contains("piano"));
    EXPECT_TRUE(dict.contains("clarinet"));
    EXPECT_TRUE(dict.contains("harmonica"));
    EXPECT_TRUE(dict.contains("violin"));
    dict.remove("piano");
    EXPECT_FALSE(dict.contains("piano"));
    EXPECT_TRUE(dict.contains("clarinet"));
    EXPECT_TRUE(dict.contains("harmonica"));
    EXPECT_TRUE(dict.contains("violin"));
}

TEST_F(TestDictionary, DictionaryContainsCaseInsensitiveWords_1)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("piano");
    EXPECT_TRUE(dict.contains("PIANO"));
    EXPECT_TRUE(dict.contains("piAno"));
    EXPECT_TRUE(dict.contains("Piano"));
    EXPECT_TRUE(dict.contains("piaNO"));
}

TEST_F(TestDictionary, DictionaryRemoveCaseInsensitiveWords_1)
{
    Dictionary dict;
    EXPECT_EQ(0, dict.size());
    dict.add("PIANO");
    dict.add("clARinet");
    dict.add("harmONica");
    dict.add("vIoLin");
    EXPECT_TRUE(dict.contains("piano"));
    EXPECT_TRUE(dict.contains("clarinet"));
    EXPECT_TRUE(dict.contains("harmonica"));
    EXPECT_TRUE(dict.contains("violin"));
    dict.remove("piano");
    EXPECT_FALSE(dict.contains("piano"));
    EXPECT_TRUE(dict.contains("clarinet"));
    EXPECT_TRUE(dict.contains("harmonica"));
    EXPECT_TRUE(dict.contains("violin"));
    dict.remove("CLarinet");
    EXPECT_FALSE(dict.contains("piano"));
    EXPECT_FALSE(dict.contains("clarinet"));
    EXPECT_TRUE(dict.contains("harmonica"));
    EXPECT_TRUE(dict.contains("violin"));
}
