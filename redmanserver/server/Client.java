package server;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Observable;
import java.util.Observer;
import java.util.concurrent.ExecutorService;

public abstract class Client implements Observer{
	protected ClientListener cl;
	protected Socket sock;
	private DataOutputStream out;

	public Client(Socket sock, ExecutorService es) {
		this.sock = sock;
		this.cl = new ClientListener(sock);
		cl.addObserver(this);
		es.execute(cl);
		
		try {
			this.out = new DataOutputStream(sock.getOutputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void update(Observable arg0, Object arg1) {
		onMessage(cl.getMessage());
	}
	
	public void send(String s) {
		System.out.println("sending : " + s);
		s+= "\n";
		try {
			byte message[] = s.getBytes();
			out.write(message);
			out.flush();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public abstract void onMessage(String s);
	
}
