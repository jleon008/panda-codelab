package panda_codelab_soln;

public class MergeSort {
	public static int[] sort(int[] arr) {
		if (arr == null) {
			return null;
		}
		if (arr.length < 2) {
			return arr;
		}
		int middle = arr.length / 2;

		int[] left = new int[middle];
		System.arraycopy(arr, 0, left, 0, middle);
		int[] sorted_left = sort(left);

		int[] right = new int[arr.length - middle];
		System.arraycopy(arr, middle, right, 0, right.length);
		int[] sorted_right = sort(right);
		
		return merge(sorted_left, sorted_right);
	}
	
	private static int[] merge(int[] a, int[] b) {
		int[] c = new int[a.length + b.length];
		int a_iter = 0;
		int b_iter = 0;
		int c_iter = 0;
		while (a_iter < a.length && b_iter < b.length) {
			if (a[a_iter] < b[b_iter]) {
				c[c_iter++] = a[a_iter++];
			} else {
				c[c_iter++] = b[b_iter++];
			}
		}
		while (a_iter < a.length) {
			c[c_iter++] = a[a_iter++];
		}
		while (b_iter < b.length) {
			c[c_iter++] = b[b_iter++];
		}
		return c;
	}
}
