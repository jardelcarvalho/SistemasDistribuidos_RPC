//package example.hello;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Calculator extends Remote {
    float mult(float a, float b) throws RemoteException;
    float div(float a, float b) throws RemoteException;
    float add(float a, float b) throws RemoteException;
    float sub(float a, float b) throws RemoteException;
}