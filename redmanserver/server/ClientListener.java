package server;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Observable;

import slave.SlaveManager;

public class ClientListener extends Observable implements Runnable{

	Socket socket;
	BufferedReader in;
	boolean running;
	String message;


	public ClientListener(Socket socket) {
		this.socket = socket;
		try {
			in = new BufferedReader (new InputStreamReader (socket.getInputStream()));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String listenClient() {
		try {
			return in.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		running = false;
		return "disconnected";
	}

	@Override
	public void run() {
		running = true;
		while(running) {
			message = listenClient();
			setChanged();
			notifyObservers(); 
		}
	}

	public String getMessage() {
		return message;
	}

	public void stop() {
		running = false;
	}

}
