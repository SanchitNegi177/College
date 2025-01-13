import java.util.Scanner;

public class SumDiagonal {
    public static void main(String args[]) {
        Scanner obj = new Scanner(System.in);
        System.out.println("Enter order of matrix N x N ");
        int n = obj.nextInt();
        int arr[][] = new int[n][n];

        System.out.println("Enter elements in " + n + " x " + n + " matrix");
        for (int i = 0; i < n; i++) // Taking input in array
            for (int j = 0; j < n; j++)
                arr[i][j] = obj.nextInt();

        int leftDiagonalSum = 0, rightDiagonalSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) // Finding Sum
            {
                if (i == j)
                    rightDiagonalSum += arr[i][j];
                if (i + j == n - 1) {
                    leftDiagonalSum += arr[i][j];
                }
            }
        }
        System.out.println("Sum of Left Diagonal: " + leftDiagonalSum);
        System.out.println("Sum of Right Diagonal: " + rightDiagonalSum);
        obj.close();
    }
}
