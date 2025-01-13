import java.util.Scanner;
class Marks 
{
    public static void main(String args[])
    {
        Scanner obj = new Scanner(System.in);
        int range1=0,range2=0,range3=0,range4=0;
        
        System.out.println("Enter no. of students: ");
        int n=obj.nextInt();
        int arr[]=new int[n];
        
        System.out.println("Enter marks of "+ n +" students: ");
        for(int i=0;i<n;i++)
            arr[i]=obj.nextInt();

        for(int i=0;i<n;i++)
        {
            if(arr[i]>=81)
                range1++;
            else if(arr[i]>=61)
                range2++;
            else if(arr[i]>=41)
                range3++;
            else
                range4++;
        }
        System.out.println("No. of student who have marks in range 81-100: "+range1);
        System.out.println("No. of student who have marks in range 61-80: "+range2);
        System.out.println("No. of student who have marks in range 41-60: "+range3);
        System.out.println("No. of student who have marks in range 0-40: "+range4);
        obj.close();
    }
    
}
