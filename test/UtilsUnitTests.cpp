#include "gtest/gtest.h"
#include "utils/lexical_cast.h"

TEST(UtilsTest, lexical_cast)
{
	EXPECT_EQ(utils::lexical_cast<int>(-11), -11);
	EXPECT_EQ(utils::lexical_cast<int>("-533"), -533);
	EXPECT_EQ(utils::lexical_cast<bool>("true"), true);
	EXPECT_EQ(utils::lexical_cast<bool>("false"), false);
	EXPECT_EQ(utils::lexical_cast<std::string>(-11), "-11");
	EXPECT_EQ(utils::lexical_cast<std::string>(true), "true");
	EXPECT_EQ(utils::lexical_cast<std::string>(false), "false");
}