import java.util.Scanner;

public class StringFunctions 
{
    public static void main(String[] args) 
    {
        Scanner obj = new Scanner(System.in);
        System.out.print("Enter String 1: ");
        String s1 = obj.nextLine();
        System.out.print("Enter String 2: ");
        String s2 = obj.nextLine();

        System.out.println("STRING CLASS METHODS");
        // Converts s1 to lowercase
        String s3 = s1.toLowerCase();
        System.out.println("String 1 in LowerCase: "+s3);

        // Converts s2 to Uppercase
        s3 = s2.toUpperCase();
        System.out.println("String 2 in LowerCase: "+s3);
        
        // Replace all apperances of o with m without interpreting the pattern as regular expression
        s3 = s1.replace('o', 'm');
        System.out.println("Replace all apperances of o with m in String 1: "+s3);
        
        // remove white spaces at the beginning and the end of the string
        s3 = s1.trim();
        System.out.println("remove white spaces at the beginning and the end of the string 1: "+s3);

        // returns true if equal strings otherwise false
        boolean check = s1.equals(s2);
        System.out.println("String1==String2 (Case Sensitive):"+check);
        
        // ignores the case of characters while checking
        check = s1.equalsIgnoreCase(s2);
        System.out.println("String1==String2 :"+check);

        // gives length of s1
        int len = s1.length();
        System.out.println("Length of string 1: "+len);

        // return negative if s1<s2, positive if s1>s2 and 0 if s1==s2

        int com = s1.compareTo(s2);
        System.out.println("ASCII of String 1 - ASCII of String 2: "+com);
        
        // concatenates s1 and s2
        s3 = s1.concat(s2);
        System.out.println("Concatenate String 1 and String 2: "+s3);
        
        // Replace the occurences of substring that match a specified regula expression
        // pattern with another string
        System.out.println("Replace the occurences of substring that match a specified regula expression pattern with another string :");
        s3 = s1.replaceAll("l+", "t");
        System.out.println(s3);

        // gives substring starting from nth character
        s3 = s1.substring(3);
        System.out.println("Substring of String 1 from index 3: "+s3);
        
        // gives substring starting from nth to mth character
        s3 = s1.substring(2, 5);
        System.out.println("Substring of String 1 from index 2 to 5: "+s3);

        // gives the position of x occuring after nth position
        int index = s1.indexOf('l', 2);
        System.out.println("Index of l :"+index);

        // gives the nth character of s1
        char ch = s1.charAt(3);
        System.out.println("Character at index 3: "+ch);

        // startswith and endswith return true and false
        check = s1.startsWith("He");
        System.out.println("start with (HE) :"+check);
        
        check = s2.endsWith("ld");
        System.out.println("end with (ld) :"+check);

        obj.close();
    }
}