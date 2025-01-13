class Staff {
    int code;
    String name;

    Staff(int code, String name) {
        this.code = code;
        this.name = name;
    }

    void display() {
        System.out.println("CODE: " + code);
        System.out.println("NAME: " + name);
    }
}

class Teacher extends Staff {
    String subject, publication;

    Teacher(int code, String name, String subject, String publication) {
        super(code, name);
        this.subject = subject;
        this.publication = publication;
    }

    void display() {
        super.display();
        System.out.println("SUBJECT: " + subject);
        System.out.println("PUBLICATION: " + publication);
    }
}

class Typist extends Staff {
    int speed;

    Typist(int code, String name, int speed) {
        super(code, name);
        this.speed = speed;
    }

    void display() {
        super.display();
        System.out.println("SPEED: " + speed);
    }

}

class Officer extends Staff {
    String grade;

    Officer(int code, String name, String grade) {
        super(code, name);
        this.grade = grade;
    }

    void display() {
        super.display();
        System.out.println("GRADE: " + grade);
    }
}

class Regular extends Typist {
    int regularWage;

    Regular(int code, String name, int speed, int regularWage) {
        super(code, name, speed);
        this.regularWage = regularWage;
    }

    void display() {
        super.display();
        System.out.println("Regular Wage: " + regularWage);
    }
}

class Casual extends Typist {
    int dailyWage;

    Casual(int code, String name, int speed, int dailyWage) {
        super(code, name, speed);
        this.dailyWage = dailyWage;
    }

    void display() {
        super.display();
        System.out.println("Daily Wage: " + dailyWage);
    }

}

public class Program8 {
    public static void main(String args[]) {
        Regular r = new Regular(1, "Sanchit", 2, 2000);
        Casual c = new Casual(2, "Rishi", 1, 1000);
        Teacher t = new Teacher(3, "Anshika", "Theory of computaion", "IEEE");
        Officer o = new Officer(4, "Ramesh", "A+");
        r.display();
        System.out.println();
        c.display();
        System.out.println();
        t.display();
        System.out.println();
        o.display();
        System.out.println();
    }
}
