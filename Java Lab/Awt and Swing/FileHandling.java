import java.io.*;
import java.util.*;

public class FileHandling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String fileName = "text.txt";
        System.out.println("Enter sentence");
        String sentence = sc.nextLine();

        // Write sentences to file
        // FileWriter fw = new FileWriter(fileName, true); // true to append
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) 
        {
            writer.println(sentence);
            System.out.println("Sentences written to file: " + fileName);
        } 
        catch (IOException e) 
        {
            System.out.println("Error writing to file: " + e.getMessage());
        }

        // Read file and display vowels
        try 
        {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            System.out.println("\nVowels in the file:");
            String line;
            int line_cnt=0,word_cnt=0,char_cnt=0;
            while ((line = reader.readLine()) != null) 
            {
                line_cnt++;
                char_cnt+=line.length();
                displayVowels(line);
                line=line.trim();
                for(int i=0;i<line.length();i++)
                {
                    if(line.charAt(i)==' ')
                        word_cnt++;
                }
                word_cnt++;
            }
        System.out.println("wordcnt " + word_cnt);
        System.out.println("char_cnt " + char_cnt);
        System.out.println("line_cnt " + line_cnt);
        }
        catch (IOException e) 
        {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }

    public static void displayVowels(String str) {
        String vowels = "aeiouAEIOU";
        for (char ch : str.toCharArray()) {
            if (vowels.indexOf(ch) != -1)
                System.out.print(ch);
            if (ch == ' ')
                System.out.print(" ");
        }
        System.out.println();
    }
}
