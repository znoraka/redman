package server;

import global.Globals;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import slave.Slave;
import slave.SlaveManager;

public class SlaveServer implements Runnable {

	ServerSocket sock;
	ExecutorService es;
	boolean running;
	Socket sockCli;
	SlaveManager clients;

	public SlaveServer() throws IOException {
		this.sock = new ServerSocket(Globals.CLIENT_PORT);
		this.es = Executors.newFixedThreadPool(Globals.SLAVE_NUMBER);
		this.clients = SlaveManager.getInstance();
		this.running = false;
	}

	public void start() {
		try {
			while(true) {
				if(clients.canAddClient()) {
					sockCli = sock.accept();
					Slave c = new Slave(sockCli, es);
					clients.addClient(c);
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Override
	public void run() {
		start();
	}
}


