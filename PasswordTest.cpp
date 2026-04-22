/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}
TEST(PasswordTest, mixed_letter_password)
{
	Password my_password;
	EXPECT_EQ(3, my_password.count_leading_characters("ZZZ"));
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	ASSERT_NE(0, my_password.count_leading_characters(""));
}
TEST(PasswordTest, ascii_test)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("'\0'"));
}
TEST(PasswordTest, string_case)
{
	ASSERT_STRCASEEQ("zar", "Zar");
}
TEST(PasswordTest, string_case2)
{
	ASSERT_STRCASEEQ("bar", "bar");
}
TEST(PasswordTest, string_case3)
{
	ASSERT_STRCASENE("bar", "Bar");
}
//TEST(unique_characters
//TEST(PasswordTest, ){
//  
//	Password my_password;
//	ASSERT_EQ(0, my_password.count_leading_characters(""));
//}
