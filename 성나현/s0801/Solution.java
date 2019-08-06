// package s0801;

import java.io.File;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;


public class Solution {

	public static void main(String[] args) throws Exception {
		//  Scanner sc = new Scanner(new File("src/s/0725/input.txt"));
		Scanner sc = new Scanner(new File("./sample_input.txt"));

		int numTestCases = sc.nextInt();
		
		String line = System.getProperty("line.separator");
		
		for(int i=0; i<numTestCases; i++) {
			System.out.print("#" + (i+1) + " ");

			Solution ex = new Solution(); 
			int numTotalSource = 1;
			numTotalSource = sc.nextInt();
			int numFoodsSources = numTotalSource/2;
			int[] ingredients = new int[numTotalSource];
			int[] combIngredientsA = new int[numFoodsSources];
			
			int n = numTotalSource;
			int r = numFoodsSources;

			ex.doCombination(combIngredientsA, n, r, 0, 0, ingredients);
			int[][] synergy = new int[numTotalSource][numTotalSource];         

			for (int row = 0; row < numTotalSource; row++) {
				for (int column = 0; column < numTotalSource; column++) {
					synergy[row][column] = sc.nextInt();
				}
			}

			// for(int r=0; r<numTotalSource; r++) {
			// 	for(int c=0; c<numTotalSource; c++) {
			// 		System.out.print(synergy[r][c]);  
			// 		if(c==numTotalSource-1) System.out.print(line);
			// 	}
			// }

		}
	}

	

	// 재료 조합 선택1
	public void doCombination(int[] combIngredientsA, int n, int r, int index, int target, int[] ingredients){
		int[] combIngredientsB = new int[n/2];

		if(r==0){
			int idx = 0;
			for(int i=0; i<n; i++){
				final int num = i;
				
				if(!IntStream.of(combIngredientsA).anyMatch(x->x==num)){
					combIngredientsB[idx] = num;
					idx++;
				}
			}
			// A음식 조합, B음식 조합 완성
			System.out.println("A "+Arrays.toString(combIngredientsA));
			System.out.println("B "+Arrays.toString(combIngredientsB));
		}else if(target == n){ 
			return; 
		}else {
			combIngredientsA[index] = target;

			//뽑을 경우
			doCombination(combIngredientsA, n, r-1, index+1, target+1, ingredients);

			//안 뽑을 경우
			doCombination(combIngredientsA, n, r, index, target+1, ingredients);
		}

	}


}
