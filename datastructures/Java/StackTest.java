// javac -g Stack.java StackTest.java 
// java StackTest

class StackTest {
	public static void main(String[] args) {
		Stack<Integer> s = new Stack<Integer>();

		System.out.print("is empty? ");
		System.out.println(s.isEmpty());

		System.out.print("stack size: ");
		System.out.println(s.size());

		System.out.println("add element 128 elemts [0,127]");
		for (int i=0; i<128; i++) {
			s.push(i);
		}

		System.out.print("is empty? ");
		System.out.println(s.isEmpty());

		System.out.print("stack size: ");
		System.out.println(s.size());
		System.out.print("peek top element: ");
		System.out.println(s.peek());
		System.out.print("stack size: ");
		System.out.println(s.size());
		System.out.print("pop top element: ");
		System.out.println(s.pop());
		System.out.print("stack size: ");
		System.out.println(s.size());
		System.out.print("peek top element: ");
		System.out.println(s.peek());
	}
}