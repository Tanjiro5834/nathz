import java.util.Scanner;

public class CollegeList {

	public static void main(String[] args) {
		//nag instantiate tayo dito ng mga class na ginawa natin para globally ma access sya and para 'di redundant
		Scanner scanner = new Scanner(System.in);
		Employee employee = null;
		Person person = null;
		Student student = null;
		Faculty faculty = null;
		
		//declare na natin dito yung mga necessary variables para di paulit ulit sa pag ddeclare ng bago
		String name, contactNumber, department;
		double salary;
		
		//while loop para continous yung pag ask sa user as long as hindi sila ng iinput ng 'e'.
		while(true){
			System.out.print("Press E for employee, F for faculty, or S for student: ");
			String input = scanner.next().toUpperCase();
			scanner.nextLine();
			
			if(input.equalsIgnoreCase("exit")){
				break;
			}
			
			switch(input){
			case "E":
				System.out.println("Type employee's name, contact number, salary, and department.");
				
				System.out.print("Name: ");
				name = scanner.nextLine();
				
				System.out.print("Contact number: ");
				contactNumber = scanner.nextLine();
				
				System.out.print("Salary: ");
				while(!scanner.hasNextDouble()){ //eto chinecheck natin if may decimal yung nilagay ni user
					System.out.println("Invalid salary input. try again.");
					scanner.next();
				}
				salary = scanner.nextDouble();
				scanner.nextLine();
				
				System.out.print("Department: ");
				department = scanner.nextLine();
				
				System.out.println("---------------------");
				
				//create person and employee objects then print natin gamit yung toString method
				person = new Person(name, contactNumber);
				employee = new Employee(name, contactNumber, salary, department);
				System.out.println(person.toString() + "\n" + employee.toString());
				break;
				
			case "F":
				System.out.print("Press Y if the faculty member is regular or not: ");
				char response = scanner.next().charAt(0); //char nalang kasi single letter lang 
				scanner.nextLine();
				if(response == 'y'){
					System.out.print("Faculty member name: "); 
					String facultyMember = scanner.nextLine();
					
					System.out.print("Contact number: ");
					String contact = scanner.nextLine();
					
					System.out.print("Salary: ");
					salary = scanner.nextDouble();
					scanner.nextLine(); //consume left over newline para continous yung pag ask ng input, laging may ganito every time na hindi nalabas yung sunod na prompt especially numeric data type
					
					System.out.print("Department: ");
					department = scanner.nextLine();
					
					System.out.println("---------------------");
					
					person = new Person(facultyMember, contact);
					faculty = new Faculty(salary, department, true);
					System.out.println(person.toString() + "\n" + faculty.toString());
				}else{
					System.out.println("Cancelled.");
				}
				break;
				
			case "S":
				System.out.print("Enter student's program e.g. BSIT, BSTM, BSCS: ");
				String program = scanner.nextLine();	
				
				System.out.print("Year level: ");
				int yrLevel = scanner.nextInt();
				scanner.nextLine();
				
				System.out.print("Student name: ");
				String studentName = scanner.nextLine();
				
				System.out.print("Contact number: ");
				String contact = scanner.nextLine();
				
				System.out.println("---------------------");
				
				if(!program.isEmpty() && yrLevel > 0){ //check if may input dun sa program and if yung year level is greater than 0
					person = new Person(studentName, contact);
					student = new Student(studentName, contact, program, yrLevel);
					System.out.println(person.toString() + "\n" + student.toString());
				}else{
					System.out.println("Enter program and year level.");
				}
				break;
			}
		}
		scanner.close(); //close natin yung scanner para avoid resource leaks
	}
}
class Person{ //eto yung pinaka parent class since i-iinherit ng employee at student class yung mga variables dito
    private String name, contactNum;
    
    Person(String name, String contactNum){ //default constructor
        this.name = name;
        this.contactNum = contactNum;
    }
    
    public String getName(){
        return name;
    }
    
    public String getContactNum(){
        return contactNum;
    }
    
    public void setName(String n){
        name = n;
    }
    
    public void setContactNum(String c){
        contactNum = c;
    }

    @Override
    public String toString(){
        return "Name: " + name + "\nContact Number: " + contactNum;
    }
}

class Student extends Person{ //subclass na ininherit yung attributes ni Person class
    private String program;
    private int yearLevel;
    
    Student(String name, String contactNum, String program, int yearLevel){
    	super(name, contactNum); //kino call nito yung constructor ni person, para magamit din natin yung constructor ni person pag mag aadd tayo ng bagong student
        this.program = program;
        this.yearLevel = yearLevel;
    }
    
    public String getProgram(){
        return program;
    }
    
    public int getYearLevel(){
        return yearLevel;
    }
    
    public void setProgram(String p){
        program = p;
    }
    
    public void setYearLevel(int y){
        yearLevel = y;
    }

    @Override
    public String toString() {
        return "Program: " + program + "\nYear Level: " + yearLevel;
    }
}

class Employee extends Person{ //ganon lang din, subclass ni person
    private double salary;
    private String department;
    
    Employee(String name, String contactNum, double salary, String department){
        super(name, contactNum);
        this.salary = salary;
        this.department = department;
    }
    
    public double getSalary() {
        return salary;
    }
    
    public String getDepartment() {
        return department;
    }
    
    public void setSalary(double s) {
        salary = s;
    }
    
    public void setDepartment(String d) {
        department = d;
    }

    @Override
    public String toString() {
        return "Salary: " + salary + "\nDepartment: " + department;
    }
}

class Faculty extends Employee{ //eto naman yung subclass ng isa pang subclass, since ang mga nasa faculty is employees so we want to inherit the attributes from the employee class papunta dito
	private boolean status;
	public boolean isRegular;
	
	public Faculty(double salary, String department, boolean isRegular) {
		 super(department, department, salary, department);
	     this.isRegular = isRegular;
	}
	public String toString() {
        return super.toString() + "\nRegular Status: " + (isRegular ? "Regular" : "Not Regular");
    }
}
