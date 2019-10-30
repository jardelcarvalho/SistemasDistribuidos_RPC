//package example.hello;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Client {

    private Client() {}

    public static void main(String[] args) {

        String host = (args.length < 1) ? null : args[0];
	    System.out.println("Endereco do servidor: " + host);
        try {
            Registry registry = LocateRegistry.getRegistry(host);
            Calculator stub = (Calculator) registry.lookup("Calculator");
            System.out.println("Calculadora");
            float res = stub.add(4, 2);
            System.out.println("4 + 2 = " + Float.toString(res));
            res = stub.sub(4, 2);
            System.out.println("4 - 2 = " + Float.toString(res));
            res = stub.mult(4, 2);
            System.out.println("4 * 2 = " + Float.toString(res));
            res = stub.div(4, 2);
            System.out.println("4 / 2 = " + Float.toString(res));
        } catch (Exception e) {
            System.err.println("Client exception: " + e.toString());
            e.printStackTrace();
        }
    }
}