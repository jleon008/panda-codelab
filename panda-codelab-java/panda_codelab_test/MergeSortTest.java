package panda_codelab_test;

import static org.junit.Assert.*;
import org.junit.Test;

// import classes to be tested.
import panda_codelab_soln.MergeSort;
//import panda_codelab.MergeSort;

public class MergeSortTest {

	@Test
	public void NullInputIntArr() {
		int[] arr = null;
		int[] result = MergeSort.sort(arr);
		assertNull(result);
	}
	
	@Test
	public void EmptyInputIntArr() {
		int[] arr = new int[0];
		int[] result = MergeSort.sort(arr);
		assertArrayEquals(arr, result);
	}
	
	@Test
	public void SingleElemInputIntArr() {
		int[] arr = new int[1];
		int[] result = MergeSort.sort(arr);
		assertArrayEquals(arr, result);
	}
	
	@Test
	public void DistinctElemInputIntArr() {
		int[] arr = { 5, 4, 3, 2, 1 };
		int[] result = MergeSort.sort(arr);
		int[] expected = { 1, 2, 3, 4, 5 };
		assertArrayEquals(expected, result);
	}
	
	@Test
	public void AllSameElemInputIntArr() {
		int[] arr = { 1, 1, 1 };
		int[] result = MergeSort.sort(arr);
		assertArrayEquals(arr, result);
	}
	
	@Test
	public void SortedInputIntArr() {
		int[] arr = { 1, 2, 3, 4, 5 };
		int[] result = MergeSort.sort(arr);
		assertArrayEquals(arr, result);
	}

}
