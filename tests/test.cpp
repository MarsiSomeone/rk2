#include <gtest/gtest.h>
#include "monster_and_pet.hpp"

TEST(AnyFunctionTest, PuppyCutenessAbility) {

Puppy pup;

EXPECT_EQ(pup.CutenessAbility(), 50);}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
