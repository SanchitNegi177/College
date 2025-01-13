public class UseOfAbstractClass {
    public static void main(String[] args) {
        Circle circle = new Circle();
        Rectangle rectangle = new Rectangle();

        circle.draw();
        rectangle.draw();

        circle.display();
        rectangle.display();
    }
}
abstract class Shape {
    public abstract void draw();

    public void display() {
        System.out.println("This is a shape.");
    }
}

class Circle extends Shape {
    public void draw() {
        System.out.println("Drawing a circle");
    }
}

class Rectangle extends Shape {
    public void draw() {
        System.out.println("Drawing a rectangle");
    }
}

