package global;

import java.io.IOException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import server.AdminServer;
import server.SlaveServer;

public class Main {

	
	public static void main(String[] args) {
		ExecutorService es;
		es = Executors.newFixedThreadPool(3);
		try {
			SlaveServer ss = new SlaveServer();
			es.execute(ss);
			
			AdminServer as = new AdminServer();
			es.execute(as);
		} catch (IOException e) {
			e.printStackTrace();
		}
		

	}

}
