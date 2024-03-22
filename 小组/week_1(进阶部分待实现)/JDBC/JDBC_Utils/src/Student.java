public class Student {
    private int id;
    private String name;
    private int math;
    private int English;
    private int Chinese;

    public Student() {
    }

    public Student(int id, String name, int math, int english, int chinese) {
        this.id = id;
        this.name = name;
        this.math = math;
        English = english;
        Chinese = chinese;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getMath() {
        return math;
    }

    public void setMath(int math) {
        this.math = math;
    }

    public int getEnglish() {
        return English;
    }

    public void setEnglish(int english) {
        English = english;
    }

    public int getChinese() {
        return Chinese;
    }

    public void setChinese(int chinese) {
        Chinese = chinese;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", math=" + math +
                ", English=" + English +
                ", Chinese=" + Chinese +
                '}';
    }
}
