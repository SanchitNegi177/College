public class Student {
    int id;
    String name, branch, city, university;

    public Student(int id, String name, String branch, String city, String university) {
        this.id = id;
        this.name = name;
        this.branch = branch;
        this.city = city;
        this.university = university;
    }

    // chaining contructors
    public Student(int id) {
        this(id, null, null, null, null);
    }

    public Student(int id, String name) {
        this(id, name, null, null, null);
    }

    public Student(int id, String name, String branch) {
        this(id, name, branch, null, null);
    }

    public Student(int id, String name, String branch, String city) {
        this(id, name, branch, city, null);
    }

    public void display() {
        System.out.println("ID: " + id);
        System.out.println("NAME: " + name);
        System.out.println("BRANCH: " + branch);
        System.out.println("CITY: " + city);
        System.out.println("UNIVERSITY: " + university);
    }

    public static void main(String args[]) {
        Student s1 = new Student(1, "Sanchit", "CSE", "DDN", "GEHU");
        s1.display();
        System.out.println();
        Student s2 = new Student(2, "Rish", "CSE");
        s2.display();
    }
}
