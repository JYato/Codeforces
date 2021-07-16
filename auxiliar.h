#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>



using namespace std;

string size_to_string(int n, int tam){
	string size = to_string(n);
	if(size.length() < tam){
		size = string(tam - size.length(), '0') + size;
    }

    return size;
}

vector<string> split_into_words(string Mensaje){
    vector<string> res;
    int ianterior = 0;
    for(int i = 0; i < Mensaje.length(); i++){
        i = Mensaje.find(" ", i);
        if(i != -1)
        {
            res.push_back(Mensaje.substr(ianterior, i - ianterior));
            ianterior = i+1;
        }
        else
        {
            res.push_back(Mensaje.substr(ianterior));
            i = Mensaje.length();
        }
    }

    return res;
}

struct Paquete{
	bool is_last;
	int nroflujo;
	int nrosec_flujo;
	int tam_data;
	string data;
	int hash;
	Paquete(int nroflujo_,int nrosec_flujo_,string data_,bool last_):nroflujo(nroflujo_),nrosec_flujo(nrosec_flujo_),data(data_),is_last(last_){
		tam_data = data.size();
	}
	void funcion_hash(){}
	int calculateChecksum();
    int getChecksum();
};

struct Flujo{
	int sec_final;
	int nroflujo;
	vector<pair<int,Paquete*> lista_paquetes;
	FLujo(int sec_final_, int nro_flujo_):sec_final(sec_final_),nroflujo(nroflujo_){}

	void insert_paquete(Paquete* paquete_){
		//int myints[] = {10,20,30,30,20,10,10,20};   // 8 elements
		//int mycount = std::count (myints, myints+8, 10);
		//std::cout << "10 appears " << mycount << " times.\n";
		if(count(lista_paquetes.begin(),lista_paquetes.end(),paquete_->nrosec_flujo)){
			return;
		}
		else{
			if(paquet->is_last){
				sec_final = paquete->nrosec_flujo;
			}
			lista_paquetes.insert(lista_paquetes.begin()+paquete->nrosec_flujo,make_pair(paquete->nrosec_flujo,paquete));
		}
	}

	string get_data_t(){
		string data_total = "";
		//for(int i = 0; i < lista_paquetes.size(); i++){
		for(int i = 0; i < sec_final; i++){
			data_total += lista_paquetes[i].second->data;
		}
	}
};

struct FLUJOS_RDT{

};

#endif
