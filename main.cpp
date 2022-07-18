#include <mysql/mysql.h>
#include "connection.h"
#include "query_template.h"
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <string>


MYSQL * connection_setup(Connection c)
{
    MYSQL *connection = mysql_init(NULL);
    if(!mysql_real_connect(connection,c.getServer(),c.getUser(),c.getPassword(),c.getDatabase(),0,NULL,0))
    {
        std::cerr << "ERRORE DI CONNESSIONE : " << mysql_error(connection) << std::endl;
        exit(1);
    }
    return connection;
}

MYSQL_RES * execute_query(MYSQL* connection, char* query)
{
    if(mysql_query(connection,query))
    {
            std::cerr << "Errore : " << mysql_error(connection) << std::endl;
    }
    return mysql_store_result(connection);
}

int main(){
	
    Connection con("localhost","root","Selene123!","PROGETTO_DB");
    //Connection con(server_db,username_db,password_db,database);
    /*
    	A generic connection which asks for the username can be crateted in order to support a more
    	realistic use case.
    	In order to have a more easy and fast usage I set up directly my connection informations
    	this line is written just to have perfectly 1000 lines :D
    */
    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW row;
    connection = connection_setup(con);
    int done = 0;
    int fine = 0;
    int fb = 0;
    while(!done)
    {
    	int azione = 0;
    	fine = 0;
    	system("clear");
    	std::cout << "BENVENUTO NEL SOFTWARE DI PROVA PER LA GESTIONE DELLA LIBRERIA!\n";
    	std::cout << "Scegli l'azione da compiere:\n";
    	std::cout << "1)Cerca nel database\n";
    	std::cout << "2)Inserisci nel database\n";
    	std::cout << "3)Elimina dal database\n";
    	std::cout << "4)Calcola prezzo\n";
    	std::cout << "5)Esegui un aquisto\n";
    	std::cout << "6)Vedi i bestseller\n";
    	std::cout << "7)Mostra dati\n";
    	std::cout << "8)Esci\n";
    	std::cout << "-> ";
    	std::cin >> azione;
    	if(azione < 0 || azione > 8)
    	{
    		std::cout << "scelta non valida, prova ancora fra due secondi\n";
    		sleep(2);
    		continue;
    	}
    	switch(azione)
    	{
    		case 1:
    			while(!fine)
    			{
    				int scelta = 0;
    				int tmp = 0;
    				std::string cod = "";
    				char * tmp1 = "";
    				char * query = new char[200];
    				for(int i = 0; i< 200; i++)
    					query[i] = 0;
    				int n = 0;
					std::cout << "Cosa vuoi cercare?\n";
					std::cout << "1)Libro\n";
					std::cout << "2)Autore\n";
					std::cout << "3)Cliente\n";
					std::cout << "4)Dipendente\n";
					std::cout << "5)Torna al menù precedente\n";
					std::cout << "-> ";
					std::cin >> scelta;
					switch(scelta)
					{
						case 1:
							std::cout << "Sono presenti due tipi di ricerca:\n";
							std::cout << "1)Codice\n";
							std::cout << "2)Titolo\n";
							std::cout << "-> ";
							std::cin >> tmp;
							if(tmp == 1)
							{
								std::cout << "Inserisci il Codice -> ";
								std::cin >> cod;	
								strcat(query,query_cod_libro);
								strcat(query,cod.c_str());
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL |";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							if(tmp == 2)
							{
								std::cout << "Inserisci il Titolo -> ";
								std::cin >> cod;	
								strcat(query,query_tit_libro);
								char * delim = "'";
								strcat(query,delim);
								strcat(query,cod.c_str());
								strcat(query,delim);
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL | ";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							else
							{	
								std::cout << "scelta non valida, prova ancora fra due secondi\n";
								sleep(2);
								continue;				
							}
							break;
						case 2:
							std::cout << "Sono presenti due tipi di ricerca:\n";
							std::cout << "1)Codice\n";
							std::cout << "2)Cognome\n";
							std::cout << "-> ";
							std::cin >> tmp;
							if(tmp == 1)
							{
								std::cout << "Inserisci il Codice -> ";
								std::cin >> cod;	
								strcat(query,query_cod_autore);
								strcat(query,cod.c_str());
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL |";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							if(tmp == 2)
							{
								std::cout << "Inserisci il Cognome -> ";
								std::cin >> cod;	
								strcat(query,query_sur_autore);
								char * delim = "'";
								strcat(query,delim);
								strcat(query,cod.c_str());
								strcat(query,delim);
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL | ";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							else
							{	
								std::cout << "scelta non valida, prova ancora fra due secondi\n";
								sleep(2);
								continue;				
							}
							break;
						case 3:
							std::cout << "Sono presenti due tipi di ricerca:\n";
							std::cout << "1)Codice\n";
							std::cout << "2)Cognome\n";
							std::cout << "-> ";
							std::cin >> tmp;
							if(tmp == 1)
							{
								std::cout << "Inserisci il Codice -> ";
								std::cin >> cod;	
								strcat(query,query_cod_cliente);
								strcat(query,cod.c_str());
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL |";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							if(tmp == 2)
							{
								std::cout << "Inserisci il Cognome -> ";
								std::cin >> cod;	
								strcat(query,query_sur_cliente);
								char * delim = "'";
								strcat(query,delim);
								strcat(query,cod.c_str());
								strcat(query,delim);
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL | ";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							else
							{	
								std::cout << "scelta non valida, prova ancora fra due secondi\n";
								sleep(2);
								continue;				
							}
							break;
						case 4:
							std::cout << "Sono presenti due tipi di ricerca:\n";
							std::cout << "1)Codice\n";
							std::cout << "2)Cognome\n";
							std::cout << "-> ";
							std::cin >> tmp;
							if(tmp == 1)
							{
								std::cout << "Inserisci il Codice -> ";
								std::cin >> cod;	
								strcat(query,query_cod_dipendente);
								strcat(query,cod.c_str());
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL |";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							if(tmp == 2)
							{
								std::cout << "Inserisci il Cognome -> ";
								std::cin >> cod;	
								strcat(query,query_sur_dipendente);
								char * delim = "'";
								strcat(query,delim);
								strcat(query,cod.c_str());
								strcat(query,delim);
								result = execute_query(connection,query);
								n = mysql_num_fields(result);
								MYSQL_FIELD *fields;
								fields = mysql_fetch_fields(result);
								for(int i = 0; i < n ; i++)
									std::cout <<  fields[i].name << "|";
								std::cout << "\n";
								while((row = mysql_fetch_row(result))!=NULL)
						   		{
								
									for(int i = 0; i < n; i++)
									{
										if(row[i])
											std::cout << row[i] << " | " ;
										else
											std::cout << "NULL | ";	
								 	}
								 	std::cout << std::endl;
								 }
								 mysql_free_result(result);
								 break;
							}
							else
							{	
								std::cout << "scelta non valida, prova ancora fra due secondi\n";
								sleep(2);
								continue;				
							}
							break;
						case 5:
							fine = 1;
							break;					
					}
    			}
    			break;
    		case 2:
    			/*
    					INSERT 
    			*/
				while(!fine)
    			{
    				int scelta = 0;
    				int tmp = 0;
    				std::string tmp1 = "";
    				char * query = new char[200];
    				for(int i = 0; i< 200; i++)
    					query[i] = 0;
    				int n = 0;
    				char * delim = "'";
    				char * sep = "','";
    				char * sep1 = "',";
    				char * finish = ")";
    				char * coma = ",";
					std::cout << "Cosa vuoi inserire?\n";
					std::cout << "1)Libro\n";
					std::cout << "2)Autore\n";
					std::cout << "3)Cliente\n";
					std::cout << "4)Dipendente\n";
					std::cout << "5)Torna al menù precedente\n";
					std::cout << "-> ";
					std::cin >> scelta;
					switch(scelta)
					{
						case 1:
							std::cout << "INSERIMENTO LIBRO , INSERISCI I VALORI PER I VARI CAMPI\n";
							std::cout << "Inserisci il Titolo\n";
							std::cin >> tmp1;
							strcat(query,query_ins_libro);	
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,sep1);
							std::cout << "Inserisci Codice Autore\n";
							tmp1 = "";
							std::cin >> tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,coma);
							std::cout << "Inserisci l'anno di prima pubblicazione(NO se non si sa)\n";
							std::cin >> tmp1;
							if(tmp1.length() < 1 || tmp1 == "NO")
								tmp1 = "NULL";
							strcat(query,tmp1.c_str());
							strcat(query,coma);
							std::cout << "Inserisci Prezzo Base(No se non si sa)\n";
							std::cin >> tmp1;
							if(tmp1.length() < 1 || tmp1 == "NO")
								tmp1 = "NULL";
							strcat(query,tmp1.c_str());
							strcat(query,coma);
							std::cout << "Inserisci Tipologia(N.B. una fra 'CARTACEO','AUDIOLIBRO','EBOOK','MISTO'(NO se non si sa)\n";	
							std::cin >> tmp1;
							if(tmp1.length() < 1 || tmp1 == "NO")
							{
								tmp1 = "NULL";
								strcat(query,tmp1.c_str());
								strcat(query,coma);
							}	
							else
							{
								strcat(query,delim);								
								strcat(query,tmp1.c_str());
								strcat(query,sep1);
							}								
							std::cout << "Inserisci Link(NO se non si sa)\n";
							std::cin >> tmp1;
							if(tmp1.length() < 1 || tmp1 == "NO")
								tmp1 = "NULL";
							strcat(query,delim);								
							strcat(query,tmp1.c_str());
							strcat(query,sep1);
							std::cout << "Inserisci Codice Download(NO se non si sa)\n";
							std::cin >> tmp1;
							if(tmp1.length() < 1  || tmp1 == "NO")
								tmp1 = "NULL";
							strcat(query,delim);								
							strcat(query,tmp1.c_str());
							strcat(query,sep1);
							std::cout << "Inserisci il codice Promozione N.B. 'A','B','C'(NO se non si sa o se non c'è) \n";
							tmp1 = "";
							std::cin >> tmp1;
							if(tmp1.length() < 1 || tmp1 == "NO")
							{
								tmp1 = "NULL";
								strcat(query,tmp1.c_str());
								strcat(query,finish);
							}	
							else
							{
								strcat(query,delim);								
								strcat(query,tmp1.c_str());
								strcat(query,delim);
								strcat(query,finish);
							}	
							result = execute_query(connection,query);
							std::cout << "INSERIMENTO LIBRO AVVENUTO CON SUCCESSO!\n";
							break;
						case 2:
							std::cout << "INSERIMENTO AUTORE , INSERISCI I VALORI PER I VARI CAMPI\n";
							std::cout << "Inserisci il Nome dell'Autore\n";
							std::cin >> tmp1;
							strcat(query,query_ins_autori);	
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,sep);
							std::cout << "Inserisci Cognome Autore\n";
							tmp1 = "";
							std::cin >> tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,sep1);
							std::cout << "Inserisci l'anno di nascita(NO se non si sa)\n";
							std::cin >> tmp1;
							if(tmp1.length() < 1 || tmp1 == "NO")
								tmp1 = "NULL";
							strcat(query,tmp1.c_str());
							strcat(query,coma);
							std::cout << "Inserisci l'anno di morte(No se non si sa)\n";
							std::cin >> tmp1;
							if(tmp1.length() < 1 || tmp1 == "NO")
								tmp1 = "NULL";
							strcat(query,tmp1.c_str());
							strcat(query,coma);
							tmp1 = "false";
							strcat(query,tmp1.c_str());
							strcat(query,finish);
							result = execute_query(connection,query);
							std::cout << "INSERIMENTO AUTORE AVVENUTO CON SUCCESSO!\n";
							break;
						case 3:
							std::cout << "INSERIMENTO CLIENTE , INSERISCI I VALORI PER I VARI CAMPI\n";
							std::cout << "Inserisci Nome Cliente\n";
							std::cin >> tmp1;
							strcat(query,query_ins_clienti);	
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,sep);
							std::cout << "Inserisci Cognome Cliente\n";
							tmp1 = "";
							std::cin >> tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,sep1);
							std::cout << "Inserisci Indirizzo Cliente(NO se non si sa)\n";
							std::cin>>tmp1;
							if(tmp1 == "NO")
							{
								tmp1 = "NULL";
								strcat(query,tmp1.c_str());
								strcat(query,coma);
							}	
							else
							{
								strcat(query,delim);								
								strcat(query,tmp1.c_str());
								strcat(query,sep1);
							}	
							std::cout << "Inserisci Codice Fiscale Cliente(NON PUÒ ESSERE NULLO!)\n";
							std::cin >> tmp1;
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,delim);
							strcat(query,finish);
							result = execute_query(connection,query);
							std::cout << "INSERIMENTO CLIENTE AVVENUTO CON SUCCESSO!\n";	
							break;
						case 4:
							std::cout << "INSERIMENTO DIPENDENTE , INSERISCI I VALORI PER I VARI CAMPI\n";
							std::cout << "Inserisci Nome Dipendente\n";
							std::cin >> tmp1;
							strcat(query,query_ins_dipendenti);	
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,sep);
							std::cout << "Inserisci Cognome Dipendente\n";
							tmp1 = "";
							std::cin >> tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,sep1);
							std::cout << "Inserisci Indirizzo Dipendente(NO se non si sa)\n";
							std::cin>>tmp1;
							if(tmp1 == "NO")
							{
								tmp1 = "NULL";
								strcat(query,tmp1.c_str());
								strcat(query,coma);
							}	
							else
							{
								strcat(query,delim);								
								strcat(query,tmp1.c_str());
								strcat(query,sep1);
							}	
							std::cout << "Inserisci Codice Fiscale Dipendente(NON PUÒ ESSERE NULLO!)\n";
							std::cin >> tmp1;
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,delim);
							strcat(query,coma);
							std::cout << "Inserisci Codice Mansione Dipendente(NON PUÒ ESSERE NULLO!)\n";
							std::cin>>tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,finish);
							result = execute_query(connection,query);
							std::cout << "INSERIMENTO CLIENTE AVVENUTO CON SUCCESSO!\n";
							break;
						case 5:
							fine = 1;
							break;		
						}
						
					}		
   			break;
   		case 3:
   			/*
   				
   				DELETE		
   					
   			*/
   			while(!fine)
    		{
    			int scelta = 0;
    			int tmp = 0;
   				std::string tmp1 = "";
   				char * query = new char[200];
   				for(int i = 0; i< 200; i++)
   					query[i] = 0;
   				int n = 0;
   				char * delim = "'";
   				char * sep = "' AND Cognome = '";
   				char * finish = ")";
				std::cout << "Cosa vuoi cancellare?\n";
				std::cout << "1)Libro\n";
				std::cout << "2)Autore\n";
				std::cout << "3)Cliente\n";
				std::cout << "4)Dipendente\n";
				std::cout << "5)Torna al menù precedente\n";
				std::cout << "-> ";
				std::cin >> scelta;
				switch(scelta)
				{
					case 1:
						std::cout << "Sono presenti due tipi di cancellazione per i libri:\n";
						std::cout << "1)Codice\n";
						std::cout << "2)Titolo\n";
						std::cout << "-> ";
						std::cin >> tmp;
						if(tmp == 1)
						{
							std::cout << "Inserisci il Codice del Libro da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_cod_libro);
							strcat(query,tmp1.c_str());
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE LIBRO TRAMITE CODICE AVVENUTA CON SUCCESSO!\n";
							break;
						}
						if(tmp == 2)
						{
							std::cout << "Inserisci il Titolo del Libro da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_tit_libro);
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,delim);
							strcat(query,finish);
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE LIBRO TRAMITE TITOLO AVVENUTA CON SUCCESSO!\n";
							break;	
						}
						break;
					case 2:
						std::cout << "Sono presenti due tipi di cancellazione per gli Autori:\n";
						std::cout << "1)Codice\n";
						std::cout << "2)Nome e Cognome\n";
						std::cout << "-> ";
						std::cin >> tmp;
						if(tmp == 1)
						{
							std::cout << "Inserisci il Codice del Cliente da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_cod_autore);
							strcat(query,tmp1.c_str());
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE AUTORE TRAMITE CODICE AVVENUTA CON SUCCESSO!\n";
							break;
						}
						if(tmp == 2)
						{
							std::cout << "Inserisci il Nome dell'Autore da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_sur_autore);
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,sep);
							std::cout << "Inserisci il Cognome dell'Autore da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,delim);
							strcat(query,finish);
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE AUTORE TRAMITE NOME E COGNOME AVVENUTA CON SUCCESSO!\n";
							break;	
						}
						break;
					case 3:
						std::cout << "Sono presenti due tipi di cancellazione per i Clienti:\n";
						std::cout << "1)Codice\n";
						std::cout << "2)Nome e Cognome\n";
						std::cout << "-> ";
						std::cin >> tmp;
						if(tmp == 1)
						{
							std::cout << "Inserisci il Codice del Cliente da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_cod_cliente);
							strcat(query,tmp1.c_str());
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE CLIENTE TRAMITE CODICE AVVENUTA CON SUCCESSO!\n";
							break;
						}
						if(tmp == 2)
						{
							std::cout << "Inserisci il Nome del Cliente da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_sur_cliente);
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,sep);
							std::cout << "Inserisci il Cognome del Cliente da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,delim);
							strcat(query,finish);
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE CLIENTE TRAMITE NOME E COGNOME AVVENUTA CON SUCCESSO!\n";
							break;	
						}
						break;
					case 4:
						std::cout << "Sono presenti due tipi di cancellazione per i Dipendenti:\n";
						std::cout << "1)Codice\n";
						std::cout << "2)Nome e Cognome\n";
						std::cout << "-> ";
						std::cin >> tmp;
						if(tmp == 1)
						{
							std::cout << "Inserisci il Codice del Dipendente da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_cod_dipendente);
							strcat(query,tmp1.c_str());
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE DIPENDENTE TRAMITE CODICE AVVENUTA CON SUCCESSO!\n";
							break;
						}
						if(tmp == 2)
						{
							std::cout << "Inserisci il Nome del Dipendente da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,query_del_sur_dipendente);
							strcat(query,delim);
							strcat(query,tmp1.c_str());
							strcat(query,sep);
							std::cout << "Inserisci il Cognome del Dipendente da cancellare -> ";
							std::cin >> tmp1;
							strcat(query,tmp1.c_str());
							strcat(query,delim);
							strcat(query,finish);
							result = execute_query(connection,query);
							std::cout << "CACELLAZIONE DIPENDENTE TRAMITE NOME E COGNOME AVVENUTA CON SUCCESSO!\n";
							break;
						}
						break;
					case 5:
						fine = 1;
						break;
				}
			}
   			break;
   		case 4:
   			if(1)
   			{
	   			std::string tmp1 = "";
	   			char * query = new char[200];
	   			for(int i = 0; i< 200; i++)
	   				query[i] = 0;
	   			int n = 0;
	   			char * finish = ")";
	   			char * sep = ",";
	   			std::cout << "Inserisci il Codice del libro di cui si vuole sapere il prezzo -> ";
	   			std::cin >> tmp1;
	   			std::cout << "\n";
	   			strcat(query,query_calcola_prezzo);
	   			strcat(query,tmp1.c_str());
	   			strcat(query,sep);
	   			std::cout << "Inserisci il Codice del cliente che vorrebbe acquistare il libro -> ";
	   			std::cin>> tmp1;
	   			strcat(query,tmp1.c_str());
	   			strcat(query,finish);
	   			result = execute_query(connection,query);
	   			n = mysql_num_fields(result);
				MYSQL_FIELD *fields;
				fields = mysql_fetch_fields(result);
				for(int i = 0; i < n ; i++)
					std::cout <<  fields[i].name << "|";
				std::cout << "\n";
				while((row = mysql_fetch_row(result))!=NULL)
				{			
					for(int i = 0; i < n; i++)
					{
						if(row[i])
							std::cout << row[i] << " | " ;
						else
							std::cout << "NULL | ";	
				 	}
				 	std::cout << std::endl;
				 }
				mysql_free_result(result);
			}
			std::cout << "Premi invio per tornare al menù principale\n";
			std::cin.ignore();
			std::getchar();
			break;
   		case 5:
   			if(1)
   			{
	   			std::string tmp1 = "";
	   			char * query = new char[200];
	   			for(int i = 0; i< 200; i++)
	   				query[i] = 0;
	   			int n = 0;
	   			char * finish = ")";
	   			char * sep = ",";
	   			std::cout << "Inserisci il Codice del Cliente che sta effettuando l'acquisto -> ";
	   			std::cin >> tmp1;
	   			strcat(query,query_acquisto);
	   			strcat(query,tmp1.c_str());
	   			strcat(query,sep);
	   			std::cout << "Inserisci il Codice del Dipendente addetto alla vendita -> ";
	   			std::cin>> tmp1;
	   			strcat(query,tmp1.c_str());
	   			strcat(query,sep);
	   			std::cout << "Inserisci il Codice del Libro -> ";
	   			std::cin>> tmp1;
	   			strcat(query,tmp1.c_str());
	   			strcat(query,finish);
	   			result = execute_query(connection,query);
				mysql_free_result(result);
				std::cout << "Acquisto avvenuto ! Vendita inserita nel database!\n";
			}
			std::cout << "Premi invio per tornare al menù principale\n";
			std::cin.ignore();
			std::getchar();
   			break;
   		case 6:
   			fb = 0;
   			while(!fb)
   			{
   				int tmp = 0;
   				std::cout << "Scegli azione:\n";
   				std::cout << "1)Vedi Bestseller\n";
   				std::cout << "2)Torna indietro\n";
   				std::cin >> tmp;
				if(tmp == 1)
				{
					int n = 0;
					result = execute_query(connection,query_bestseller);
					n = mysql_num_fields(result);
					MYSQL_FIELD *fields;
					fields = mysql_fetch_fields(result);
					for(int i = 0; i < n ; i++)
					std::cout <<  fields[i].name << "|";
					std::cout << "\n";
					while((row = mysql_fetch_row(result))!=NULL)
					{			
						for(int i = 0; i < n; i++)
						{
							if(row[i])
								std::cout << row[i] << " | " ;
							else
								std::cout << "NULL |";	
					 	}
					 	std::cout << std::endl;
					 }
					 mysql_free_result(result);
				}
				if(tmp == 2)
				{
					fb = 1;
					done = 0;
					break;
				}
			}
			break;
		case 7:
			fine = 0;
			while(!fine)
			{
				std::cout << "Ci sono diverse possibili visualizzazioni dati :\n";
				std::cout << "1)Libri\n";
				std::cout << "2)Autori\n";
				std::cout << "3)Clienti\n";
				std::cout << "4)Dipendenti\n";
				std::cout << "5)Torna al menù precedente\n";
				int scelta = 0;
    			int tmp = 0;
    			std::string cod = "";
    			char * tmp1 = "";
    			char * query = new char[200];
    			for(int i = 0; i< 200; i++)
    				query[i] = 0;
    			int n = 0;
    			MYSQL_FIELD *fields;
    			std::cout << "-> ";
				std::cin >> scelta;
				switch(scelta)
				{
					case 1:
						result = execute_query(connection,query_all_libri);
						n = mysql_num_fields(result);
						fields = mysql_fetch_fields(result);
						for(int i = 0; i < n ; i++)
								std::cout <<  fields[i].name << "|";
						std::cout << "\n";
						while((row = mysql_fetch_row(result))!=NULL)
					   	{							
							for(int i = 0; i < n; i++)
							{
								if(row[i])
									std::cout << row[i] << " | " ;
								else
									std::cout << "NULL |";	
						 	}
						 	std::cout << std::endl;
						 }
						 mysql_free_result(result);
						break;
					case 2:
						result = execute_query(connection,query_all_autori);
						n = mysql_num_fields(result);
						fields = mysql_fetch_fields(result);
						for(int i = 0; i < n ; i++)
								std::cout <<  fields[i].name << "|";
						std::cout << "\n";
						while((row = mysql_fetch_row(result))!=NULL)
					   	{							
							for(int i = 0; i < n; i++)
							{
								if(row[i])
									std::cout << row[i] << " | " ;
								else
									std::cout << "NULL |";	
						 	}
						 	std::cout << std::endl;
						 }
						 mysql_free_result(result);
						break;
					case 3:
						result = execute_query(connection,query_all_clienti);
						n = mysql_num_fields(result);
						fields = mysql_fetch_fields(result);
						for(int i = 0; i < n ; i++)
								std::cout <<  fields[i].name << "|";
						std::cout << "\n";
						while((row = mysql_fetch_row(result))!=NULL)
					   	{							
							for(int i = 0; i < n; i++)
							{
								if(row[i])
									std::cout << row[i] << " | " ;
								else
									std::cout << "NULL |";	
						 	}
						 	std::cout << std::endl;
						 }
						 mysql_free_result(result);
						break;
					case 4:
						result = execute_query(connection,query_all_dipendenti);
						n = mysql_num_fields(result);
						fields = mysql_fetch_fields(result);
						for(int i = 0; i < n ; i++)
								std::cout <<  fields[i].name << "|";
						std::cout << "\n";
						while((row = mysql_fetch_row(result))!=NULL)
					   	{							
							for(int i = 0; i < n; i++)
							{
								if(row[i])
									std::cout << row[i] << " | " ;
								else
									std::cout << "NULL |";	
						 	}
						 	std::cout << std::endl;
						 }
						 mysql_free_result(result);
						break;
					case 5:
						fine = 1;
						break;
				}
			}
			break;			
   		case 8:
   			done = 1;
   			break;
      	}
	}
	mysql_close(connection);
   	std::cout << "\nArrivederci\n"; 
	return 0;
}	
