

interface Dad 
{
    int x=10;
    public void show();
}
interface Mom
{
    int x=20;
    public void show();
}
class Son implements Dad,Mom
{ 
    public void show()
    {
        System.out.println(Mom.x);
        System.out.println("Son show()");
    }
}

public class MultipleInheritenc 
{
    public static void main(String args[])
    {
        Son ob=new Son();
        ob.show();
    }
}
