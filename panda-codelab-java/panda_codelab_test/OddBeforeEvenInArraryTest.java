package panda_codelab_test;

import static org.junit.Assert.*;
import org.junit.Test;

import panda_codelab_soln.OddBeforeEvenInArrary;

public class OddBeforeEvenInArraryTest {
	// helper function that for a given array of ints, it returns true if odd
	// numbers are before even numbers, false otherwise.
	private static boolean isOddBeforeEven(int arr[]) {
		boolean passOdd = false;
		for (int i = 0; i < arr.length; i++) {
			if (!passOdd && arr[i] % 2 == 0) {
				passOdd = true;
			} else if (passOdd && arr[i] % 2 == 1) {
				return false;
			}
		}
		return true;
	}
	
	@Test
	public void TestIsOddBeforeEvenHelper() {
		int[] good = { 1, 1, 2 };
		assertTrue(isOddBeforeEven(good));
		int[] bad = { 1, 2, 1 };
		assertFalse(isOddBeforeEven(bad));
		// Test with single elem arrary.
		int[] single = { 1 };
		assertTrue(isOddBeforeEven(single));
		single[0] = 2;
		assertTrue(isOddBeforeEven(single));
	}
	
	@Test
	public void TestWithAlternatingArray() {
		int[] arr = { 1, 2, 3, 4, 5 };
		assertFalse(isOddBeforeEven(arr));
		OddBeforeEvenInArrary.reorder(arr);
		assertTrue(isOddBeforeEven(arr));
	}

}
