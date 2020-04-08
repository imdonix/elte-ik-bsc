

public class BitwiseExample
{
    public static void main(String[] args)
    {
        byte x;

        x = 0b00001100;
        System.out.println("x = " + x);
        // előjelbit 0
        // 1*2^3 + 1*2^2 + 0*2^1 + 0*2^0 == 8 + 4 == 12

        //x = 0b10001101; // 0b10001101 típusa int, x típusa byte

        x = (byte)0b10001101;
        System.out.println("x = " + x);
        // előjelbit 1, kettes komplemensképzésű ábrázolás
        // -(1110010b + 1) == -1110011b == -(1*2^6 + 1*2^5 + 1*2^4 + 0*2^3 + 0*2^2 + 1*2^1 + 1*2^0) == -(64 + 32 + 16 + 2 + 1) == -115

        System.out.println("");

        byte mask;
        x    = 0b00001100;
        mask = 0b00001010;

        System.out.println("x        = " + Integer.toBinaryString(x) + "b");
        System.out.println("mask     = " + Integer.toBinaryString(mask) + "b");

        System.out.println("");

        System.out.format("%-10s = %7s", "~x", Integer.toBinaryString(~x) + "b"); System.out.println(""); // negate
        System.out.format("%-10s = %7s", "x & mask", Integer.toBinaryString(x & mask) + "b"); System.out.println(""); // and
        System.out.format("%-10s = %7s", "x | mask", Integer.toBinaryString(x | mask) + "b"); System.out.println(""); // or
        System.out.format("%-10s = %7s", "x ^ mask", Integer.toBinaryString(x ^ mask) + "b"); System.out.println(""); // xor
        System.out.format("%-10s = %7s", "x << 1", Integer.toBinaryString(x << 1) + "b"); System.out.println(""); // shift to the left
        System.out.format("%-10s = %7s", "x >> 2", Integer.toBinaryString(x >> 2) + "b"); System.out.println(""); // shift to the right // előjelbit lép be
    }
}

