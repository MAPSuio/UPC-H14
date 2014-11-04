/*
# @EXPECTED_RESULTS@: CORRECT
*/

import java.util.Queue;
import java.util.LinkedList;
import java.util.Scanner;

public class hawken {
    public static Queue<Integer> qgen(){
        return new LinkedList<Integer>();
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Queue<Integer> p1stack = qgen(), p2stack = qgen();
        Queue<Integer> p1bet = qgen(), p2bet = qgen();
        int p1card, p2card;

        int n, m;

        n = in.nextInt();
        m = in.nextInt();
        for(int i = 0; i < n; i++)
            p1stack.add(in.nextInt());
        for(int i = 0; i < m; i++)
            p2stack.add(in.nextInt());

        while(p1stack.peek() != null && p2stack.peek() != null) {
            p1card = p1stack.poll();
            p2card = p2stack.poll();
            if(p1card == p2card) {
                p1bet.add(p1card);
                p2bet.add(p2card);
                for(int i = 0; i < 3; i++){
                    if(p1stack.peek() != null)
                        p1bet.add(p1stack.poll());
                    if(p2stack.peek() != null)
                        p2bet.add(p2stack.poll());
                }
            } else if(p1card > p2card) {
                while(p1bet.peek() != null) {
                    p1stack.add(p1bet.poll());
                }
                p1stack.add(p1card);
                while(p2bet.peek() != null) {
                    p1stack.add(p2bet.poll());
                }
                p1stack.add(p2card);
            } else /* if(p1card < p2card) */ {
                while(p2bet.peek() != null) {
                    p2stack.add(p2bet.poll());
                }
                p2stack.add(p2card);
                while(p1bet.peek() != null) {
                    p2stack.add(p1bet.poll());
                }
                p2stack.add(p1card);
            }
        }
        if(p1stack.peek() == null && p2stack.peek() == null) {
            System.out.println("draw");
        } else if(p1stack.peek() != null) {
            System.out.println("you");
        } else /* if(p2stack.peek() != null) */ {
            System.out.println("mike");
        }
    }
}
