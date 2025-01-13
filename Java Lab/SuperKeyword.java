class parent
{
    int x;
    parent(){}
    parent(int a)
    {
        this.x=a;
    }
    void display()
    {
        System.out.println("display of parent");
        System.out.println("parent x = "+x);
    }
}

public class SuperKeyword extends parent
{
    int x;
    SuperKeyword(){}
    SuperKeyword(int a,int b)
    {
        super(a);
        this.x=b;
    }
    void display()
    {
        super.display();
        System.out.println("display of child");
        System.out.println(" child x = "+x);

    }
    public static void main(String args[])
    {
        SuperKeyword ob=new SuperKeyword();
        ob.display();
        SuperKeyword obj=new SuperKeyword(5,10);
        obj.display();

        System.out.println(obj.x);  //child has overridden value of x of parent

    }
}