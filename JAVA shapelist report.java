package shapeList;

public class Circle extends Shape
{
	public void draw(int i)
	{
		System.out.println((i+1) + "번째 도형은 원입니다.");
	}
}

package shapeList;

public class Rectangle extends Shape
{
	public void draw(int i)
	{
		System.out.println((i+1) + "번째 도형은 사각형입니다.");
	}
}

package shapeList;

public class Triangle extends Shape 
{
	public void draw(int i)
	{
		System.out.println((i+1) + "번째 도형은 삼각형입니다.");
	}
}

package shapeList;

public class Shape 
{
	public Shape()
	{
	}
}

package shapeList;
import java.util.Scanner;
import java.util.ArrayList;

public class shapeList 
{
	public static void add(String a, ArrayList<String> arr)
	{
		 arr.add(a);
	}
	
	public static void print(ArrayList<String> arr)
	{
		Circle circle = new Circle();
		Triangle triangle = new Triangle();
		Rectangle rectangle = new Rectangle();
		
		for(int i=0; i<arr.size(); i++)
		{
			if(arr.get(i).equals("1"))
				triangle.draw(i);
			
			else if(arr.get(i).equals("2"))
				rectangle.draw(i);
			
			else if(arr.get(i).equals("3"))
				circle.draw(i);
		}
	}

	public static void main(String[] args) 
	{
		String input;
		ArrayList<String> lists = new ArrayList<String>();
		 
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("1번: 삼각형 추가/ 2번 : 사각형 추가 / 3번: 원추가\r\n"
				+ "4번: 도형출력 /5번: 종료");
		
		
		while(true)
		{
			input = sc.nextLine();
			
			if(input.equals("5"))
			{
				System.out.println("종료되었습니다.");
				sc.close();
				return;
			}
				
			
			else if(input.equals("4"))
			{
				print(lists);
			}
			
			else if(input.equals("3"))
			{
				add(input, lists);
				System.out.println("도형이 추가되었습니다.");
			}
			
			else if(input.equals("2"))
			{
				add(input, lists);
				System.out.println("도형이 추가되었습니다.");
			}
			
			else if(input.equals("1"))
			{
				add(input, lists);
				System.out.println("도형이 추가되었습니다.");
			}
		}
	}
}

