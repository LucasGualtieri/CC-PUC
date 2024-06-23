package TP04.src.Algoritmos.Criptografia;

import java.util.List;
import java.util.LinkedList;

public class CipherBuilder {
	
	List<CipherStrategy> strategies = new LinkedList<>();

	public CipherBuilder() {};

	public CipherBuilder append(CipherStrategy strategy) {
		strategies.add(strategy);
		return this;
	}

	public Cipher build() {
		
		CipherStrategy[] strategiesArray = new CipherStrategy[strategies.size()];
		
		for (int i = 0; i < strategies.size(); i++) {
			strategiesArray[i] = strategies.remove(0);
		}

		return new Cipher(strategiesArray);
	}
}
