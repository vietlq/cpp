#include <gtest/gtest.h>
#include "tdd_set.h"

class TestSet: public ::testing::Test {
protected:
	TestSet()
	{
		
	}
	
	virtual ~TestSet()
	{
		
	}
	
	virtual void SetUp()
	{
		
	}
	
	virtual void TearDown()
	{
		
	}
};

TEST_F(TestSet, NewSetIsEmpty)
{
	Set set;
	EXPECT_TRUE(set.isEmpty());
}

TEST_F(TestSet, SetWithOneEleIsNotEmpty)
{
	Set set;
	set.add(1);
	EXPECT_FALSE(set.isEmpty());
}

TEST_F(TestSet, SetAddOneContainsOne)
{
	Set set;
	set.add(1);
	EXPECT_TRUE(set.contains(1));
}

TEST_F(TestSet, SetAddOneDoesNotContainsTwo)
{
	Set set;
	set.add(1);
	EXPECT_FALSE(set.contains(2));
}

TEST_F(TestSet, SetWithOneEleHasSizeOfOne)
{
	Set set;
	set.add(1);
	EXPECT_EQ(1, set.size());
}

TEST_F(TestSet, SetWithTwoDistinctEleHasSizeOfTwo)
{
	Set set;
	set.add(1);
	set.add(2);
	EXPECT_EQ(2, set.size());
}

TEST_F(TestSet, SetWithTwoEqualEleHasSizeOfOne)
{
	Set set;
	set.add(1);
	set.add(1);
	EXPECT_EQ(1, set.size());
}

TEST_F(TestSet, SetWithOneEleRemovedOneIsEmpty)
{
	Set set;
	set.add(1);
	set.remove(1);
	EXPECT_EQ(0, set.size());
	EXPECT_TRUE(set.isEmpty());
}

TEST_F(TestSet, SetWithOneEleRemovedZeroIsNotEmpty)
{
	Set set;
	set.add(1);
	set.remove(0);
	EXPECT_EQ(1, set.size());
	EXPECT_FALSE(set.isEmpty());
}

TEST_F(TestSet, SetWithTwoDistinctEleRemovedOneIsNotEmpty)
{
	Set set;
	set.add(1);
	set.add(2);
	EXPECT_EQ(2, set.size());
	EXPECT_FALSE(set.isEmpty());
	set.remove(1);
	EXPECT_EQ(1, set.size());
	EXPECT_FALSE(set.isEmpty());
}

TEST_F(TestSet, SetWithTwoEqualEleRemovedOneIsEmpty)
{
	Set set;
	set.add(1);
	set.add(1);
	EXPECT_EQ(1, set.size());
	EXPECT_FALSE(set.isEmpty());
	set.remove(1);
	EXPECT_EQ(0, set.size());
	EXPECT_TRUE(set.isEmpty());
}
