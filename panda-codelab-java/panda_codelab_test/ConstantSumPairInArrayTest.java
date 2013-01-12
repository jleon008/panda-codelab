package panda_codelab_test;

import static org.junit.Assert.*;
import org.junit.Test;

import panda_codelab_soln.ConstantSumPairInArray;

public class ConstantSumPairInArrayTest {
	@Test
	public void TestWithSingleElemArray() {
		int sum = 1;
		int[] arr = { sum + sum };
		assertFalse(ConstantSumPairInArray.existPairWithSum(arr, sum));
	}
	
	@Test
	public void TestAllSameElemArrayWithoutSuchPair() {
		int[] arr = { 1, 1, 1 };
		int sum = 4;
		assertFalse(ConstantSumPairInArray.existPairWithSum(arr, sum));
	}

	@Test
	public void TestAllSameElemArrayWithSuchPair() {
		int[] arr = { 1, 1, 1 };
		int sum = 2;
		assertTrue(ConstantSumPairInArray.existPairWithSum(arr, sum));
	}
	
	@Test
	public void TestArrayWithoutSuchPair() {
		int[] arr = { 1, 2, 3, 4, 5 };
		int sum = 10;
		assertFalse(ConstantSumPairInArray.existPairWithSum(arr, sum));
	}
	
	@Test
	public void TestArrayWithSuchPair() {
		int[] arr = { 1, 2, 3, 4, 5 };
		int sum = 7;
		assertTrue(ConstantSumPairInArray.existPairWithSum(arr, sum));
	}
}
