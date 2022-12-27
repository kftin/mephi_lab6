#include <gtest/gtest.h>

int test_main() {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}

int main() {
    return test_main();
}

