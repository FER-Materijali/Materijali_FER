package hr.fer.oop.lab4.prob3;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * A class that uses a dictionary to store the students and their grades.
 * 
 * @author karlo
 *
 */
public class Grades {
	
	/** The students. */
	private static Map<String, List<Integer>> students = new LinkedHashMap<>();

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {	
        System.out.println("Enter student name and grade, type 'KRAJ' to finish");
        inputData();    
        outputData();
	}

	/**
	 * Input data.
	 */
	private static void inputData() {
		Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String line = sc.nextLine();
            if (line.toUpperCase().equals("KRAJ")) {
                break;
            }

            String[] input = line.split("\\s");
            String name;
            Integer grade;
            try {
                name = input[0];
                grade = Integer.parseInt(input[1]);
            }
            catch(NumberFormatException e) {
            	System.err.println("Invalid input: grades can only be numbers");
            	continue;	
            }
            catch(ArrayIndexOutOfBoundsException  e) {
            	System.err.println("Invalid input: expected format {NAME} {GRADE}");
            	continue;	
            }
            
            List<Integer> grades = students.get(name);
            if (grades == null) {
            	grades = new ArrayList<>();
            }

            grades.add(grade);
            students.put(name, grades);
        }
        sc.close();
    }

	/**
	 * Output data.
	 */
	private static void outputData() {
        for(Map.Entry<String, List<Integer>> student : students.entrySet()) {
            StringBuilder sb = new StringBuilder();
            String name = student.getKey();
            List<Integer> grades = student.getValue();

            int numOfGrades = grades.size();
            int sumOfGrades = 0;

            sb.append("Student: ").append(name).append("\n");
            sb.append("\tNumber of grades: ").append(numOfGrades).append("\n");
            sb.append("\tGrades are: ");
            for(Integer grade : grades){
                sumOfGrades += grade;
                sb.append(grade).append(" ");
            } 
            sb.append("\n");
            sb.append("\tDifferent grades: ");

            Collections.sort(grades);
            Set<Integer> uniqueGrades = new HashSet<>(grades);
            for(Integer grade : uniqueGrades){
                sb.append(grade).append(" ");
            }          
            sb.append("\n");
            
            double average = (double)sumOfGrades / numOfGrades;
            sb.append("\tAverage grade is: ").append(new DecimalFormat("#.#####").format(average)).append("\n");

            double sumOfSquares = 0;
            for(Integer grade : grades){
                sumOfSquares += Math.pow(grade - average, 2);
            }
            
            double stdDev = Math.sqrt(sumOfSquares / numOfGrades);
            sb.append("\tStandard deviation: ").append(new DecimalFormat("#.#####").format(stdDev)).append("\n");
            System.out.println(sb);
        }
    }
}
