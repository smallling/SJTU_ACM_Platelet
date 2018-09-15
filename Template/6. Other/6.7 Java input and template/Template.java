import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Template {
    // Input
    private static BufferedReader reader;
    private static StringTokenizer tokenizer;

    private static String next() {
        try {
            while (tokenizer == null || !tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
            // do nothing
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() {
        return Integer.parseInt(next());
    }

    private static double nextDouble() {
        return Double.parseDouble(next());
    }

    private static BigInteger nextBigInteger() {
        return new BigInteger(next());
    }

    public static void main(String[] args) {
        reader = new BufferedReader(new InputStreamReader(System.in));
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext())
            scanner.next();
    }

    // BigInteger & BigDecimal
    private static void bigDecimal() {
        BigDecimal a = BigDecimal.valueOf(1.0);
        BigDecimal b = a.setScale(50, RoundingMode.HALF_EVEN);
        BigDecimal c = b.abs();
        // if scale omitted, b.scale is used
        BigDecimal d = c.divide(b, 50, RoundingMode.HALF_EVEN);
        // since Java 9
        // BigDecimal e = d.sqrt(new MathContext(50, RoundingMode.HALF_EVEN));
        BigDecimal x = new BigDecimal(BigInteger.ZERO);
        BigInteger y = BigDecimal.ZERO.toBigInteger(); // RoundingMode.DOWN
        y = BigDecimal.ZERO.setScale(0, RoundingMode.HALF_EVEN).unscaledValue();
    }

    // sqrt for Java 8
    private static BigDecimal sqrt(BigDecimal a, int scale, RoundingMode mode) {
        if (a.equals(BigDecimal.ZERO))
            return BigDecimal.ZERO;
        a = a.setScale(scale, mode);
        BigDecimal ans = a;
        BigDecimal TWO = BigDecimal.valueOf(2L);
        for (int i = 1; i <= scale; i++)
            ans = ans.add(a.divide(ans, scale, mode)).divide(TWO, scale, mode);
        return ans;
    }

    private static BigInteger sqrt(BigInteger a) {
        BigInteger about = BigInteger.ZERO.setBit(a.bitLength() / 2);
        return sqrt(new BigDecimal(a.toString()), new BigDecimal(about.toString())).setScale(0, RoundingMode.FLOOR).unscaledValue();
    }

    private static BigDecimal sqrt(BigDecimal a, BigDecimal initial) {
        if (a.equals(BigDecimal.ZERO))
            return BigDecimal.ZERO;
        a = a.setScale(50, RoundingMode.HALF_EVEN);
        BigDecimal ans = initial;
        for (int i = 1; i <= 10; i++)
            ans = ans.add(a.divide(ans, RoundingMode.HALF_EVEN)).divide(BigDecimal.valueOf(2), RoundingMode.HALF_EVEN);
        return ans;
    }

    // ArrayList
    private static void arrayList() {
        List<Integer> list = new ArrayList<>();
        // Generic array is banned
        List[] lists = new List[100];
        lists[0] = new ArrayList<Integer>();
        // for List<Integer>, remove(Integer) stands for element, while remove(int) stands for index
        list.remove(list.get(1));
        list.remove(list.size() - 1);
        list.clear();
    }

    // Queue
    private static void queue() {
        LinkedList<Integer> queue = new LinkedList<>();
        // return the value without popping
        queue.peek();
        // pop and return the value
        queue.poll();
        Deque<Integer> deque = new ArrayDeque<>();
        deque.peekFirst();
        deque.peekLast();
        deque.pollFirst();
    }

    // Others
    private static void others() {
        Arrays.sort(new int[10]);
        Arrays.sort(new Integer[10], (a, b) -> {
            if (a.equals(b)) return 0;
            if (a > b) return -1;
            return 1;
        });
        Arrays.sort(new Integer[10], Comparator.comparingInt((a) -> (int) a).reversed());
        long a = 1_000_000_000_000_000_000L;
        int b = Integer.MAX_VALUE;
        int c = 'a';
    }
}
