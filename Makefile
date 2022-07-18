main:
	g++ main.cpp -o main -L/usr/include/mysql/mysql -lmysqlclient
mysql_install:
	chmod +x mysql_install
	./mysql_install
install:
	sudo apt-get install libmysqlclient-dev
clean:
	rm main			
run:
	./main
