//
//  TestPathFinder.cpp
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#include "TestPathFinder.h"
#include "PathFinder.h"

TestPathFinder::TestPathFinder()
{
    
}

TestPathFinder::~TestPathFinder()
{
    
}

void TestPathFinder::SetUp()
{
    
}

void TestPathFinder::TearDown()
{
    
}

TEST_F(TestPathFinder, NewPathFinderIsEmpty)
{
    PathFinder pathFinder;
    EXPECT_TRUE(pathFinder.empty());
}

TEST_F(TestPathFinder, NewPathFinderHasSizeZero)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
}

TEST_F(TestPathFinder, PathFinderWithOneItemIsNotEmpty)
{
    PathFinder pathFinder;
    EXPECT_TRUE(pathFinder.empty());
    pathFinder.add("anything");
    EXPECT_FALSE(pathFinder.empty());
}

TEST_F(TestPathFinder, PathFinderWithOneItemHasSizeOfOne)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("imagination");
    EXPECT_EQ(1, pathFinder.size());
}

TEST_F(TestPathFinder, PathFinderWithTwoDistinctItemsHasSizeOfTwo)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("imagination");
    EXPECT_EQ(1, pathFinder.size());
    pathFinder.add("awesome");
    EXPECT_EQ(2, pathFinder.size());
}

TEST_F(TestPathFinder, PathFinderWithTwoEqualItemsHasSizeOfOne)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("piano");
    EXPECT_EQ(1, pathFinder.size());
    pathFinder.add("piano");
    EXPECT_EQ(1, pathFinder.size());
}

TEST_F(TestPathFinder, EmptyPathFinderContainsNoMatch)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    EXPECT_FALSE(pathFinder.contains("piano"));
    EXPECT_FALSE(pathFinder.contains("clarinet"));
    EXPECT_FALSE(pathFinder.contains("harmonica"));
    EXPECT_FALSE(pathFinder.contains("violin"));
}

TEST_F(TestPathFinder, PathFinderWithOneItemContainsMatch)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("piano");
    EXPECT_TRUE(pathFinder.contains("piano"));
    EXPECT_FALSE(pathFinder.contains("clarinet"));
    EXPECT_FALSE(pathFinder.contains("harmonica"));
    EXPECT_FALSE(pathFinder.contains("violin"));
}

TEST_F(TestPathFinder, PathFinderContainsNoMatchAfterRemoving_1)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("piano");
    EXPECT_TRUE(pathFinder.contains("piano"));
    pathFinder.remove("piano");
    EXPECT_FALSE(pathFinder.contains("piano"));
    EXPECT_FALSE(pathFinder.contains("clarinet"));
    EXPECT_FALSE(pathFinder.contains("harmonica"));
    EXPECT_FALSE(pathFinder.contains("violin"));
}

TEST_F(TestPathFinder, PathFinderContainsNoMatchAfterRemoving_2)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("piano");
    pathFinder.add("clarinet");
    pathFinder.add("harmonica");
    pathFinder.add("violin");
    EXPECT_TRUE(pathFinder.contains("piano"));
    EXPECT_TRUE(pathFinder.contains("clarinet"));
    EXPECT_TRUE(pathFinder.contains("harmonica"));
    EXPECT_TRUE(pathFinder.contains("violin"));
    pathFinder.remove("piano");
    EXPECT_FALSE(pathFinder.contains("piano"));
    EXPECT_TRUE(pathFinder.contains("clarinet"));
    EXPECT_TRUE(pathFinder.contains("harmonica"));
    EXPECT_TRUE(pathFinder.contains("violin"));
}

TEST_F(TestPathFinder, PathFinderContainsCaseInsensitiveWords_1)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("piano");
    EXPECT_TRUE(pathFinder.contains("PIANO"));
    EXPECT_TRUE(pathFinder.contains("piAno"));
    EXPECT_TRUE(pathFinder.contains("Piano"));
    EXPECT_TRUE(pathFinder.contains("piaNO"));
}

