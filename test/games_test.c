#include "matches.h"
#include "bulls.h"
#include "ctest.h"
#include <stdio.h>

CTEST (mathces_test_true, check_match)
{
	// Given
	char value[] = "5\n";

	// When
	int result = check_match (value);

	// Then
	const int expected = 0;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_test_false_symbol, check_match)
{
	// Given
	char value[] = "1a\n";

	// When
	int result = check_match (value);

	// Then
	const int expected = -2;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_test_false_large_value, check_match)
{
	// Given
	char value[] = "115\n";

	// When
	int result = check_match (value);

	// Then
	const int expected = -1;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_test_false_incorrect_value, check_match)
{
	// Given
	char value[] = "13\n";

	// When
	int result = check_match (value);

	// Then
	const int expected = -3;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_test_true, check_nickname)
{
	// Given
	char player[] = "MexicoFlexico\n";

	// When
	int result = check_nickname (player);

	// Then
	const int expected = 0;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_test_false, check_nickname)
{
	// Given
	char player[] = "abcdefgh1234536fkowwqrrkkwp\n";

	// When
	int result = check_nickname (player);

	// Then
	const int expected = -2;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_heap_test_true_turn_equals_heap, check_heap)
{
	//Given
	int heap = 7;
	int turn = 7;

	//When
	int result = check_heap (&heap, turn);

	//Then
	const int expected = 0;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_heap_test_true_turn, check_heap)
{
	//Given
	int heap = 7;
	int turn = 5;

	//When
	int result = check_heap (&heap, turn);

	//Then
	const int expected = 0;
	ASSERT_EQUAL (expected, result);
}

CTEST (matches_heap_test_false_large_turn, check_heap)
{
	//Given
	int heap = 7;
	int turn = 10;

	//When
	int result = check_heap (&heap, turn);

	//Then
	const int expected = -1;
	ASSERT_EQUAL (expected, result);
}

CTEST (bulls_test_false_symbol, check_number)
{
	//Given
	char n[] = "123ab\n";

	//When
	int result = check_number (n);

	//Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST (bulls_test_false_equals, check_number)
{
	//Given
	char n[] = "4124\n";

	//When
	int result = check_number(n);

	//Then
	const int expected = -2;
	ASSERT_EQUAL(expected, result);
}

CTEST (bulls_test_false_lenght_small, check_number)
{
	//Given
	char n[] = "13\n";

	//When
	int result = check_number(n);

	//Then
	const int expected = -3;
	ASSERT_EQUAL(expected, result);
}

CTEST (bulls_test_false_length_large, check_number)
{
	//Given
	char n[] = "12345";

	//When
	int result = check_number(n);

	//Then
	const int expected = -4;
	ASSERT_EQUAL(expected, result);
}
