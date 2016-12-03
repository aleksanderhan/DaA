import java.util.EmptyStackException;

/*
 * Dynamically sized generic stack
 */ 
public class Stack<T> {
        private T[] elements;
        private int size = 0;
        private int n = 5;
        
        @SuppressWarnings("unchecked")
        public Stack() {
            elements = (T[]) new Object[1<<n]; // 1<<n = 2^n, faster than Math.pow
            n++;
        }
         
        public boolean isEmpty() {
            if (size == 0) {
                return true;
            } else {
                return false;
            }
        }
         
        public int size() {
            return size;
        }
        
        @SuppressWarnings("unchecked")
        public void push(T elem) {
            try {
                elements[size] = elem;
                size++;
            } catch (ArrayIndexOutOfBoundsException e) {
                T[] temp = (T[]) new Object[1<<n];
                n++;
                for (int j=0; j<size; j++) {
                    temp[j] = elements[j];
                }
                elements = temp;
                elements[size] = elem;
                size++;
            }
        }
         
        public T pop() {
            if (isEmpty()) {
                throw new EmptyStackException();
            }
            T elem = elements[size-1];
            size--;
            return elem;
        }
         
        public T peek() {
            return elements[size-1];
        }
                  
}