TEST_F(TestPathFinder, PathFinderRemoveCaseInsensitiveWords_1)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("PIANO");
    pathFinder.add("clARinet");
    pathFinder.add("harmONica");
    pathFinder.add("vIoLin");
    EXPECT_TRUE(pathFinder.contains("piano"));
    EXPECT_TRUE(pathFinder.contains("clarinet"));
    EXPECT_TRUE(pathFinder.contains("harmonica"));
    EXPECT_TRUE(pathFinder.contains("violin"));
    pathFinder.remove("piano");
    EXPECT_FALSE(pathFinder.contains("piano"));
    EXPECT_TRUE(pathFinder.contains("clarinet"));
    EXPECT_TRUE(pathFinder.contains("harmonica"));
    EXPECT_TRUE(pathFinder.contains("violin"));
    pathFinder.remove("CLarinet");
    EXPECT_FALSE(pathFinder.contains("piano"));
    EXPECT_FALSE(pathFinder.contains("clarinet"));
    EXPECT_TRUE(pathFinder.contains("harmonica"));
    EXPECT_TRUE(pathFinder.contains("violin"));
}

TEST_F(TestPathFinder, EmptyStringsAreNotAdjacent)
{
    EXPECT_FALSE(are_adjacent("", ""));
}

TEST_F(TestPathFinder, EmptyStringsAndNonEmptyStringAreNotAdjacent)
{
    EXPECT_FALSE(are_adjacent("a", ""));
    EXPECT_FALSE(are_adjacent("", "b"));
}

TEST_F(TestPathFinder, StringsWithDiffLenAreNotAdjacent)
{
    EXPECT_FALSE(are_adjacent("ab", "abc"));
}

TEST_F(TestPathFinder, EqualStringsAreNotAdjacent)
{
    EXPECT_FALSE(are_adjacent("abc", "abc"));
}

TEST_F(TestPathFinder, StringsWithOneDiffCharAreAdjacent)
{
    EXPECT_TRUE(are_adjacent("abd", "abc"));
    EXPECT_TRUE(are_adjacent("abc", "abd"));
    EXPECT_TRUE(are_adjacent("abdaa", "abcaa"));
    EXPECT_TRUE(are_adjacent("abcaa", "abdaa"));
}

TEST_F(TestPathFinder, StringsWithMoreThanOneDiffCharAreNotAdjacent)
{
    EXPECT_FALSE(are_adjacent("abda", "abcb"));
    EXPECT_FALSE(are_adjacent("abca", "abdb"));
    EXPECT_FALSE(are_adjacent("abdaa", "abcba"));
    EXPECT_FALSE(are_adjacent("abcaa", "abdba"));
}

TEST_F(TestPathFinder, PathFinderComplainsAboutMissingPairs)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("piano");
    pathFinder.add("violin");
    pathFinder.add("clarinet");
    pathFinder.add("harmonica");
    
    EXPECT_EQ(ERR_BOTH_WORDS_MUST_BE_INSERTED, pathFinder.path("piano", "basso"));
    EXPECT_NE(ERR_BOTH_WORDS_MUST_BE_INSERTED, pathFinder.path("piano", "violin"));
}

TEST_F(TestPathFinder, PathFinderComplainsAboutDiffLen)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("piano");
    pathFinder.add("violin");
    pathFinder.add("clarinet");
    pathFinder.add("harmonica");
    
    EXPECT_EQ(ERR_BOTH_WORDS_MUST_BE_SAME_LEN, pathFinder.path("piano", "violin"));
}

TEST_F(TestPathFinder, PathFinderAcceptsCorrectResult_1)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("cat");
    pathFinder.add("bat");
    
    EXPECT_EQ("cat > bat", pathFinder.path("cat", "bat"));
}

TEST_F(TestPathFinder, PathFinderAcceptsCorrectResult_2)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("cat");
    pathFinder.add("can");
    pathFinder.add("man");
    
    EXPECT_EQ("cat > can > man", pathFinder.path("cat", "man"));
}

TEST_F(TestPathFinder, PathFinderAcceptsCorrectResult_3)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("cat");
    pathFinder.add("can");
    pathFinder.add("pan");
    pathFinder.add("man");
    
    EXPECT_EQ("cat > can > man", pathFinder.path("cat", "man"));
}

TEST_F(TestPathFinder, PathFinderAcceptsCorrectResult_4)
{
    PathFinder pathFinder;
    EXPECT_EQ(0, pathFinder.size());
    pathFinder.add("cat");
    pathFinder.add("pat");
    pathFinder.add("pan");
    pathFinder.add("man");
    pathFinder.add("dan");
    
    EXPECT_EQ("cat > pat > pan > man", pathFinder.path("cat", "man"));
}
