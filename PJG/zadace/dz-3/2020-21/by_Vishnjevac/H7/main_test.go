package someRandomPackage

import (
	"testing"
)

type testCase struct {
	shopItems []ShopItem

	expectedOutput int
	expectingError bool
}

func getTestCases() []testCase {
	return []testCase{
		{
			shopItems: []ShopItem{
				{
					Name:     "Watermelon",
					Price:    5,
					Type:     "Prehrana",
					Callory:  30,
					Quantity: 2,
				},
				{
					Name:     "Banana",
					Price:    2,
					Type:     "Prehrana",
					Callory:  89,
					Quantity: 3,
				},
			},
			expectedOutput: 16,
			expectingError: false,
		},
		{
			shopItems: []ShopItem{

			},
			expectedOutput: 0,
			expectingError: false,
		},
		{
			shopItems: []ShopItem{
				{
					Name:     "Chocolate",
					Price:    2,
					Type:     "Prehrana",
					Callory:  546,
					Quantity: 1,
				},
				{
					Name:     "Watermelon",
					Price:    5,
					Type:     "Prehrana",
					Callory:  30,
					Quantity: 2,
				},
			},
			expectingError: true,
		},
		{
			shopItems: []ShopItem{
				{
					Name:     "Rubik's cube",
					Price:    30,
					Type:     "Toy",
					Callory:  0,
					Quantity: 1,
				},
			},
			expectingError: true,
		},
		{
			shopItems: []ShopItem{
				{
					Name:     "Crab legs",
					Price:    50,
					Type:     "Prehrana",
					Callory:  120,
					Quantity: 1,
				},
			},
			expectingError: true,
		},
	}
}

func TestTotalCost(t *testing.T) {
	for _, tc := range getTestCases() {

		actualOutput, actualErr := TotalCost(tc.shopItems)
		if tc.expectingError {
			if actualErr == nil {
				t.Errorf("Expected an error but got `nil` error")
			}
		} else {
			if actualErr != nil {
				t.Errorf("Expected no error but got non-nil error: %v", actualErr)
			}

			if actualOutput != tc.expectedOutput {
				t.Errorf(
					"Actual and expected output is not equal - actual: %v, expected: %v",
					actualOutput,
					tc.expectedOutput)
			}
		}
	}
}
