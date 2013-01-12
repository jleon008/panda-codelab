package panda_codelab_soln;

public class OddBeforeEvenInArrary {
	public static void reorder(int[] arr) {
		assert(arr != null);
		int open_slot = 0;
		int next = 0;
		while (next < arr.length) {
			if (arr[next] % 2 == 1) {
				swap(arr, open_slot++, next);
			}
			next++;
		}
	}
	
	private static void swap(int[] arr, int index1, int index2) {
		assert(index1 < arr.length);
		assert(index2 < arr.length);
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}
