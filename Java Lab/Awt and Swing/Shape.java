public class Shape {
    public void area(double s1, double s2, double s3) // triangle
    {
        double s = (s1 + s2 + s3) / 2;
        double ans = Math.sqrt(s * (s - s1) * (s - s2) * (s - s3));
        System.out.println("Area of triangle with sides s1 (" + s1 + ") , s2 (" + s2 + ") & s3 (" + s3 + ") is " + ans);
    }

    public void area(double breadth, double length) // rectangle
    {
        System.out.println(
                "Area of Rectangle with breadth (" + breadth + ") & length (" + length + ") is " + length * breadth);
    }

    public void area(double radius) // circle
    {
        System.out.println("Area of Circle with radius (" + radius + ") is " + 3.14 * radius * radius);
    }

    public static void main(String args[]) {
        Shape obj = new Shape();
        obj.area(3, 4, 5); // triangle
        obj.area(2, 5); // rectangle
        obj.area(10); // circle
    }
}
