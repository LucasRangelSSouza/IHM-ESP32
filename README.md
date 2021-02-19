
[![N|Solid](https://eventos.ifg.edu.br/semanai2c/wp-content/uploads/sites/7/2016/08/marca-ifg-2015-todas-as-verses.png)](https://www.ifg.edu.br/goiania)

# IHM (Criptografia de mensagens)

O presente projeto é uma interface homem maquina desenvolvido pos discentes do IFG, utilizando um teclado matricial 4x4 e um display de 7 segmentos.

#### Componentes:

  - ESP32 (38 Pinos)
   ![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/ESP32-DEVKIT-V4-pinout-v2.jpg  =250x250)
  
  - Teclado matricial 4x4
  ![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/teclado-membrana-4x4.jpg  =250x250)
  - Display de 7 segmentos (Anodo comum)
  ![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/display7.jpg  =250x250)
  - 1 Resistor de 68 ohms
  ![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/68ohms.png =250x250)
  - 4 Resistores de 1Kohms
  ![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/1kohms.png  =250x250)
  
#### Montagem pratica:

  - Esquma eletrico
  ![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/esquemaEletrico.bmp)
  

#### Configuração do software:

  - Para gravar a firmware no microcontrolador utilizando a Arduino IDE
siga os passos descritos [aqui](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

  - Logo após configurar o ESP32 na arduino IDE clone o presente repositorio(É necessario ter um cliente [git](https://git-scm.com/) instalado ).Para clonar o diretorio execute no terminal ou no prompt:
	```sh
	$ git clone https://github.com/LucasRangelSSouza/criptografiaMsgs.git
	```
  - Apos clonado abra o ProjetoIHM.ino, no menu de placas selecione a placa: "ESP32 Dev-Module".
	![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/selectPlaca.png)
	
  - Faça o upload do codigo para sua placa. Logo apos o upload o projeto já estara funcionando em seu microcontrolador
		OBS: Algumas placas ESP32 necessitam que o botao "boot" na placa, seja mantido pressionado durante o upload do codigo.

#### Funcionamento:

   ![](https://github.com/LucasRangelSSouza/IHM-ESP32/blob/main/assets/test.gif)


### Licença:


MIT
**Free Software, Hell Yeah!**
