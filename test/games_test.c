#include "matches.h"
#include "bulls.h"
#include "ctest.h"
#include <stdio.h>

CTEST (mathces_test_true, correct_match)
{
	// Given
	int value = 5;

	// When
	int result = correct_match (value);

	// Then
	const int expected = 0;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_test_false_higher, correct_match)
{
	// Given
	int value = 1337;

	// When
	int result = correct_match (value);

	// Then
	const int expected = 1;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_test_false_lower, correct_match)
{
	// Given
	int value = -228;

	// When
	int result = correct_match (value);

	// Then
	const int expected = 1;
	ASSERT_EQUAL (expected, result);
}

CTEST (bulls_test_en_false, enter_number)
{
	//Given
	char n[] = "sxs";

	//When
	char *result = enter_number(n);

	//Then
	const char *expected = NULL;
	ASSERT_STR(expected, result);
}

CTEST (bulls_test_en_true, enter_number)
{
	fputs ("1352\n", stdin);
	//Given
	char n[] = "sxs";

	//When
	char *result = enter_number(n);

	//Then
	const char *expected = "1352\n";
	ASSERT_STR(expected, result);
}

CTEST (bulls_test_cn_false, check_number)
{
	//Given
	char n[] = "1234567\n";

	//When
	int result = check_number(n);

	//Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST (bulls_test_cn_false1, check_number)
{
	//Given
	char n[] = "qwerty\n";

	//When
	int result = check_number(n);

	//Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST (bulls_test_cn_false2, check_number)
{
	//Given
	char n[] = "1221\n";

	//When
	int result = check_number(n);

	//Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST (bulls_test_cn_true, check_number)
{
	//Given
	char n[] = "1234\n";

	//When
	int result = check_number(n);

	//Then
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}
