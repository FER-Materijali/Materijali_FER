package hr.fer.oop.vjezba;

/**
 * First task from midterm exam
 * 
 * @author KarloVrbic
 * @version 1.0
 */
public class MergeArrays {
	
	/**
	 * Main method used for testing purposes
	 * @param args Not used
	 */
	public static void main1(String[] args) {
		int[] firstArray = {54, 23, 6, 4, 1};
		int[] secondArray = {65, 30, 8, 7, 3};
		int[] mergedArray = mergeArrays(firstArray, secondArray);
		
		System.out.printf("\n");
		for(int num : mergedArray)
			System.out.printf("%d ", num);

	}
	
	/**
	 * Merging two sorted arrays
	 * @param array1 Sorted array
	 * @param array2 Sorted array
	 * @return Merged sorted array
	 */
	public static int[] mergeArrays(int[] array1, int[] array2){
		int[] mergedArray = new int[array1.length + array2.length];
		int index1 = 0;
		int index2 = 0;
		int index3 = 0;
		
		while(index1 != array1.length && index2 != array2.length){
			if(array1[index1] > array2[index2]){
				mergedArray[index3] = array1[index1];
				index1++;
				index3++;
			}
			else if(array1[index1] < array2[index2]){
				mergedArray[index3] = array2[index2];
				index2++;
				index3++;
			}
			else{
				mergedArray[index3] = array1[index1];
				index3++;
				
				mergedArray[index3] = array2[index2];
				index1++;
				index2++;
				index3++;
			}
		}

		if(index1 == array1.length)
			while(!(index2 == array2.length)){
				mergedArray[index3] = array2[index2];
				index2++;
			}
		else if(index2 == array2.length){
			while(!(index1 == array1.length)){
				mergedArray[index3] = array1[index1];
				index1++;
			}
		}
		return mergedArray;
	}

}
