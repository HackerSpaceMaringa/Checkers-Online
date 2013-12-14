#!/bin/bash

install(){
	sleep 2
	wget http://ufpr.dl.sourceforge.net/project/boost/boost/1.54.0/boost_1_54_0.tar.gz
	tar -xf boost_1_54_0.tar.gz
	rm boost_1_54_0.tar.gz
	echo -e "Compilando libboost..."
	sleep 2
	cd ./boost_1_54_0/
	./bootstrap.sh
	./b2
	echo -e "Compilação concluída!"
	sleep 2
	echo -e "Instalando libboost..."
	sudo ./b2 install
	echo -e "\n\nInstalação concluída!"
	cd ../
	rm boost_1_54_0/ -r
        sudo ldconfig
}

uninstall(){
	echo -e "Desinstalando libboost..."
	sudo rm /usr/local/include/boost -r
	sudo rm /usr/local/lib/libboost*
	echo -e "Desinstalado!"
}

$1
