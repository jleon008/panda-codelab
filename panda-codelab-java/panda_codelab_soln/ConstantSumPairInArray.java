package panda_codelab_soln;

public class ConstantSumPairInArray {
	public static boolean existPairWithSum(int arr[], int sum) {
		if (arr == null) {
			return false;
		}
		int begin = 0;
		int end = arr.length - 1;
		while (begin != end) {
			int current_sum = arr[begin] + arr[end];
			if (current_sum < sum) {
				begin++;
			} else if (current_sum == sum) {
				return true;
			} else {
				end--;
			}
		}
		return false;
	}
}
