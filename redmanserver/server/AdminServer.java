package server;

import global.Globals;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import slave.SlaveManager;
import admin.Admin;

public class AdminServer implements Runnable {

	ServerSocket sock;
	ExecutorService es;
	Socket sockCli;

	public AdminServer() throws IOException {
		this.sock = new ServerSocket(Globals.ADMIN_PORT);
		this.es = Executors.newFixedThreadPool(3);
	}

	public void start() {
		try {
			while(true) {
				System.out.println("waiting for admin to connect...");
				sockCli = sock.accept();
				System.out.println("admin connected!");
				Admin a = new Admin(sockCli, es);
				SlaveManager.getInstance().setAdmin(a);
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
