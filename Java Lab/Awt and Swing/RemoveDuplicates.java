import java.util.Scanner;
public class RemoveDuplicates {
    public static String removeDup(StringBuffer str) {
        int[] freq = new int[256];

        StringBuffer result = new StringBuffer();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (freq[ch] == 0)
                result.append(ch);
            freq[ch]++;
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        StringBuffer str = new StringBuffer(sc.nextLine());
        System.out.println("Original string:" + str);
        System.out.println("String after removing duplicates:" + removeDup(str));
        sc.close();
    }
}
